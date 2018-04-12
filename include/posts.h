#ifndef __POSTS_H__
#define __POSTS_H__
#include "date.h"

typedef struct posts *POST;
POST make_post(long postID, 
			   char* postTitle, 
			   int postType, 
			   long parentID, 
			   long score, 
			   Date data, 
			   long answerCount, 
			   long commentCount, 
			   char** tags, 
			   long ownerID);

char* get_post_title(POST p);
long get_post_id(POST p);
int get_post_type(POST p);
long get_post_parentID(POST p);
long get_post_score(POST p);
Date get_post_date(POST p);
long get_post_awnser_count(POST p);
long get_post_comment_count(POST p);
long get_post_owner(POST p);
char** get_post_tags(POST p);
void free_post(void* p);
#endif