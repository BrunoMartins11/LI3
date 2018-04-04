#include <stdlib.h>
#include <date.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>
#include "posts.h"
#include "date.h"

struct posts{	//esta struct tem campos de perguntas e respostas, 
						//para que consiga conter ambos, tornando possivel ter perguntas e respostas no mesmo array(por exemplo).	
	long postID;		
	char* postTitle;
	int postType; 		//1 -> pergunta, 2-> resposta.
	long parentID; 		// 0 no caso de ser uma pergunta.
	long score;
	Date data;
	long answerCount;
	long commentCount;
	char** tags;		//basicamente um array de strings. As tags sao strings.
	long ownerID;		//ID do user referente ao post.
	
};

POST make_post(long postID, char* postTitle, int postType, long parentID, long score, Date data, long answerCount, long commentCount, char** tags, long ownerID){
	POST p = malloc(sizeof (struct posts));
	p->postID = postID;	
	p->postTitle = g_strdup(postTitle);
	p->postType = postType; 		
	p->parentID = parentID; 		
	p->score = score;
	p->data = data;
	p->answerCount = answerCount;
	p->commentCount = commentCount;
	for(int i=0; tags[i]; i++) 
		p->tags[i]=g_strdup(tags[i]);
	p->tags = tags;
	p->ownerID = ownerID;
    return p;
}

char* get_title(POST p){
	return g_strdup(p->postTitle);
	
}

long get_postID(POST p){
	return p->postID;
	
}

int get_post_type(POST p){
	return p->postType;
	
}

long get_parentID(POST p){
	return p->parentID;
	
}

long get_score(POST p){
	return p->score;
	
}

Date get_date(POST p){ 
	return p->data;
	
}

long get_awnserC(POST p){
	return p->answerCount;
	
}

long get_commentC(POST p){
	return p->commentCount;
	
}

long get_owner(POST p){
	return p->commentCount;
		
} 

char** get_tags(POST p){ //erraddo compor
	return p->tags;
	
}

void free_post(void* po){
	POST p = (POST)po;
	int i=0;
	if (p){
		if (p->data) free_date(p->data);
		free(p->postTitle);
		while(p->tags[i]){
			free(p->tags[i]);
			i++;
		}
		free(p->tags);
		free(p);
	}
}