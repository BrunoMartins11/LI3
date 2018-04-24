#ifndef __POSTS_H__
#define __POSTS_H__
#include "date.h"

/**\
*@file
*Modulo que define e cria um Post, retorna as suas componentes e o limpa da memória.
*/ 

typedef struct posts *POST;

/**\ Cria um Post.
 *@param postID       ID do Post
 *@param postTitle    Título do Post
 *@param postType     Tipo do Post
 *@param parentID     ID da pergunta a que pertence esta resposta
 *@param score        Score do Post
 *@param data         Data de criação do Post
 *@param answerCount  Número de respostas a uma pergunta
 *@param commentCount Número de comentários de um Post
 *@param tags         Tags de um Post 
 *@param ownerID      ID do utilizador que criou o POST
 *@return  Post
 */
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

/**\ Retorna o título de um  Post.
 *@param p Post
 *@return  String que contém o título do Post
 */
char* get_post_title(POST p);

/**\ Retorna o ID de um  Post.
 *@param p Post
 *@return  ID do Post.
 */
long get_post_id(POST p);

/**\ Retorna o tipo de um  Post.
 *@param p Post
 *@return  inteiro referente ao tipo do Post
 */
int get_post_type(POST p);

/**\ Retorna o ID da pergunta a que corresponde o Post resposta.
 *@param p Post
 *@return  ID da pergunta 
 */
long get_post_parentID(POST p);

/**\ Retorna o score de um  Post.
 *@param p Post
 *@return  Score de um Post
 */
long get_post_score(POST p);

/**\ Retorna a data de criação de um  Post.
 *@param p Post
 *@return  Data
 */
Date get_post_date(POST p);

/**\ Retorna o awnserCount de um  Post.
 *@param p Post
 *@return  awnserCount
 */
long get_post_awnser_count(POST p);

/**\ Retorna o commentCount de um  Post.
 *@param p Post
 *@return  commentCount
 */
long get_post_comment_count(POST p);

/**\ Retorna o ID do utilizador criador de um  Post.
 *@param p Post
 *@return  ID de um utilizador
 */
long get_post_owner(POST p);

/**\ Retorna as tags de um  Post.
 *@param p Post
 *@return  Array de strings das tags
 */
char** get_post_tags(POST p);

/**\ Liberta a memória alocada para um Post.
 *@param p Post
 *@return
 */
void free_post(void* p);

#endif