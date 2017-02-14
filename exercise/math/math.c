#include <stdio.h>
#include <math.h>
#include <complex.h>


int main() {
	// Calculate gamma(5)
	double x=5;
	double gx = tgamma(x);
	printf("gamma(%g) is %g\n", x,gx);
	// Calculate Bessel function of first kind to 0.5
	double y=0.5;
	double jy = j0(y);
	printf("Bessel(%g) is %g\n", y,jy);
	// Play around with complex numbers
	double complex z = -2;
	double complex sz = csqrt(z);
	printf("csqrt(%g+%gi) is %g+%gi\n", creal(z), cimag(z), creal(sz), cimag(sz));
	double complex ce = cexp(I);
	printf("exp(%g+%gi) is %g+%gi\n", creal(I), cimag(I), creal(ce), cimag(ce));
	double complex cpi = cexp(I * M_PI);
	printf("exp(%g+%gi) is %g+%gi\n", creal(I * M_PI), cimag(I * M_PI), creal(cpi), cimag(cpi));
	double complex ie = cpow(I, M_E); 
	printf("i^e is %g+%gi\n", creal(ie), cimag(ie));
return 0;
}
