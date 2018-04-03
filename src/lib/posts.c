#include <stdlib.h>
#include <date.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>
#include "posts.h"

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
	POST p = malloc(sizeof posts);
	postID;
	p->postTitle = malloc(sizeof char);		
	p->postTitle = postTitle;
	p->postType = postType; 		
	p->parentID = parentID; 		
	p->score = score;
	p->data = data;
	p->answerCount = answerCount;
	p->commentCount = commentCount;
	p->tags=malloc(sizeof(char)*strlen(tags));//nao sei se esta certo
	while(i<strlen(tags)){
		p->tags[i] = tags[i];
		i++;
	}	
	p->tags = tags;
	p->ownerID = ownerID;
    return p;
}

char* get_title(POST p){
	if(p)
	return p->postTitle;
	return NULL;
}

long get_postID(POST p){
	if (p) return p->postID;
	return NULL;
}

int get_post_type(POST p){
	if(p) return p->postType;
	return NULL;
}

long get_parentID(POST p){
	if(p) return p->parentID;
	return NULL;
}

long get_score(POST p){
	if(p) return p->score;
	return NULL;
}

Date get_date(POST p){ 
	if (p) return p->data;
	return NULL;
}

long get_awnserC(POST p){
	if (p) return p->answerCount;
	return NULL;
}

long get_commentC(POST p){
	if (p) return p->commentCount;
	return NULL;
}

long get_owner(POST p){
	if(p) return p->commentCount;
	return NULL;	
} 

char** get_tags(POST p){
	if (p) return p->tags;
	return NULL;
}

void free_post(POST p){
	if (p){
		free_date(p->data);
		free(p->postTitle);
		while(i<strlen(p->tags)){
			free(p->tags[i]);
			i++;
		}
		free(p->tags);
		free(p);
	}
}