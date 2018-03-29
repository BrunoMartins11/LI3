#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "interface.h"
#define MAX 1000


USER get_user_info(TAD_community com, long id); //funçao que é executada no interface

//retorna o about me
char* get_aboutme(long id){
	gconstpointer idaux = id;
	guint hash = g_direct_hash(idaux);
	if (g_hash_table_contains(aDefinir, hash)){
		return	((g_hash_table_lookup(aDefinir, hash))->about);
	}
	return NULL;
}
// retorna o apontador para o post mais antigo deste user
gpointer pointer_last_posts(long id){
	gconstpointer idaux = id;
	guint hash = g_direct_hash(idaux);
	if (g_hash_table_contains(aDefinir, hash)){
		return	g_hash_table_lookup(aDefinir, hash);
	}
	return NULL;
}

//retorna um array com o posts
long last_posts(long id){
    long posts[MAX];
    int i = 0:
    gpointer IDpost = pointer_last_posts(id);
    while(IDpost != NULL){
    	posts[i] = IDpost->postID;
    	i++
    	IDpost = IDpost->next;
    }
    reverse(posts);
}



