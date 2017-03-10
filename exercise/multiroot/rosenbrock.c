#include <stdio.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>

int rosenbrock(const gsl_vector *v, gsl_vector *f) {
	double x = gsl_vector_get(v, 0);
	double y = gsl_vector_get(v, 1);

	gsl_vector_set(f, 0, -2 * (1 - x) - 400 * (y - x * x) * x);
	gsl_vector_set(f, 1, 200 * (y - x * x));
	return GSL_SUCCESS;
}

int main() {
	int status, flag;
	int iter = 0, iter_max = 1000;
	const double dim = 2, eps = 1e-7;
	gsl_vector *x;
	const gsl_multiroot_fsolver_type *T =  gsl_multiroot_fsolver_hybrids;

	// Initialise method
	gsl_multiroot_function f = {&rosenbrock, dim};

	x = gsl_vector_alloc(dim);
	gsl_vector_set(x, 0, 2);
	gsl_vector_set(x, 1, 2);

	gsl_multiroot_fsolver *s = gsl_multiroot_fsolver_alloc(T, dim);
	gsl_multiroot_fsolver_set(s, &f, x);

	do {
		iter++;
		flag = gsl_multiroot_fsolver_iterate(s);

		if (flag != 0)
			break;

		status = gsl_multiroot_test_residual(s->f, eps);
	} 
	while (status == GSL_CONTINUE && iter < iter_max);

	printf("i = %d, x = %.3f %.3f, f(x) = %.3f %.3f", iter,
			gsl_vector_get(s->x, 0), gsl_vector_get(s->x, 1),
			gsl_vector_get(s->f, 0), gsl_vector_get(s->f, 1));
	gsl_vector_free(x);
	gsl_multiroot_fsolver_free(s);

	return status;
}
