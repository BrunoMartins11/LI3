#ifndef __POSTS_H__
#define __POSTS_H__
#include "date.h"

typedef struct posts *POST;
POST make_post(long postID, char* postTitle, int postType, long parentID, long score, Date data, long answerCount, long commentCount, char** tags, long ownerID);
char* get_title(POST p);
long get_post(POST p);
int get_post_type(POST p);
long get_parentID(POST p);
long get_score(POST p);
Date get_date(POST p);
long get_awnserC(POST p);
long get_commentC(POST p);
long get_owner(POST p);
char** get_tags(POST p);
void free_post(void* p);
#endif