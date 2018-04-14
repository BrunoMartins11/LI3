#include <stdlib.h>
#include <date.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>
#include "profile.h"


struct profile{
	long id;
	char *name;
	char *aboutme;
	long rep;
	int postCount;
	long userPosts[];
};

PROFILE make_profile(long id, long rep, char *name, char *aboutme){
	PROFILE p = malloc(sizeof (struct profile));
	p->id = id;
	p->rep = rep;
	p->name = g_strdup(name);
	p->aboutme = g_strdup(aboutme);
	p->postCount = 0;
	return p;
}

void increment_profile_post_count(PROFILE p){

	p->postCount += 1;
}

int get_profile_post_count(PROFILE p){
	return p->postCount;
}


long get_profile_id(PROFILE p){
	return p->id;
	
}

long get_profile_rep(PROFILE p){
	return p->rep;
	
}

char* get_profile_name(PROFILE p){
	return p->name;
	
}

char* get_profile_about(PROFILE p){
	return p->aboutme;
	
}

void add_profile_post(PROFILE p, long id){
	if (p->postCount>0)
		p->userPosts[p->postCount-1] = id;
}

long get_profile_user_posts(PROFILE p){
	return (long)p->userPosts;
}

void free_profile(void* po){
	PROFILE p = (PROFILE)po;
	if (p) {
		free(p->name);
		free(p->aboutme);
		free(p);
	}
}