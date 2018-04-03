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
	m->profile = g_hash_table_new_full( g_int64_hash, g_int64_equal, free_profile, ); //falta o ultimo parametro
	m->posts = g_hash_table_new_full( g_int64_hash, g_int64_equal, free_post, ); //falta o ultimo parametro
	return m;
}

GHashTable get_profile_hash(TAD_Community m){
	if(m) return m->profile;
	return NULL;
}

GHashTable get_posts_hash(TAD_Community m){
	if (m) return m->posts;
	return NULL;
}

void clean_hash_table(TAD_Community m){
	if(m){
	free_post(m->posts);
	free_post(m->profile);
	free(m);
	}
}
