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
//Vote number = UpVotes - DownVotes = Score
//Numero de respostas de uma pergunta
//Score da resposta
//User reputation
//Numero de comentarios das respostas
//Tags, e numero de vezes que cada uma e usada.

void parse_post(void* user_data, const xmlChar* name, const xmlChar** atributos){

	TAD_community com = (TAD_community) user_data;

	while(atributos != NULL && atributos[0] != NULL){
		
		atributos += 2; // 0 = atributo, 1 = valor do atributo
	}
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

