#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_eigen.h>
const double pi = 3.14159265358979323844;
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

	fprintf(stderr, "b is: \n");
	gsl_vector_fprintf(stderr, b, "%f");
	fprintf(stderr, "A is: \n");
	gsl_matrix_fprintf(stderr, A, "%f");

	// Solve the linear system
	x = gsl_vector_alloc(3);
	p = gsl_permutation_alloc(3);

	int m;
	gsl_linalg_LU_decomp(A, p, &m);
	gsl_linalg_LU_solve(A, p, b, x);

	fprintf(stderr, "x is then found to be:\n");
	gsl_vector_fprintf(stderr, x, "%f");


	// Free memory
	gsl_vector_free(b);
	gsl_matrix_free(A);
	gsl_vector_free(x);
	gsl_permutation_free(p);


	// part b
	// Declare pointer variables
	int n = 20;
	double start = 0, end = 30;
	double step = (end - start) / (n + 1);
	gsl_matrix *H = gsl_matrix_calloc(n, n);
	
	// Build the Hamiltonian
	for(int i=0; i < n-1; i++) {
		gsl_matrix_set(H, i, i, -2);
		gsl_matrix_set(H, i, i+1, 1);
		gsl_matrix_set(H, i+1, i, 1);
	}
	gsl_matrix_set(H, n-1, n-1, -2);
	double s = 1.0 / (n+1);
	gsl_matrix_scale(H, -1/s/s);

	gsl_vector *xvec = gsl_vector_alloc(n);
	for (int i = 0; i < n; i++)
		gsl_vector_set(xvec, i, start + (i + 1) * step);
	
	// Add potential


	// Diagonalize
	gsl_eigen_symmv_workspace *w =  gsl_eigen_symmv_alloc(n);
	gsl_vector *eval = gsl_vector_alloc(n);
	gsl_matrix *evec = gsl_matrix_calloc(n, n);
	gsl_eigen_symmv(H, eval, evec, w);
	gsl_eigen_symmv_sort(eval, evec, GSL_EIGEN_SORT_VAL_ASC);

	// Print the first eigenvalues
	fprintf(stderr, "i   exact   calculated\n");
	for (int k = 0; k < n/3; k++){
		double exact = pi * pi * (k + 1) * (k + 1);
		double calculated = gsl_vector_get(eval, k);
		fprintf(stderr, "%i %g %g\n", k, exact, calculated);
	}
	// Print
	printf("x u0 u1 u2\n");
	printf("%f %f %f %f\n", start, 0., 0., 0.);
	for (int i = 0; i < n; i++) {
		double x = gsl_vector_get(xvec, i);
		double u0 = gsl_matrix_get(evec, i, 0);
		double u1 = gsl_matrix_get(evec, i, 1);
		double u2 = gsl_matrix_get(evec, i, 2);
		printf("%f %f %f %f\n", x, u0, u1, u2);
	}
	printf("%f %f %f %f\n", end, 0., 0., 0.);

	// Free memory
	gsl_matrix_free(H);
	gsl_vector_free(eval);
	gsl_matrix_free(evec);
	gsl_vector_free(xvec);

	return 0;
}
