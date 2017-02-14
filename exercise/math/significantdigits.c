#include<stdio.h>
#include<math.h>
int significantdigits(){
	float f = .1111111111111111111111111111;
	double d = .1111111111111111111111111111;
	long double l = .1111111111111111111111111111L;
	printf("Float %.25g, double %.25lg, long double %.25Lg", f, d, l);
	return 0;
}

