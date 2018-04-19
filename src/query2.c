#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "interface.h"
#include "posts.h"
#include "list.h"
#include "dArray.h"
#include "profile.h"
#include "tadCommunity.h"
#include "par.h"

//funçao de compraçao
gint fcompare(PAR p1, PAR p2){

/*	if(!p1 && !p2) return (gint)0;
	if(!p1) return((gint)1);
	if(!p2) return ((gint)(-1));*/
	return((gint)(get_par_pCount(p2)-get_par_pCount(p1)));
}


//funçao que vai criar o par e inserir na estrutura
void insert_pCount_GList_user(gpointer key, gpointer value, gpointer list){
	
	long profileID = get_profile_id((PROFILE)value);
	int pCount = get_profile_post_count((PROFILE)value);

	if(profileID > 0 && pCount > 0){ //verifica se sao NULL 
		PAR p = make_new_par(profileID, pCount);// insere no par
		insert_listG_par(list, p); //insere na lista
	}
}


//cria a lista e itera a estrutura dos users toda
LISTG create_GList_user_pCount(TAD_community com, GHFunc func){

	LISTG list = create_listG(sizeof(PAR)); //cria a lista
	iterate_community_users(com, func, (GList*)list); // itera os users
	
	return list;	
}

/*cria a lista dos profs para retornar. cria uma lista do glib auxiliar em que insere cada par de informaçao com
o id do user e o postCount. no fim ordena a lista tendo em conta o postCount */
LONG_list top_most_active(TAD_community com, int N){
	
	if (N<=0) return NULL;

	LONG_list l = create_list(N);

	int i=0;
	LISTG list = create_GList_user_pCount(com, insert_pCount_GList_user);
	list = (LISTG)sort_listG_par(list, (GCompareFunc)fcompare);
	
	while(i<N){
		set_list(l, i, get_par_id(get_listG_par(list,i)));
		printf("%ld\n", get_list( l, i));
		i++;	
	}

	return l;
} 




