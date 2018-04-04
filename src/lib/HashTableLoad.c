#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "posts.h"
#include "profile.h"
#include "interface.h"
#include "date.h"
#include "postDate.h"
#include "profile.h"
#include "posts.h"

struct TCD_community{
	GHashTable *profile;
	GHashTable *posts;
	GHashTable *postDate;
};

TAD_community create_struct(){
	TAD_community m = malloc(sizeof (struct TCD_community));
	m->profile = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_profile); 
	m->posts = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_post);
	m->postDate = g_hash_table_new_full(g_int64_hash, g_int64_equal, g_free,free_postDate); 
	return m;
}

GHashTable* get_profile_hash(TAD_community m){
	return m->profile;
	
}

GHashTable* get_posts_hash(TAD_community m){
	return m->posts;
	
}

GHashTable* get_postDate_hash(TAD_community m){
	return m->postDate;
}


void clean_hash_table(TAD_community m){
	if(m){
		g_hash_table_destroy(m->profile);
		g_hash_table_destroy(m->posts);
		g_hash_table_destroy(m->postDate);
	}
}
