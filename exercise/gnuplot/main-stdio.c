#include <stdio.h>
#include <math.h>

void main() {
	double x;
	while( scanf("%lg", &x) != EOF)
		printf("%lg \t %lg\n", x, cos(x));
}
