#include <stdio.c>
#include <gsl/gsl_multimin.h>

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

}
