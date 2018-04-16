#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "interface.h"
#include "date.h"
#include "postDate.h"
#include "profile.h"
#include "posts.h"
#include "tags.h"
#include "tadCommunity.h"

struct TCD_community{
	GHashTable *profile;
	GHashTable *posts;
	GHashTable *postDate;
	GHashTable *tags;
};


TAD_community init(){
	return create_struct();
}


TAD_community create_struct(){
	TAD_community m = malloc(sizeof (struct TCD_community));
	m->profile = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_profile); 
	m->posts = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_post);
	m->postDate = g_hash_table_new_full(g_str_hash, g_str_equal, g_free,free_postDate); 
	m->tags = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, free_tag);
	return m;
}


POST get_community_post(TAD_community m, long id){
	
	return (POST)g_hash_table_lookup(m->posts,&id);
}


void add_community_post(TAD_community m, long id, POST p){
	
	long* idp = malloc(sizeof(long));
	*idp = get_post_id(p);
	long owner = get_post_owner(p);
	
	increment_profile_post_count(get_community_profile(m, owner));
	//add_profile_post(get_community_profile(m, owner), id);
	g_hash_table_insert(m->posts,idp,p);
}


PROFILE get_community_profile(TAD_community m, long id){
	
	return (PROFILE)g_hash_table_lookup(m->profile,&id);
}


void add_community_profile(TAD_community m, long id, PROFILE p){

	long* idp = malloc(sizeof(long));
	*idp = get_profile_id(p);

	g_hash_table_insert(m->profile,idp,p);
}


TAG get_community_tag(TAD_community m, char* id){
	
	return (TAG)g_hash_table_lookup(m->tags,&id);
}


void add_community_tag(TAD_community m, long id, TAG t){

	long* idp = malloc(sizeof(long));
	*idp = get_tag_id(t);
	
	g_hash_table_insert(m->tags,idp,t);
}

void iterate_community_posts(TAD_community m, GHFunc func){
	g_hash_table_foreach(m->posts, func, NULL);
}

void clean_hash_table(TAD_community m){
	if(m){
		g_hash_table_destroy(m->profile);
		g_hash_table_destroy(m->posts);
		g_hash_table_destroy(m->postDate);
	}
}
