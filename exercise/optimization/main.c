#include <stdio.c>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multimin.h>
#include <assert.h>

struct exp_data {int n; double *t, *y, *e;}

double deviation(const gsl_vector *x, void *params) {
	double a = gsl_vector_get(x, 0);
	double t = gsl_vector_get(x, 1);
	double e = gsl_vector_get(x, 2);

	struct exp_data *p = (struct exp_data*) params;

	int n = p->n;
	double *t = p->t;
	double *y = p->y;
	double *e = p->e;
	
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += pow(f(t[i]) - y[i], 2) / pow(e[i], 2);
	}
	return sum;
}

int main() {
	int status;
	int iter = 0;
	double dim = 3, eps = 1e-3, step = 1;
	const gsl_multimin_fminimizer_type *T = gsl_multimin_fminimizer_nmsimplex2;

	// Load data
	double t[]= {0.47,1.41,2.36,3.30,4.24,5.18,6.13,7.07,8.01,8.95};
	double y[]= {5.49,4.08,3.54,2.61,2.09,1.91,1.55,1.47,1.45,1.25};
	double e[]= {0.26,0.12,0.27,0.10,0.15,0.11,0.13,0.07,0.15,0.09};

	int n = sizeof(t) / sizeof(t[0]);
	assert(n == sizeof(y) / sizeof(y[0]) && n == sizeof(e) / sizeof(e[0]));

	printf("t[i]\ty[i]\te[i]");
	for(int i = 0; i < n; i++) {
		printf("%g\t%g\t%g\n", t[i], y[i], e[i]);
	}

	struct exp_data params;
	params.n=n;
	params.t=t;
	params.y=y;
	params.e=e;

	gsl_multimin_function F;
	F.f = deviation;
	F.n = dim;
	F.params = (void*) &params;

	gsl_vector *x = gsl_vector_alloc(dim);
	gsl_vector_set(x, 0, 3);
	gsl_vector_set(x, 1, 2);
	gsl_vector_set(x, 2, 0);

	gsl_vector *ss = gsl_vector_alloc(dim);
	gsl_vector_set_all(ss, step);

	// Initialise
	gsl_multimin_fminimizer *s = gsl_multimin_fminimizer_alloc(T, dim);
	gsl_multimin_fminimizer_set(s, &F, x, ss);



}
