#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "interface.h"
#include "profile.h"
#include "posts.h"
#include "hashTableLoad.h"

// retorna o apontador do post que procuramos
gpointer get_postq(TAD_community com, long postID){
	/*gconstpointer IDaux = (gconstpointer)&postID;
	guint hash = g_int64_hash(IDaux);
	gconstpointer hashaux = (gconstpointer)&hash;
	GHashTable* postHashT = get_posts_hash(com);
	return g_hash_table_lookup(postHashT, hashaux);*/
	GHashTable* x = get_posts_hash(com);
	return g_hash_table_lookup(x, &postID);

}

// recebe o apontador calculado na funçao anterior e retorna a string com o nome e titulo do post
STR_pair get_info(TAD_community com, gpointer pID){

	POST p = (POST)pID;
	long ownerID = get_owner(p);
	GHashTable* hash_user = get_profile_hash(com);
	PROFILE u = (PROFILE)g_hash_table_lookup(hash_user, &ownerID);
	
	if(get_title(p) == NULL){
		return create_str_pair("aqui devia ser o nome", NULL);
	}

	return  create_str_pair("devia ser o nome", get_title(p));
}

STR_pair info_from_post(TAD_community com, long id){

	gpointer p = get_postq(com,id);
	
	if(!p) return NULL;
	POST po =(POST)p;
	if (get_post_type(po) == 2){
		gpointer pID;	
		pID = get_postq(com, get_parentID(po));
		return get_info(com, pID);
	}
	return get_info(com, p);
} 


