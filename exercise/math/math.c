#include <stdio.h>
#include <math.h>
#include<complex.h>


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
	printf("csqrt(%g+i%g) is %g+i%g\n", creal(z), cimag(z), creal(sz), cimag(sz));
	double complex ce = cexp(I);
	printf("exp(%g+i%g) is %g+i%g\n", creal(I), cimag(I), creal(ce), cimag(ce));
	double complex cpi = cexp(I * M_PI);
	printf("exp(%g+i%g) is %g+i%g\n", creal(I * M_PI), cimag(I * M_PI), creal(cpi), cimag(cpi));
	double complex ie = pow(I, M_E); 
	printf("i^e is %g+i%g\n", creal(ie), cimag(ie));
return 0;
}
