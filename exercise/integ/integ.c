#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double trialhamiltoniantrial(double x, void * params) {
	double alpha = *(double *) params;
	double f = ((- alpha * alpha * x * x)/2 + alpha/2 + (x * x)/2) * exp(- alpha * x * x);
	return f;
}

double trialtrial(double x, void * params) {
	double alpha = *(double *) params;
	double f = exp( - alpha * x * x);
	return f;
}

int main(void) {
	double start = 0, end = 1;
	double epsabs = 1e-6, epsrel = 1e-6;
	double n = 1000;
	double psiHpsi, pHperror;
	double psipsi, pperror;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(n);

	gsl_function F;
	F.function = &func;

	gsl_integration_qagi(&F, start, end, epsabs, epsrel, n, w, &psiHpsi, &pHperror); 
	gsl_integration_qagi(&F, start, end, epsabs, epsrel, n, w, &psipsi, &pperror);

	printf("Result = %.12f\n", result);
	printf("Estimated error = %.12f\n", error);

	gsl_integration_workspace_free(w);
}
