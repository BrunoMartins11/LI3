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
	long own = get_owner(p);
	gconstpointer uh = (gconstpointer)&own;
	GHashTable* hash_user = get_profile_hash(com);
	guint hash = g_int64_hash(uh);
	gconstpointer hashaux = (gconstpointer)&hash;
	PROFILE u = (PROFILE)g_hash_table_lookup(hash_user, hashaux);
	if(get_title(p) == NULL) return NULL;
	return create_str_pair(get_name(u), get_title(p));
}

STR_pair info_from_post(TAD_community com, long id){
	gpointer p = get_postq(com,id);
	if(!p) printf("fuck you\n");
	POST po =(POST)p;
	if (get_post_type(po) == 2){
		gpointer pID;	
		pID = get_postq(com, get_parentID(po));
		return get_info(com, pID);
	}
	return get_info(com, p);
} 


