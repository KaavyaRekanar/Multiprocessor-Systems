/*****************************************************
 *
 * Quicksort implementation 
 *
 * Parallel version (OpenMP)
 * Author: Kaavya Rekanar, Siva Venkata Prasad Patta
 * qsort_par.c
 *
 *****************************************************/
 
#include<stdio.h>
#include<omp.h>
#include<stdio.h>
#include<time.h>

int a[67108864];
void qsort(int l,int r){
	if(r>l){
		int pivot=a[r],tmp;
		int low=l-1,high;
		for(high=l;high<=r;high++){
			if(a[high]<=pivot){
				low++;
				 tmp=a[low];
				a[low]=a[high];
				a[high]=tmp;
			}
		}
		qsort(l,low-1);
		qsort(low+1,r);
	}
}
void qsort_parallel(int l,int r){
	if(r>l){

		int pivot=a[r],tmp;
		int low=l-1,high;
		for(high=l;high<=r;high++){
			if(a[high]<=pivot){
				low++;
				tmp=a[low];
				a[low]=a[high];
				a[high]=tmp;
			}
		}
		if((r-l)<1000){
			qsort(l,low-1);
			qsort(low+1,r);
		}
		else{
			#pragma omp task               /* explicit task executed by the thread*/
			qsort_parallel(l,low-1);
			#pragma omp task               /* explicit task executed by the thread*/
			qsort_parallel(low+1,r);
			#pragma omp taskwait           /* waits for the completion of child task*/
		}
	}
}
int main()
{
	int n,i;

	n=67108864; //increased the value of n
	
      for( i=0;i<n;i++)
		a[i]=rand();

      #pragma omp parallel	
	#pragma omp single
	qsort_parallel(0,n-1);
	return 0;
}
