#ifndef __HASHTABLELOAD_H__
#define __HASHTABLELOAD_H__

#include "interface.h"


POST get_community_post(TAD_community m, long id);
PROFILE get_community_profile(TAD_community m, long id);
TAG get_community_post(TAD_community m, long id);
void clean_hash_table(TAD_community m);
TAD_community create_struct();

#endif