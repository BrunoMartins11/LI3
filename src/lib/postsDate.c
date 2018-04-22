#include <stdlib.h>
#include <date.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>
#include "postsDate.h"
#include "date.h"
#include "dArray.h"
#include "posts.h"


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

	return p->matrix[date_to_int(d)];
}

void clean_postsDate(POSTSDATE p){
	if(p){
		for(int i=0; p->matrix; i++)
			g_array_free(p->matrix[i], TRUE);
		
		free(p->matrix);
		free(p);
	}
}

GArray* posts_id_between_dates(POSTSDATE p, Date a, Date b){

	int i, maior, menor;
	
	if(date_to_int(a) > date_to_int(b)){
		maior = date_to_int(a);
		menor = date_to_int(b);
	}
	
	else{
		
		maior = date_to_int(b);
		menor = date_to_int(b);
	}

	GArray* ret = g_array_new(FALSE, TRUE, sizeof(long));

	for(i = menor; i <= maior; i++)
		
		for(int j = 0; j < (p->matrix[j]->len); j++){

			g_array_append_val(ret, g_array_index(p->matrix[i], long, j));
	
		}
	
	return ret;

}


LISTG posts_id_between_dates2(POSTSDATE p, Date a, Date b){

	int i, maior, menor;
	LISTG posts_ids = create_listG(sizeof(long));

	if(date_to_int(a) > date_to_int(b)){
		maior = date_to_int(a);
		menor = date_to_int(b);
	}
	else{
		maior = date_to_int(b);
		menor = date_to_int(a);
	}

	for(i = menor; i <= maior; i++)	
		for(int j = 0; j < (p->matrix[i]->len); j++)
			append_listG(posts_ids, g_array_index(p->matrix[i], long, j));

	return posts_ids;
}

void add_posts_to_matrix(gpointer key, gpointer value, gpointer user_data){

	long id = get_post_id(value);
	Date d = get_post_date(value);

	insert_id_to_matrix((POSTSDATE) user_data, id, d);
}



