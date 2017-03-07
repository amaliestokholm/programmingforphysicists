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
	double epsabs = 1e-6, epsrel = 1e-6;
	double n = 1000, alpha = 1.0;
	double psiHpsi, pHperror;
	double psipsi, pperror;
	gsl_integration_workspace * w = gsl_integration_workspace_alloc(n);
	gsl_integration_workspace * q = gsl_integration_workspace_alloc(n);

	gsl_function F;
	F.function = &trialhamiltoniantrial;
	F.params = &alpha;
	gsl_integration_qagi(&F, epsabs, epsrel, n, w, &psiHpsi, &pHperror);

	gsl_function G;
	G.function = &trialtrial;
	G.params = &alpha;
	gsl_integration_qagi(&G, epsabs, epsrel, n, q, &psipsi, &pperror);

	gsl_integration_workspace_free(w);
	gsl_integration_workspace_free(q);
	
	double E = psiHpsi / psipsi;
	printf("E = %.g\n", E);

	return 0;
}
