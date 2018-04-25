#include <stdlib.h>
#include <date.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>
#include "posts.h"
#include "date.h"
#include "postsDate.h"

struct posts{		//esta struct tem campos de perguntas e respostas, 
					//para que consiga conter ambos, tornando possivel ter perguntas e respostas no mesmo array(por exemplo).	
	long postID;		
	char* postTitle;
	int postType; 		//1 -> pergunta, 2-> resposta.
	long parentID; 		// 0 no caso de ser uma pergunta.
	long score;
	Date data;
	long answerCount;
	long commentCount;
	char* tags;		
	long ownerID;	
	GArray* answers;
};

POST make_post(long postID, char* postTitle, int postType, long parentID, long score, Date data, long answerCount, long commentCount, char* tags, long ownerID){
	POST p = malloc(sizeof (struct posts));
	p->postID = postID;	
	p->postTitle = g_strdup(postTitle);
	p->postType = postType; 		
	p->parentID = parentID; 		
	p->score = score;
	p->data = data;
	p->answerCount = answerCount;
	p->commentCount = commentCount;
	p->tags = g_strdup(tags);
	p->ownerID = ownerID;
	p->answers = g_array_new(FALSE, TRUE, sizeof(long));

    return p;
}

char* get_post_title(POST p){
	return g_strdup(p->postTitle);
	
}

long get_post_id(POST p){
	return p->postID;
	
}

int get_post_type(POST p){
	return p->postType;
	
}

long get_post_parentID(POST p){
	return p->parentID;
	
}

long get_post_score(POST p){
	return p->score;
	
}

Date get_post_date(POST p){ 
	return p->data;
	
}

long get_post_awnser_count(POST p){
	return p->answerCount;
	
}

long get_post_comment_count(POST p){
	return p->commentCount;
	
}

long get_post_owner(POST p){
	return p->ownerID;
		
} 

char* get_post_tags(POST p){ 
	return p->tags;
	
}

void free_post(void* po){
	POST p = (POST)po;
	if (p){
		if (p->data) free_date(p->data);
		free(p->postTitle);
		g_array_free(p->answers,TRUE);
		free(p->tags);
		free(p);
	}
	return;
}


void add_answer(POST p, long id){
	if(p)
		g_array_append_val(p->answers, id);
}

GArray* get_answers(POST p){
	return p->answers;
}

int str_in_postTitle(POST p, char* str){
	
	if (strstr(get_post_title(p), str) != NULL)
		return 1;
	
	else 
		return 0;
}

int tag_in_post(POST p, char* str){

	if(get_post_tags(p)){
		if (strstr(get_post_tags(p), str) != NULL)
			return 1;
		else 
			return 0;
	}
	else
		return 0;
}

void add_questions_to_array(gpointer key, gpointer value, gpointer user_data){
	if(get_post_type(value) == 1){
		long id = get_post_id(value);
		g_array_append_val(user_data, id);
	}
}


