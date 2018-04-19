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

struct _dynamic_list{
	
	GList *list;
};

dynamic_list* create_dynamic_list(){
	
	dynamic_list *l = malloc(sizeof (struct _dynamic_list));
	return l;
}

struct TCD_community{
	
	GHashTable *profile;
	GHashTable *posts;
	GHashTable *tags;
	GArray **postsDate;
}; 


TAD_community init(){
	
	return create_struct();
}


TAD_community create_struct(){
	
	TAD_community m = malloc(sizeof (struct TCD_community));
	m->profile = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_profile); 
	m->posts = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free,free_post); 
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
	PROFILE po = get_community_profile(m, owner);
	
	if(po) { 
		increment_profile_post_count(po);
		add_profile_post(get_community_profile(m, owner), id);
		g_hash_table_insert(m->posts,idp,p);
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
	g_hash_table_foreach(m->posts, func, data);
}

void iterate_community_users(TAD_community m, GHFunc func, gpointer data){
	g_hash_table_foreach(m->profile,func,data);
}

void clean_TAD_community(TAD_community m){
	
	if(m){
		g_hash_table_destroy(m->profile);
		g_hash_table_destroy(m->posts);
		//adicionar clean func da matriz
	}
}

int str_in_postTitle(POST p, char* str){
	
	if (strstr(get_post_title(p), str) != NULL)
		return 1;
	
	else 
		return 0;
}

GList* get_all_keys(GHashTable* dict){
	
	return g_hash_table_get_values(dict);
}

dynamic_list* get_all_keys_post(TAD_community m){
	
	dynamic_list *l = create_dynamic_list();
	l->list = get_all_keys(m->posts);
	
	return l;
}

int list_size(dynamic_list* l){
	
	return (int) g_list_length(l->list);
}

dynamic_list* sort_list(dynamic_list* l, long func){
	
	l->list = g_list_sort(l->list, (GCompareFunc) func);
	
	return l;
}

long get_data_from_list(dynamic_list* l){
	
	return (long) l->list->data;
}

dynamic_list* next(dynamic_list* lista){
	
	lista->list = lista->list->next;
	
	return lista;
}

