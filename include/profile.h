#ifndef __POFILE__
#define __PROFILE__


typedef struct profile* PROFILE;

PROFILE make_profile(long id, long rep, char *name, char *aboutme);
long get_id(PROFILE p);
long get_rep(PROFILE p);
char* get_name(PROFILE p);
char* get_profile(PROFILE p); 
void free_profile(void* p);


#endif
