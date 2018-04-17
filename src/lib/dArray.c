#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include "par.h"


struct listG {
	GList* list;
};

GList* create_listG(){
	GList* list = malloc(sizeof(GList));
	return list;
}

void insert_listG_par(GList* list,PAR p, GCompareFunc func){
	printf("%ld\n",get_par_id(p) );
	list = g_list_insert_sorted(list,p,func);
}

PAR get_listG_par(GList* list, guint n){
	return (PAR)g_list_nth(list, n);
}

