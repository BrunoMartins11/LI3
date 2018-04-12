#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "tags.h"

struct tag{
	char* name;
	long  tagID;
};

TAG create_tag(char* name, long tagID){
	TAG t = malloc(sizeof(struct tag));
	t->name = g_strdup(name);
	t->tagID = tagID;
	return t;
}

char* get_tag_name(TAG t){
	return g_strdup(t->name);
}

long get_tag_id(TAG t){
	return t->tagID;
}

void free_tag(void* ta){
	TAG t = (TAG)ta;
	free(t->name);
	free(t);
}