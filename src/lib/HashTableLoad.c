#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

struct TCD_Community{
	GHashTable *profile;
	GHashTable *posts;
};

TCD_Community create_struct(){
	TCD_Community m = malloc(sizeof TCD_Community);
	m->profile = g_hash_table_new_full( g_int64_hash, g_int64_equal, free_profile, ); //falta o ultimo parametro
	m->posts = g_hash_table_new_full( g_int64_hash, g_int64_equal, free_post, ); //falta o ultimo parametro
	return m;
}