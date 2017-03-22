#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
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

int main(int argc, char* argv[]) {
	assert(argc == 5);
	int n = atoi(argv[1]);
	double x_start = atof(argv[2]);
	double x_end = atof(argv[3]);
	double x_delta = atof(argv[4]);
	double epsabs = 1e-6, epsrel = 1e-6;
	double m = 1000, start = 0, end = M_PI;
	double result, error;
	int key = 3;

	printf("# x, Jn(x)\n");
	for (double x = x_start; x < x_end; x += x_delta) {
		gsl_integration_workspace * w = gsl_integration_workspace_alloc(m);
		struct bessel_params p = {n, x};

		gsl_function F;
		F.function = &bessel;
		F.params = &p;

		gsl_integration_qag(&F, start, end, epsabs, epsrel, m, key, w, &result, &error);

		result *= 1 / M_PI;
		printf("%g\t%g\n", x, result); 

		fprintf(stderr, "Testing bessel function\n");
		if (double_equal(result, jn(n, x)))
			fprintf(stderr, "Test passed with Jn=%g and Jn=%g\n", result, jn(n, x));
		else 
			fprintf(stderr, "Test failed with Jn=%g and Jn=%g\n", result, jn(n, x));
		
		gsl_integration_workspace_free(w);
	}
	printf("\n\n");

	printf("# x, Jn(x)\n");
	for (double x = x_start; x < x_end; x += x_delta) {
		printf("%g\t%g\n", x, jn(n, x)); 
	}
	printf("\n\n");
	return 0;
}

	

	
