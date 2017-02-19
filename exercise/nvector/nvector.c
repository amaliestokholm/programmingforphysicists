#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "nvector.h"

nvector* nvector_alloc(int n){
	nvector* v = malloc(sizeof(nvector));
	(*v).size = n;
	(*v).data = malloc(n * sizeof(double));
	if( v==NULL )
	       	fprintf(stderr,"Error in nvector_alloc\n");
	return v;
}

void nvector_free(nvector* v){
	// Free the memory v points to. You need a free statement per malloc. Unused pointers are set to NULL in order to protect against dangling pointer bugs. If v is accessed after it is freed, you may read or overwrite random memory, but if it is a null pointer, most systems would crash, telling you what the error is.
       	free(v->data);
	free(v);
	v=NULL;
}

void nvector_set(nvector* v, int i, double value){
	// make sure that i is within the length of (*v).data
	assert(0 <= i && i < (*v).size)
        (*v).data[i]=value;
}

double nvector_get(nvector* v, int i){
	// make sure that i is within the length of (*v).data
	assert(0 <= i && i < (*v).size)
	return (*v).data[i]; 
}


