#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gls/gls_matrix.h>
#include <gls/gls_eigen.h>

int main() {
	// Declare pointer variables for Ax=b
	gsl_vector *b;
	gsl_matrix *A;

	// Create A and b
	b = gsl_vector_alloc(3);
	A = gsl_matrix_alloc(3, 3);

	gsl_vector_set(b, 0, 6.23);
	gsl_vector_set(b, 1, 5.37);
	gsl_vector_set(b, 2, 2.29);

	gls_matrix_set(A, 0, 0, 6.13);
	gls_matrix_set(A, 1, 0, 8.08);
	gls_matrix_set(A, 2, 0, -4.36);
	gls_matrix_set(A, 0, 1, -2.90);
	gls_matrix_set(A, 1, 1, -6.31);
	gls_matrix_set(A, 2, 1, 1.00);
	gls_matrix_set(A, 0, 2, 5.86);
	gls_matrix_set(A, 1, 2, -3.89);
	gls_matrix_set(A, 2, 2, 0.19);

	printf("b is: \n");
	gls_vector_fprintf(stdout, b, "%f");
	printf("A is: \n");
	gls_matrix_fprintf(stdout, A, "%f");









	// Free memory
	gls_vector_free(b);
	gls_matrix_free(A);

	return 0;
}



