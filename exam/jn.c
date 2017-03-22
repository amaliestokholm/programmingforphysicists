#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

struct bessel_params {int n; double x};

double bessel(double t, void * params) {
	struct bessel_params * p = (struct bessel_params *)params;
	int n = p->n;
	double x = p->x;
	double f = cos(n * t - x * sin(t));
	return f;
}

int main(void) {
	double epsabs = 1e-6, epsrel = 1e-6;
	double m = 1000, t_start = 0, t_max = M_PI, delta_t=0.1;
	double result, error;
	int n = 1; double x = 0.5;
	printf("x\tJn(x)\n");
	for (double t = t_start; t < t_max; t += delta_t) {
		gsl_integration_workspace * w = gsl_integration_workspace_alloc(m);
		struct bessel_params p = {n, x};

		gsl_function F;
		F.function = &bessel;
		F.params = &p;
		
		gsl_integration_qagi(&F, epsabs, epsrel, m, w, &result, &error);

		printf("%g\t%g\n", x, result); 
		gsl_integration_workspace_free(w);
	}
	return 0;
}
