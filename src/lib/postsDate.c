#include <stdlib.h>
#include <date.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>
#include "postsDate.h"
#include "date.h"


struct postsDate{

	GArray** matrix; //um array de GArrays
};


int date_to_int(Date d){

	int equivalent;
	
	int dia = get_day(d) - 1; //diferença de dias
	int mes = get_month(d) - 1; // diferença de meses
	int ano = get_year(d) - 2008; // diferença de anos
	
	equivalent = dia + mes*31 + ano*(12*31);
	
	return equivalent;

}


POSTSDATE init_id_matrix(){
	
	Date d = createDate(1, 1, 2019);
	
	POSTSDATE p = malloc(sizeof(struct postsDate));
	p->matrix = malloc(sizeof(GArray*)*(date_to_int(d)));
	
	for(int i = 0; i < date_to_int(d); i++)
		p->matrix[i] = g_array_new(FALSE, TRUE, sizeof(long));

	return p;
}


void insert_id_to_matrix(POSTSDATE p, long id, Date d){

	int index = date_to_int(d);
	GArray* a = p->matrix[index];
	g_array_append_val(a, id);
}


GArray* get_id_array(Date d, POSTSDATE p){

	if(p)
		return p->matrix[date_to_int(d)];
	return NULL;
}