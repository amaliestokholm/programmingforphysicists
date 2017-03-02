#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_eigen.h>

int main() {
	// part a
	// Declare pointer variables for Ax=b
	gsl_vector *b, *x;
	gsl_matrix *A;
	gsl_permutation *p;

	// Create A and b
	b = gsl_vector_alloc(3);
	A = gsl_matrix_alloc(3, 3);

	gsl_vector_set(b, 0, 6.23);
	gsl_vector_set(b, 1, 5.37);
	gsl_vector_set(b, 2, 2.29);

	gsl_matrix_set(A, 0, 0, 6.13);
	gsl_matrix_set(A, 1, 0, 8.08);
	gsl_matrix_set(A, 2, 0, -4.36);
	gsl_matrix_set(A, 0, 1, -2.90);
	gsl_matrix_set(A, 1, 1, -6.31);
	gsl_matrix_set(A, 2, 1, 1.00);
	gsl_matrix_set(A, 0, 2, 5.86);
	gsl_matrix_set(A, 1, 2, -3.89);
	gsl_matrix_set(A, 2, 2, 0.19);

	printf("b is: \n");
	gsl_vector_fprintf(stdout, b, "%f");
	printf("A is: \n");
	gsl_matrix_fprintf(stdout, A, "%f");

	// Solve the linear system
	x = gsl_vector_alloc(3);
	p = gsl_permutation_alloc(3);

	int s;
	gsl_linalg_LU_decomp(A, p, &s);
	gsl_linalg_LU_solve(A, p, b, x);

	printf("x is then found to be:\n");
	gsl_vector_fprintf(stdout, x, "%f");


	// Free memory
	gsl_vector_free(b);
	gsl_matrix_free(A);
	gsl_vector_free(x);
	gsl_permutation_free(p);


	// part b
	// Declare pointer variables
	int n = 20;
	gsl_matrix *H = gsl_matrix_calloc(n, n);
	

	// Build the Hamiltonian
	for(int i=0; i < n-1; i++) {
		gsl_matrix_set(H, i, i, -2);
		gsl_matrix_set(H, i, i+1, 1);
		gls_matrix_set(H, i+1, i, 1);
	}
	gsl_matrix(set, n-1, n-1, -2);
	double s=1.0/(n+1);
	gsl_matrix_scale(H, -1/s/s);

	return 0;
}



