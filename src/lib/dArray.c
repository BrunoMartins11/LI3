#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include "par.h"
#include "dArray.h"


struct listG {
	GArray* list;
};

// passar "sizeof(tipo_de_dado)" como argumento da função
LISTG create_listG(int size){
	
	LISTG array = malloc(sizeof(struct listG));
	array->list = g_array_new(TRUE, TRUE, size);
	return array;
}

void insert_listG_par(LISTG array,PAR p){
	
	if(p!=NULL){
		g_array_append_val(array->list, p);
	}
}

LISTG sort_listG_par(LISTG array, GCompareFunc func){

	if(array!=NULL)
		g_array_sort(array->list, func);
	return(array);
}

PAR get_listG_par(LISTG array, guint n){
	return (PAR) g_array_index(array->list, PAR, n);
}


