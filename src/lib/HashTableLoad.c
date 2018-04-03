#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "posts.h"
#include "profile.h"

struct TCD_Community{
	GHashTable *profile;
	GHashTable *posts;
};

TAD_Community create_struct(){
	TAD_Community m = malloc(sizeof TAD_Community);
	m->profile = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_profile); 
	m->posts = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_post); 
	return m;
}

GHashTable get_profile_hash(TAD_Community m){
	return m->profile;
	
}

GHashTable get_posts_hash(TAD_Community m){
	return m->posts;
	
}

void clean_hash_table(TAD_Community m){
	if(m){
		g_hash_table_destroy(m->profile);
		g_hash_table_destroy(m->posts);
	}
}
