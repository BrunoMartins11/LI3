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
#include "postsDate.h"
#include "dArray.h"

struct TCD_community{
	
	GHashTable *profile;
	GHashTable *posts;
	GHashTable *tags;
	POSTSDATE postsDate;
}; 


TAD_community init(){
	
	return create_struct();
}


TAD_community create_struct(){
	
	TAD_community m = malloc(sizeof (struct TCD_community));
	m->profile = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_profile); 
	m->posts = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_post); 
	m->tags = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, free_tag);
	m->postsDate = init_id_matrix();
	return m;
}


POST get_community_post(TAD_community m, long id){
	
	return (POST)g_hash_table_lookup(m->posts,&id);
}




void add_community_post(TAD_community m, long id, POST p){
	
	long* idp = malloc(sizeof(long));
	*idp = get_post_id(p);
	
	long owner = get_post_owner(p);
	PROFILE po = get_community_profile(m, owner);
	
	if(po) { 
		increment_profile_post_count(po);
		add_profile_post(get_community_profile(m, owner), id);
		insert_id_to_matrix(m->postsDate, id, get_post_date(p));
		g_hash_table_insert(m->posts, idp, p);
		if(get_post_type(p) == 2)
			add_answer(get_community_post(m, get_post_parentID(p)), id);
	}
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

void iterate_community_posts(TAD_community m, GHFunc func, gpointer data){
	g_hash_table_foreach(m->posts, (GHFunc) func, data);
}

void iterate_community_users(TAD_community m, GHFunc func, gpointer data){
	g_hash_table_foreach(m->profile, (GHFunc) func,data);
}

void clean_TAD_community(TAD_community m){
	
	if(m){
		g_hash_table_destroy(m->profile);
		g_hash_table_destroy(m->posts);
		clean_postsDate(m->postsDate);
	}
}

int str_in_postTitle(POST p, char* str){
	
	if (strstr(get_post_title(p), str) != NULL)
		return 1;
	
	else 
		return 0;
}

void add_questions_to_array(gpointer key, gpointer value, gpointer user_data){
	if(get_post_type(value) == 1){
		long id = get_post_id(value);
		append_listG(user_data, id);
	}
}

POSTSDATE get_postsdate(TAD_community m){
	return m->postsDate;
}