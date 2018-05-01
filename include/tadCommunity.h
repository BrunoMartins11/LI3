#ifndef __TADCOMMUNITY_H__
#define __TADCOMMUNITY_H__
#include <glib.h>
#include "interface.h"
#include "date.h"
#include "postDate.h"
#include "profile.h"
#include "posts.h"
#include "tags.h"
#include "postsDate.h"

/**\
*@file
*Modulo que define e cria a estrutura principal, cria e retorna elementos das suas componentes 
 e a limpa da memória.
*/ 

typedef struct _dynamic_list dynamic_list;

/**\ Encontra na GHashTable de posts o Post requerido.
 *@param m  Estrutura principal
 *@param id ID do Post
 *@return   Post
 */
POST get_community_post(TAD_community m, long id);

/**\ Encontra na GHashTable dos profiles o utilizador requrido.
 *@param m  Estrutura principal
 *@param id ID do utilizador
 *@return  Profile
 */
PROFILE get_community_profile(TAD_community m, long id);

/**\ Limpa da memória a estrutura principal.
 *@param m Estrutura principal
 *@return  
 */
void clean_hash_table(TAD_community m);

/**\ Cria a estrutura principal.
 *@param 
 *@return Estrutura principal
 */
TAD_community create_struct();

/**\ Adiciona um Post à GHashTable dos posts da estrutura principal.
 *@param m  Estrutura principal
 *@param id ID do post
 *@param p  Post que vai ser inserido
 *@return  
 */
void add_community_post(TAD_community m, long id, POST p);

/**\ Adiciona um Profile à GHashTable dos profiles da estrutura principal.
 *@param m  Estrutura principal
 *@param id ID do utilizador
 *@param p  Profile que vai ser inserido
 *@return  
 */
void add_community_profile(TAD_community m, long id, PROFILE p);

/**\ Retorna uma TAG da GHashTable das Tags.
 *@param m  Estrutura principal
 *@param id String(conteudo da tag)
 *@return   tag
 */
TAG get_community_tag(TAD_community m, char* id);

/**\ Adiciona uma Tag à GHashTable das tags da estrutura principal.
 *@param m  Estrutura principal
 *@param id ID da tag
 *@param t  Tag que vai ser inserida
 *@return  
 */
void add_community_tag(TAD_community m, char* name, TAG t);

/**\ Itera a GHashTable dos Profiles aplicando uma função a cada elemento guardando o resultado
	 numa estrutura externa.
 *@param m    Estrutura principal
 *@param func Função que é aplicada a todos os elementos da GHashTable
 *@param data Estrutura onde vai ser armazenado o resultado
 *@return  
 */
void iterate_community_users(TAD_community m, GHFunc func, gpointer data);

/**\ Verifica se uma string está presente num titulo de um Post.
 *@param p   Post
 *@param str String
 *@return    inteiro  
 */
int str_in_postTitle(POST p, char* str);

/**\ Itera a GHashTable dos Posts aplicando uma função a cada elemento guardando o resultado
	 numa estrutura externa.
 *@param m    Estrutura principal
 *@param func Função que é aplicada a todos os elementos da GHashTable
 *@param data Estrutura onde vai ser armazenado o resultado
 *@return  
 */
void iterate_community_posts(TAD_community m, GHFunc func, gpointer data);


/**\ Retorna a estrutura onde estão guardados os ids de posts ordenados por data.
 *@param m  Estrutura principal
 *@return   PostsDate
 */
POSTSDATE get_postsdate(TAD_community m);

#endif