#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include "par.h"
#include "dArray.h"


struct listG {
	GList* list;
};

LISTG create_listG(){
	
	LISTG list = malloc(sizeof(struct listG));
	list = NULL;
	list = (LISTG)g_list_insert((GList*)list,make_new_par(1,1),0);
	return list;
}

void insert_listG_par(LISTG list,PAR p){
	
	if(p!=NULL){
		list = (LISTG)g_list_append((GList*)list,p);
	}
}

LISTG sort_listG_par(LISTG list, GCompareFunc func){
	list = (LISTG)g_list_sort((GList*)list, func);
	return(list);
}

PAR get_listG_par(LISTG list, guint n){
	return (PAR)g_list_nth((GList*)list, n);
}


