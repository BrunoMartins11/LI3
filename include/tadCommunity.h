#ifndef __TADCOMMUNITY_H__
#define __TADCOMMUNITY_H__
#include <glib.h>
#include "interface.h"
#include "date.h"
#include "postDate.h"
#include "profile.h"
#include "posts.h"
#include "tags.h"


POST get_community_post(TAD_community m, long id);

PROFILE get_community_profile(TAD_community m, long id);

void clean_hash_table(TAD_community m);

TAD_community create_struct();

void add_community_post(TAD_community m, long id, POST p);

void add_community_profile(TAD_community m, long id, PROFILE p);

TAG get_community_tag(TAD_community m, char* id);

void add_community_tag(TAD_community m, long id, TAG t);

void iterate_community_users(TAD_community m, GHFunc func, gpointer data);




#endif