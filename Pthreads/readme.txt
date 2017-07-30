Task: Parallel Gaussian Elimination using Pthreads

The system has to be connected to the kraken server for executing these programs.

For 1 CPU:

Compile the code in gauss1.c file with the following command:
 gcc -pthread -o gs gauss1.c

./gs:-
<./gs>: Executes the file gs, which is the output file.

The execution time can be found and noted using the following command:
/usr/bin/time ./gs

For 8 CPU’s: 
Compile the code in gauss2.c file with the following command:
 gcc -pthread -o gs gauss2.c

./gs:-
<./gs>: Executes the file gs, which is the output file.

The execution time can be found and noted using the following command:
/usr/bin/time ./gs
