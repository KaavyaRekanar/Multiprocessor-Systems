
Matrix Multiplication:

Compile with : mpicc -std=c99 matrix.c -o matrix -lm
Run with: mpirun -n C ./matrix
where C is the number of processors= 1,2,4 or 8.

Laplace Approximation:

Compile with : mpicc -std=c99 lapapp.c -o lapapp -lm
Run with: mpirun -n C ./lapapp
where C is the number of processors= 1,2,4 or 8.
