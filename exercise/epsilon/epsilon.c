#include <stdio.h>
#include <limits.h>
#include <float.h>

int intmax_while() {
	int i = 1;
	while (i + 1 > i)
	{i++;}
	printf("While: max_int = %i\n", i);
	return i;
}

int intmax_for() {
	int i;
	for (i=1; (i + 1) > i;)
	{i++;}
	printf("For: max_int = %i\n", i);
	return i;
}

int intmax_dowhile() {
	int i = 1;
	do {i++;}
	while (i + 1 > 1);
	printf("dowhile: max_int = %i\n", i);
	return i;
}

int intmin_while() {
	int i = 1;
	while (i - 1 < i)
	{i--;}
	printf("While: min_int = %i\n", i);
	return i;
}

int intmin_for() {
	int i;
	for (i=1; (i - 1) < i;)
	{i--;}
	printf("For: min_int = %i\n", i);
	return i;
}

int intmin_dowhile() {
	int i = 1;
	do {i--;}
	while (i - 1 < 1);
	printf("dowhile: min_int = %i\n", i);
	return i;
}

float epsilon_floatwhile() {
	float fx = 1.;
	while (1+fx != 1)
	{fx /=2;}
	fx *=2;
	printf("while: epsilon = %g, flt_epsilon = %g\n", fx, FLT_EPSILON);
	return fx;
}

double epsilon_doublewhile() {
		double dx = 1.;
		while (1+dx != 1)
		{dx /=2;}
		dx *=2;
		printf("while: epsilon = %g, dbl_epsilon = %g\n", dx, DBL_EPSILON);
		return dx;
}

long double epsilon_ldoublewhile() {
		long double ldx = 1.;
		while (1+ldx != 1)
		{ldx /=2;}
		ldx *=2;
		printf("while: epsilon = %Lg, dbl_epsilon = %Lg\n", ldx, LDBL_EPSILON);
		return ldx;
}

float epsilon_floatfor() {
		float fx;
		for (fx = 1.; 1+fx != 1;fx /= 2) {
	}
		fx *=2;
		printf("for: epsilon = %g, flt_epsilon = %g\n", fx, FLT_EPSILON);
		return fx;
}
double epsilon_doublefor() {
		double dx;
		for (dx = 1.; 1+dx != 1; dx /= 2) {
	}
		dx *=2;
		printf("for: epsilon = %g, dbl_epsilon = %g\n", dx, DBL_EPSILON);
		return dx;
}

long double epsilon_ldoublefor() {
		long double ldx;
		for (ldx = 1.; 1+ldx != 1; ldx /= 2.) {
	}
		ldx *=2;
		printf("for: epsilon = %Lg, dbl_epsilon = %Lg\n", ldx, LDBL_EPSILON);
		return ldx;
	}

float epsilon_floatdowhile() {
		float fx = 1.;
		do {fx /=2;}
		while (1+fx != 1);
		fx *=2;
		printf("dowhile: epsilon = %g, flt_epsilon = %g\n", fx, FLT_EPSILON);
		return fx;
}

double epsilon_doubledowhile() {
		double dx = 1.;
		do {dx /=2;}
		while (1+dx != 1);
		dx *=2;
		printf("dowhile: epsilon = %g, dbl_epsilon = %g\n", dx, DBL_EPSILON);
		return dx;
}

long double epsilon_ldoubledowhile() {
		long double ldx = 1.;
		do {ldx /=2;}
		while (1+ldx != 1);
		ldx *=2;
		printf("dowhile: epsilon = %Lg, dbl_epsilon = %Lg\n", ldx, LDBL_EPSILON);
		return ldx;
}

float sum_up_float(int intmax) {
	int i;
	float sum_up_float;
	intmax /= 2;
       	for( i=1; ; i++) {
		sum_up_float += 1.0f/i;
		if (i == intmax) {
			break;
		}
	}
	printf("Sum_up: %g\n", sum_up_float);
	return 0;
}


float sum_down_float(int intmax) {
	int i;
	float sum_down_float;
	intmax /= 2;
	for( i=0; ; i++) {
		sum_down_float += 1.0f/(intmax - i);
		if (i == (intmax - 1)) {
			break;
		}
	}
	printf("Sum_down: %g\n", sum_down_float);
	return 0;
}


void name_digit(int i) {
	switch(i) {
		case 0 :
			printf("Zero\n");
			break;
		case 1 :
			printf("One\n");
			break;

		case 2 :
			printf("Two\n");
			break;

		case 3 :
			printf("Three\n");
			break;

		case 4 :
			printf("Four\n");
			break;

		case 5 :
			printf("Five\n");
			break;

		case 6 :
			printf("Six\n");
			break;

		case 7 :
			printf("Seven\n");
			break;

		case 8 :
			printf("Eight\n");
			break;

		case 9 :
			printf("Nine\n");
			break;
	}
}
int main(){
	printf("Hello World\n");
	/*int i=1; printf("%i\n",i++); printf("%i\n",++i); */

	name_digit(0);
	name_digit(7);
	name_digit(1);

	int intmaxw = intmax_while();
	int intmaxf = intmax_for();
	int intmaxdw = intmax_dowhile();
	
	int intmin = intmin_while();
	int intminf = intmin_for();
	int intmindw = intmin_dowhile();

	float e_fw = epsilon_floatwhile();
	double e_dw = epsilon_doublewhile();
	long double e_ldxw = epsilon_ldoublewhile();

	float e_ff = epsilon_floatfor();
	double e_df = epsilon_doublefor();
	long double e_ldxf = epsilon_ldoublefor();

	float e_fdw = epsilon_floatdowhile();
	double e_ddw = epsilon_doubledowhile();
	long double e_ldxdw = epsilon_ldoubledowhile();

	// sum_up starts out with big number and the increment gets smaller and smaller, while sum_down starts small and the increment gets larger and larger. 
	float sum_up = sum_up_float(intmaxf);
	float sum_down = sum_down_float(intmaxf);

	double a = 1.00;
	double b = a;
	int eq1 = equal(a, b, 0.001, e_dw);
	printf("eq1 = %d\n", eq1);
	int eq2 = equal(1, 2, 0.005, 0.01);
	printf("eq2 = %d\n", eq2);
return 0;
}



