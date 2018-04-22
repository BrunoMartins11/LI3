#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include "par.h"
#include "dArray.h"

struct listG {
	GArray* list;
};


LISTG create_listG(int size){
	
	LISTG array = malloc(sizeof(struct listG));
	array->list = g_array_new(FALSE, TRUE, size);
	
	return array;
}

void set_listG(LISTG array, GArray* g_array){
	g_array_free(array->list, TRUE);
	array->list = g_array;
}

void insert_listG_par(LISTG array, PAR p){
	
	if(p!=NULL){
		g_array_append_val(array->list, p);
	}
}

LISTG sort_listG_par(LISTG array, GCompareFunc func){

	if(array!=NULL)
		g_array_sort(array->list, func);
	
	return(array);
}

PAR get_listG_par(LISTG array, int i){
	return (PAR)g_array_index(array->list, PAR, i);
}

GArray* get_GArray(LISTG array){
	return array->list;
}

void sort_listG(LISTG array, GCompareFunc func){
	g_array_sort(array->list, func);
}
	
int listG_size(LISTG array){
	return (int) array->list->len;
}

int listG_reverse_sort(gconstpointer num_a, gconstpointer num_b){
	if(!num_a && !num_b)
		return 0;

	if(!num_a)
		return 1;

	if(!num_b)
		return -1;

	return (int) (num_b - num_a);
}