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

};

PROFILE make_profile(long id, long rep, char *name, char *aboutme){
	PROFILE p = malloc(sizeof (struct profile));
	p->id = id;
	p->rep = rep;
	p->name = g_strdup(name);
	p->aboutme = g_strdup(aboutme);
}

long get_id(PROFILE p){
	return p->id;
	
}

long get_rep(PROFILE p){
	return p->rep;
	
}

char* get_name(PROFILE p){
	return p->name;
	
}

char* get_profile(PROFILE p){
	return p->aboutme;
	
}

void* free_profile(PROFILE p){
	if (p) {
		free(p->name);
		free(p->aboutme);
		free(p);
	}
}