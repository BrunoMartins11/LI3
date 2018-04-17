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


gint fcompare(PAR p1, PAR p2){
	if(!p1 && !p2) return (gint)0;
	if(!p1) return((gint)1);
	if(!p2) return ((gint)-1);
	return((gint)(get_par_pCount(p2)-get_par_pCount(p1)));
}

void search_user_postCount_aux(gpointer key, gpointer value, gpointer list){
	
	PAR p = make_new_par(get_profile_id((PROFILE)value), get_profile_post_count((PROFILE)value));
	insert_listG_par(list,p,(GCompareFunc)fcompare);

}

GList* search_user_pCount(TAD_community com, GHFunc func){

	GList* list = create_listG();
	iterate_community_users(com, search_user_postCount_aux, list);
	return list;	
}





LONG_list top_most_active(TAD_community com, int N){
	
	if (N<=0) return NULL;

	LONG_list l = create_list(N);
	int i=0;
	GList* list = search_user_pCount(com,search_user_postCount_aux);

	while(i<N){
		set_list(l, i, get_par_id(get_listG_par(list,i)));
		i++;	
	}

	return l;
} 






