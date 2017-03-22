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

int double_equal(double a, double b){
	double TAU = 1e-6, EPS = 1e-6;
	if (fabs(a - b) < TAU)
		return 1;
	if (fabs(a - b) / (fabs(a) + fabs(b)) < EPS / 2)
		return 1;
	return 0;
}

int main() {
	double epsabs = 1e-6, epsrel = 1e-6;
	double m = 1000, start = 0, end = M_PI;
	double result, error;
	int key = 3;
	int n = 0; double x = 0.5;


	gsl_integration_workspace * w = gsl_integration_workspace_alloc(m);
	struct bessel_params p = {n, x};

	gsl_function F;
	F.function = &bessel;
	F.params = &p;
		
	gsl_integration_qag(&F, start, end, epsabs, epsrel, m, key, w, &result, &error);

	result *= 1 / M_PI;
	printf("# x, Jn(x)\n");
	printf("%g\t%g\n", x, result); 
	printf("\n\n");

	printf("# x, Jn(x)\n");
	printf("%g\t%g\n", x, j0(x)); 
	printf("\n\n");

	fprintf(stderr, "Testing bessel function\n");
	if (double_equal(result, j0(x)))
		fprintf(stderr, "Test passed with Jn=%g and Jn=%g\n", result, j0(x));
	else 
		fprintf(stderr, "Test failed with Jn=%g and Jn=.%g\n", result, j0(x));

	gsl_integration_workspace_free(w);
	return 0;
}

	

	
