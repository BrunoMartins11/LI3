#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include "par.h"
#include "dArray.h"
#include "posts.h"

struct listG {
	GArray* list;
};


LISTG create_listG(int size){
	
	LISTG array = malloc(sizeof(struct listG));
	array->list = g_array_new(FALSE, TRUE, size);
	
	return array;
}

void free_listG(LISTG array){
	g_array_free(array->list, TRUE);
	free(array);
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

int listG_reverse_sort_id(gconstpointer num_a, gconstpointer num_b){

	long* id_1 = (long*) num_a;
	long* id_2 = (long*) num_b;

	return (int) (*id_2 - *id_1);
}

int listG_reverse_sort_answer(gconstpointer post_1, gconstpointer post_2){
	
	POST* p1 = (POST*) post_1 ;
	POST* p2 = (POST*) post_2;

	return (int) (get_post_awnser_count(*p2) - get_post_awnser_count(*p1));
}