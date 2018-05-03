#ifndef __POSTSDATE__
#define __POSTSDATE__

/**\
*@file
*Modulo que define funções de comparação.
*/ 

typedef struct postsDate* POSTSDATE;


/**\ @brief Converte uma data num inteiro.  
 *@param d data
 *@return inteiro
 */
int date_to_int(Date d);

/**\ @brief Iniciliza a matriz que contém os IDs dos Posts ordenados por data.  
 *@return matriz que contém o ID dos Posts.
 */
POSTSDATE init_id_matrix();

/**\ @brief Insere um ID de um Posts na posição correta da matrix tendo em conta a sua data.  
 *@param p  matriz onde se vai iserir o ID
 *@param id ID a inserir
 *@param d data do Post
 *@return inteiro
 */
void insert_id_to_matrix(POSTSDATE p, long id, Date d);

/**\ @brief Dada uma data retorna um array que contém os IDs dos Posts publicados naquela data.  
 *@param d Data 
 *@param p Matriz que contém os IDs
 *@return GArray* que contém os IDs dos Posts
 */
GArray* get_id_array(Date d, POSTSDATE p);

/**\ @brief Limpa da memória a matriz. 
 *@param Matriz que contém os IDs dos Posts
 *@return 
 */
void clean_postsDate(POSTSDATE p);

/**\ @brief Retorna os IDs de todos os Posts num intervalo de datas.  
 *@param p Matriz que contém os IDs 
 *@param a Data
 *@param b Data
 *@return GArray* que contém os IDs dos Posts
 */
GArray* posts_id_between_dates(POSTSDATE p, Date a, Date b);

#endif