#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include <assert.h>
#include <gsl/gsl_odeiv2.h>
#define step gsl_odeiv2_step_rkf45 // Runge-Kutta-Fehlberg method
#define start 1e-3
#define abseps 1e-6
#define eps 1e-6

int ode_h(double r, const double y[], double yp[], void* params) {
	double e = *(double*)params;
	yp[0] = y[1];
	yp[1] = 2 * (-1 / r - e) * y[0];
	return GSL_SUCCESS;
}

double feps(double e, double r) {
	const double rmin = eps;
	if (r < rmin) return r - (r * r);
	assert(r >= 0);

	gsl_odeiv2_system sys;
	sys.function = ode_h;
	sys.jacobian = NULL;
	sys.dimension = 2;
	sys.params = (void*)&e;

	gsl_odeiv2_driver* driv = gsl_odeiv2_driver_alloc_y_new(&sys, step, start, abseps, eps);

	double t = rmin;
	double y[] = {t - (t * t), 1 - (2 * t)};
	int flag = gsl_odeiv2_driver_apply(driv, &t, r, y);
	if (flag != GSL_SUCCESS) {
		fprintf(stderr, "odeiv2 error %d\n", flag);
	}

	gsl_odeiv2_driver_free(driv);
	return y[0];
}

int hydrogen(const gsl_vector* x, void* params, gsl_vector* f) {
	double ex = gsl_vector_get(x, 0);
	assert(ex < 0);
	double rmax = *(double*)params;
	double fval = feps(ex, rmax);

	gsl_vector_set(f, 0, fval);
	return GSL_SUCCESS;
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

	double e = gsl_vector_get(s->x, 0);
	printf("# rmax,\te\n");
	printf("%g\t%g\n",rmax, e);
	printf("\n\n");

	printf("# r, Feps(e,r), exact\n");
	for(double r = 0; r <= rmax; r += rmax/points) {
		printf("%g %g %g\n", r, feps(e, r), r * exp(-r) * feps(e, 1) * exp(1));
	}

	gsl_vector_free(x);
	gsl_multiroot_fsolver_free(s);

	return status;
}
