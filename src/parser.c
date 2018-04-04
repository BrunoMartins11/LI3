#include <libxml/parserInternals.h>
#include <libxml/parser.h>
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

void parse_post(void* user_data, const xmlChar* name, const xmlChar** atributos){

	TAD_community mystruct = (TAD_community) user_data;
	POST newpost;
	long postID;		
	char* postTitle;
	int postType; 		
	long parentID; 		
	long score;
	Date data;
	long answerCount;
	long commentCount;
	char** tags;      
	long ownerID;

	while(atributos != NULL && atributos[0] != NULL){
		if(xmlStrcmp(atributos[0],"Id")==0)
			postID=(long)atributos[1];
		
		if(xmlStrcmp(atributos[0],"PostTypeId")==0)
			postType=(int)atributos[1];
		
		if(xmlStrcmp(atributos[0],"ParentID")==0)//verificar nome do campo
			parentID=(int)atributos[1];
		
		if(xmlStrcmp(atributos[0],"CreationDate")==0)
			data=atributos[1]; //TODO: Parse Date to prof struct
										 //TODO: Passar de xmlChar para os tipos da estrutura Post
		if(xmlStrcmp(atributos[0],"Score")==0)
			score=(long)atributos[1];       //PRECISA STRDUPS NO PARSER???
		
		if(xmlStrcmp(atributos[0],"OwnerUserId")==0)
			ownerID=(long)atributos[1];
		
		if(xmlStrcmp(atributos[0],"Title")==0)
			postTitle=(char*)atributos[1];
		
		if(xmlStrcmp(atributos[0],"Tags")==0)
			tags=atributos[1]; //verificar como fazer isto
		
		if(xmlStrcmp(atributos[0],"AnswerCount")==0)
			answerCount=(long)atributos[1];
		
		if(xmlStrcmp(atributos[0],"CommentCount")==0)
			commentCount=(long)atributos[1];

		atributos += 2; // 0 = atributo, 1 = valor do atributo
	}
	if(postType==1)
		make_post(postID, postTitle, postType, 0, score, data, answerCount, commentCount, tags, ownerID);

	if(postType==2)
		make_post(postID, NULL, postType, parentID, score, data, 0, commentCount, tags, ownerID);

	return; //???
}


TAD_community load(TAD_community mystruct, char* dump_path){

	int n;
	xmlSAXHandler x = {0};
	x.startElement = parse_post;
	char pathfile[80];
	sprintf(pathfile, "%s%s", dump_path, "Posts.xml"); 
	if((n=xmlSAXUserParseFile(&x, mystruct, pathfile))){
		fprintf(stderr, "Load Error %d", n);
		return mystruct;
	}
	return mystruct;
}

