#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include <assert.h>



int hydrogen(const gsl_vector* x, void* params, gsl_vector* f) {
	double ex = gsl_vector_get(x, 0);
	assert(ex < 0);
	double rmax = *(double*)params;
	double fval = feps(ex, rmax);

	gsl_vector_set(f, 0, fval);
	return GSL_SUCCES;
}


int main(int argc, char** argv) {
	int status, flag;
	int iter = 0, iter_max = 1000;
	int dim = 1, points = 64;
	const gsl_multiroot_fsolver_type* T = gsl_multiroot_fsolver_broyden;
	gsl_vector* x;


	double rmax = argc > 1? atof(argv[1]):10;
	fprintf(stderr, "r_max = %g\n", rmax);

	gsl_multiroot_fsolver* s = gsl_multiroot_fsolver_alloc(T, dim);
	gsl_multiroot_function F = {.f=hydrogen, .n=dim, .params=(void*)&rmax};

	x = gsl_vector_alloc(dim);
	gsl_vector_set(x, 0, -1);

	gsl_multiroot_fsolver_set(s, &F, x);

	do{
		iter++;
		flag = gsl_multiroot_fsolver_iterate(s);

		if (flag != 0)
			break;

		status = gsl_multiroot_test_residual(s->f, eps);
	}
	while(status == GSL_CONTINUE && iter < iter_max);

	 double e=gsl_vector_get(solver->x,0);
	printf("# rmax, e\n");
	printf("%g %g\n",rmax,e);
	printf("\n\n");

	printf("# r, Feps(e,r), exact\n");
	for(double r = 0; r <= rmax; r += rmax/points) {
		printf("%g %g %g\n", r, feps(e, r), r * exp(-r) * feps(e, 1) * exp(1));
	}

	gsl_vector_free(x);
	gsl_multiroot_fsolver_free(s);

	return status;
}
