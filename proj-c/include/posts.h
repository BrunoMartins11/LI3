#ifndef __POSTS_H__
#define __POSTS_H__
#include "date.h"
#include <glib.h>

/**\
*@file
*Modulo que define e cria um Post, retorna as suas componentes e o limpa da memória.
*/ 

typedef struct posts *POST;

/**\ @brief Cria um Post.
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
			   char* tags, 
			   long ownerID);

/**\ @brief Retorna o título de um  Post.
 *@param p Post
 *@return  String que contém o título do Post
 */
char* get_post_title(POST p);

/**\ @brief Adiciona o ID de um Post resposta no array de respostas associado à pergunta 
 *@param p  Post
 *@param id ID do Post
 *@return 
 */
void add_answer(POST p, long id);

/**\ @brief Retorna o GArray que contém os IDs das respostas de uma pergunta.
 *@param p Post
 *@return  GArray que contém os IDs das respostas de uma pergunta.
 */
GArray* get_answers(POST p);

/**\ @brief Retorna o ID de um  Post.
 *@param p Post
 *@return  ID do Post.
 */
long get_post_id(POST p);

/**\ @brief Retorna o tipo de um  Post.
 *@param p Post
 *@return  inteiro referente ao tipo do Post
 */
int get_post_type(POST p);

/**\ @brief Retorna o ID da pergunta a que corresponde o Post resposta.
 *@param p Post
 *@return  ID da pergunta 
 */
long get_post_parentID(POST p);

/**\ @brief Retorna o score de um  Post.
 *@param p Post
 *@return  Score de um Post
 */
long get_post_score(POST p);

/**\ @brief Retorna a data de criação de um  Post.
 *@param p Post
 *@return  Data
 */
Date get_post_date(POST p);

/**\ @brief Retorna o awnserCount de um  Post.
 *@param p Post
 *@return  awnserCount
 */
long get_post_awnser_count(POST p);

/**\ @brief Retorna o commentCount de um  Post.
 *@param p Post
 *@return  commentCount
 */
long get_post_comment_count(POST p);

/**\ @brief Retorna o ID do utilizador criador de um  Post.
 *@param p Post
 *@return  ID de um utilizador
 */
long get_post_owner(POST p);

/**\ @brief Retorna as tags de um  Post.
 *@param p Post
 *@return  Array de strings das tags
 */
char* get_post_tags(POST p);

/**\ @brief Liberta a memória alocada para um Post.
 *@param p Post
 *@return
 */
void free_post(void* p);

/**\ @brief Verifica se a string está no titulo do post.
 *@param p Post
 *@param str string procurada
 *@return 1 se a string está no título do post e 0 se não está
 */
int str_in_postTitle(POST p, char* str);

/**\ @brief Verifica se uma tag está entre as tags do post.
 *@param p Post
 *@param tag tag procurada
 *@return 1 se a tag está nas tags do post e 0 se não está
 */
int tag_in_post(POST p, char* str);

/**\ @brief Adiciona os posts de perguntas a um array.
 *@param key a chave da hashtable
 *@param value o valor da hashtable
 *@param user_data o array
 *@return
 */
void add_questions_to_array(gpointer key, gpointer value, gpointer user_data);

#endif