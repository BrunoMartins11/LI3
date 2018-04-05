#include <libxml/parserInternals.h>
#include <libxml/parser.h>
#include <glib.h>
#include "posts.h"
#include "hashTableLoad.h"
#include "interface.h"

//PostID
//PostTitle
//UserName
//Em caso de resposta, retornar titulo e user da pergunta correspondente
//Numero de posts dos users(perguntas ou respostas)
//Data
//PostTypeID
//UserBio
//Numero de respostas de uma pergunta
//Score da resposta
//User reputationTCD_community * TAD_community;
//Numero de comentarios das respostas
//Tags, e numero de vezes que cada uma e usada.

Date parse_date(char* d){
	
	int dia, mes, ano;
	sscanf( d,"%d-%d-%d", &ano, &mes, &dia);
	return createDate(dia, mes, ano);
}



void parse_post(void* user_data, const xmlChar* name, const xmlChar** atributos){

	TAD_community com = (TAD_community) user_data;
	POST newpost;
	long postID = 0;		
	char* postTitle= NULL;
	int postType = 0; 		
	long parentID = 0; 		
	long score = 0;
	Date data = NULL;
	long answerCount = 0;
	long commentCount = 0;
	char** tags = malloc(sizeof(char*));      
	tags[0] = NULL;
	long ownerID = -2;
	char* ptrtol = NULL;

	while(atributos != NULL && atributos[0] != NULL){
		
		if(xmlStrcmp(atributos[0], (const xmlChar*)"Id")==0)
			postID=strtol((char*)atributos[1], &ptrtol, 10);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"PostTypeId")==0)
			postType=atoi((char*)atributos[1]);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"ParentID")==0)//verificar nome do campo
			parentID=atoi((char*)atributos[1]);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"CreationDate")==0)
			data = parse_date((char*)atributos[1]);
										
		if(xmlStrcmp(atributos[0],(const xmlChar*)"Score")==0)
			score=strtol((char*)atributos[1], &ptrtol, 10);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"OwnerUserId")==0)
			ownerID=strtol((char*)atributos[1], &ptrtol, 10);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"Title")==0)
			postTitle=g_strdup((char*)atributos[1]);
		
		//if(xmlStrcmp(atributos[0],(const xmlChar*)"Tags")==0)
		//	tags=atributos[1]; //verificar como fazer isto
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"AnswerCount")==0)
			answerCount=strtol((char*)atributos[1], &ptrtol, 10);
		
		if(xmlStrcmp(atributos[0],(const xmlChar*)"CommentCount")==0)
			commentCount=strtol((char*)atributos[1], &ptrtol, 10);

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
	long* id = malloc(sizeof(long));
	*id = get_postID(newpost);

	g_hash_table_insert(get_posts_hash(com), id, newpost);
}


TAD_community load(TAD_community com, char* dump_path){

	int n;
	xmlSAXHandler x = {0};
	x.startElement = parse_post;
	char pathfile[80];
	sprintf(pathfile, "%s%s", dump_path, "Posts.xml"); 
	if((n=xmlSAXUserParseFile(&x, com, pathfile))){
		fprintf(stderr, "Load Error %d", n);
		return com;
	}
	return com;
}

