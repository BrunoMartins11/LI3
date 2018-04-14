#include <libxml/parserInternals.h>
#include <libxml/parser.h>
#include <stdio.h>
#include <glib.h>
#include <strings.h>
#include "posts.h"
#include "tadCommunity.h"
#include "interface.h"
#include "profile.h"



Date parse_date(char* d){
	
	int dia, mes, ano;
	sscanf( d,"%d-%d-%d", &ano, &mes, &dia);
	return createDate(dia, mes, ano);
}


void parse_user(void* user_data, const xmlChar* name, const xmlChar** atributos){

	PROFILE newuser;
	TAD_community com = (TAD_community) user_data;
	long userID       = 0;		
	char* username    = NULL;
	char* aboutme     = NULL; 		
	long rep          = 0; 	

	while(atributos != NULL && atributos[0] != NULL){
		
		if(xmlStrcmp(atributos[0], (const xmlChar*)"Id")==0)
			userID = strtol((char*)atributos[1], NULL, 10);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"DisplayName")==0)
			username = g_strdup((char*)atributos[1]);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"AboutMe")==0)//verificar nome do campo
			aboutme = g_strdup((char*)atributos[1]);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"Reputation")==0)
			rep = strtol((char*)atributos[1], NULL, 10);

		atributos += 2; // 0 = atributo, 1 = valor do atributo
	}

	newuser = make_profile(userID, 
						   rep, 
						   username, 
						   aboutme);

	add_community_profile(com, userID, newuser);
}



void parse_post(void* user_data, const xmlChar* name, const xmlChar** atributos){

	POST newpost;
	TAD_community com = (TAD_community) user_data;
	long postID       = 0;		
	char* postTitle   = NULL;
	int postType      = 0; 		
	long parentID     = 0; 		
	long score        = 0;
	Date data         = NULL;
	long answerCount  = 0;
	long commentCount = 0;
	char** tags       = malloc(sizeof(char*));      
	tags[0]           = NULL;
	long ownerID      = -2;

	while(atributos != NULL && atributos[0] != NULL){

		if(xmlStrcmp(atributos[0], (const xmlChar*)"Id")==0)
			postID=strtol((char*)atributos[1], NULL, 10);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"PostTypeId")==0)
			postType=atoi((char*)atributos[1]);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"ParentId")==0)//verificar nome do campo
			parentID=atoi((char*)atributos[1]);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"CreationDate")==0)
			data = parse_date((char*)atributos[1]);
										
		if(xmlStrcmp(atributos[0],(const xmlChar*)"Score")==0)
			score=strtol((char*)atributos[1], NULL, 10);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"OwnerUserId")==0)
			ownerID=strtol((char*)atributos[1], NULL, 10);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"Title")==0)
			postTitle=g_strdup((char*)atributos[1]);
		
		//if(xmlStrcmp(atributos[0],(const xmlChar*)"Tags")==0)
		//	tags=atributos[1]; //verificar como fazer isto
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"AnswerCount")==0)
			answerCount=strtol((char*)atributos[1], NULL, 10);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"CommentCount")==0)
			commentCount=strtol((char*)atributos[1], NULL, 10);

		atributos += 2; // 0 = atributo, 1 = valor do atributo
	}


	newpost = make_post(postID, 
						postTitle, 
						postType, 
						parentID, 
						score, 
						data, 
						answerCount, 
						commentCount, 
						tags, 
						ownerID);
	
	add_community_post(com, postID, newpost);
}



TAD_community load(TAD_community com, char* dump_path){

	int n;
	char pathfile[80];

	xmlSAXHandler x = {0};
	
	x.startElement = parse_user;
	
	sprintf(pathfile, "%s%s", dump_path, "Users.xml"); 
	if((n=xmlSAXUserParseFile(&x, com, pathfile))){
		fprintf(stderr, "User Load Error %d", n);
		return com;
	}

	xmlSAXHandler y = {0};
	
	y.startElement = parse_post;
	
	sprintf(pathfile, "%s%s", dump_path, "Posts.xml"); 
	if((n=xmlSAXUserParseFile(&y, com, pathfile))){
		fprintf(stderr, "Post Load Error %d", n);
		return com;
	}

	return com;
}

