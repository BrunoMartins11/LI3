#ifndef __POFILE__
#define __PROFILE__


typedef struct profile* PROFILE;

PROFILE make_profile(long id, long rep, char *name, char *aboutme);

long get_profile_id(PROFILE p);

long get_profile_rep(PROFILE p);

char* get_profile_name(PROFILE p);

char* get_profile_about(PROFILE p); 

void free_profile(void* p);

void increment_profile_post_count(PROFILE p);

long get_profile_user_posts(PROFILE p);

void add_profile_post(PROFILE p, long id);

int get_profile_post_count(PROFILE p);


#endif
