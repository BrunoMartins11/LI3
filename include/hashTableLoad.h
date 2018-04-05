#ifndef __HASHTABLELOAD_H__
#define __HASHTABLELOAD_H__

#include "interface.h"


GHashTable* get_profile_hash(TAD_community m);
GHashTable* get_postDate_hash(TAD_community m);
GHashTable* get_posts_hash(TAD_community m);
GHashTable* get_tags_hash(TAD_community m);
void clean_hash_table(TAD_community m);
TAD_community create_struct();

#endif