#include <stdio.h>
#include <math.h>
#include <gsl/gsl_odeiv2.h>

int logistic_function() {
	dydt[0] = y[1];
	dydt[1] = y[0] * (1 - y[0]);
	// An ODE system should return GSL_SUCCES if the calculation was completed succesfully.
	return GSL_SUCCESS;
}

double my_function(double x) {
	gsl_odeiv2_system sys;
	sys.function = logistic_function;
	sys.jacobian = NULL;
	sys.dimenstion = 2;
	sys.params = NULL;
	
	double epsabs = 1e-6, epsrel = 1e-6;
	double hstart = copysign(0.1, x); // hstart determines the initial step size and copysign(a,b) is magnitude of a and sign of b.
	gsl_odeiv2_driver *driver = gsl_odeiv2_driver_alloc_y_new(&sys, gsl_odeiv2_step_rkf45,
		       	hstart, epsabs, epsrel);

	double t=0, y[2] = {0,1};
	gsl_odeiv2_driver_apply(driver, &t, x, y);

	gsl_odeiv2_driver_free(driver);
	return y[0];
}

double math_function(double x) {
	return 1 / (1 + exp(x));

int main() {
	double start=0, end=3, dx = 0.5;
	for (double x=start, x < end + dx; x += dx) {
		printf("%g %g %g\n", x, my_function(x), math_function(x));
	}
}
