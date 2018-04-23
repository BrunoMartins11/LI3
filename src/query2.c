#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "posts.h"
#include "list.h"
#include "profile.h"
#include "tadCommunity.h"
#include "par.h"

//funçao de comparaçao
gint fcompare(gconstpointer p1, gconstpointer p2){
	PAR par1 = *((PAR*) p1);
	PAR par2 = *((PAR*) p2);
/*	if(!p1 && !p2) return (gint)0;
	if(!p1) return((gint)1);
	if(!p2) return ((gint)(-1));*/
	return (gint) (get_par_pCount(par2)-get_par_pCount(par1));
}


//funçao que vai criar o par e inserir na estrutura
void insert_pCount_GList_user(gpointer key, gpointer value, gpointer list){
	
	long profileID = get_profile_id((PROFILE)value);
	int pCount = get_profile_post_count((PROFILE)value);

	if(profileID > 0 && pCount > 0){ //verifica se sao NULL
		PAR p = make_new_par(profileID, pCount);// insere no par
		g_ptr_array_add(list, p); //insere na lista
	}
}


//cria a lista e itera a estrutura dos users toda
GPtrArray* create_GList_user_pCount(TAD_community com, GHFunc func){

	GPtrArray* array = g_ptr_array_new();
	iterate_community_users(com, func, array); // itera os users
	g_ptr_array_sort(array, fcompare);
	
	return array;
}

/*cria a lista dos profs para retornar. cria uma lista do glib auxiliar em que insere cada par de informaçao com
o id do user e o postCount. no fim ordena a lista tendo em conta o postCount */
LONG_list top_most_active(TAD_community com, int N){
	
	if (N<=0) return NULL;

	LONG_list l = create_list(N);

	int i=0;
	GPtrArray* array = create_GList_user_pCount(com, insert_pCount_GList_user);
	//g_ptr_array_sort(array, (GCompareFunc)fcompare);
	
	while(i<N && i<array->len){
		set_list(l, i, get_par_id(g_ptr_array_index(array, i)));
		printf("%ld\n", get_list( l, i));
		i++;	
	}

	return l;
}