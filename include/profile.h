#ifndef __POFILE__
#define __PROFILE__

/**\
*@file
*Modulo que define e cria um Post, retorna as suas componentes e o limpa da memória.
*/

typedef struct profile* PROFILE;

/**\ Cria um Profile.
 *@param id       ID do utilizador
 *@param rep      Reputação do utilizador
 *@param name     Nome do utilizdor
 *@param aboutme  Descrição do utilizador
 *@return  Profile
 */
PROFILE make_profile(long id, long rep, char *name, char *aboutme);

/**\ Retorna o ID de um utilizador.
 *@param p Profile
 *@return  ID de um utilizador
 */
long get_profile_id(PROFILE p);

/**\ Retorna a reputação de um  Utilizador.
 *@param p Profile
 *@return  Reputação do utilizador
 */
long get_profile_rep(PROFILE p);

/**\ Retorna o nome de um utilizador.
 *@param p Profile
 *@return  String que contém o nome do utilizador
 */
char* get_profile_name(PROFILE p);

/**\ Retorna a descrição de um utilizador.
 *@param p Profile
 *@return  String que contém a descrição do utilizador
 */
char* get_profile_about(PROFILE p); 

/**\ Incrementa o PostCount de um utilizador.
 *@param p Profile
 *@return 
 */
void increment_profile_post_count(PROFILE p);

/**\ Retorna o GArray que contém os IDs dos Posts que o utilizador criou.
 *@param p Profile
 *@return  GArray que contém IDs de Posts que o utilizador criou
 */
GArray* get_profile_user_posts(PROFILE p);

/**\ Adiciona um ID de um Post no GArray de Posts que o utilizador criou.
 *@param p  Profile
 *@param id ID do Post a inserir no array
 *@return  
 */
void add_profile_post(PROFILE p, long id);

/**\ Retorna o número de Posts que o utilizador criou.
 *@param p Profile
 *@return  Número de Posts que o utilizador criou
 */
int get_profile_post_count(PROFILE p);

/**\ Liberta a memória alocada para um Profile.
 *@param p Profile
 *@return   
 */
void free_profile(void* p);




#endif
