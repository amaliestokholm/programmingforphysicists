#include <stdio.h>
void f(int i){i=0;}
int main(){
		int i=1; f(i); printf("i=%i\n",i);
			return 0; }
/*
int main(){
	printf("Hello World\n");
	 int i=1; printf("%i\n",i++); printf("%i\n",++i); 
	 int i=1; printf("%i %i\n", i++, ++i);
	int i=0;
	if(i==1) printf("true\n");
	else printf("false\n");
	for(int i=0,n=2;i<10;i++,n++) printf("i=%i,n=%i\n",i,n);
return 0;
}*/
