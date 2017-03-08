#include <stdio.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multimin.h>

int rosenbrock(double x, double y) {
	f = (1 - x) * (1 -x) + 100 * pow((y - (x * x)), 2);
	return f;
}

int main() {
	int status;
	size_t iter = 0;
	size_t dim = 2;
	gsl_multimin_function F;
	F.f = rosenbrock;
	F.n = dim;

	gsl_multimin_fminimizer *res = gsl_multimin_fminimizer_alloc(gsl_multimin_fminimizer_nmsimplex2, dim);
	gsl_vector *start = gsl_vector_alloc(dim);
	gsl_vector *step = gsl_vector_alloc(dim);

	gsl_vector_set(start, 0, 2);
	gsl_vector_set(start, 1, 2);
	gsl_vector_set_all(step, 0.05);

	gsl_multimin_fminimizer_set(res, &F, start, step);

	do {
		iter++;
		status = gsl_multimin_fminimizer_iterate(res);

		if (status)
			break;

		if (status == GSL_SUCCES)
			printf("Minimum found: \n");
		printf("%5d %.5f %.5f %10.5f\n", iter,
				gsl_vector_get(res->start, 0), gsl_vector_get(res->start, 1),
				res->f);
	} 
	while (status == GSL_CONTINUE && iter < 100);

	gsl_vector_free(start);
	gsl_vector_free(step);
	gsl_multimin_fminimizer_free(res);

	return 0;
}
