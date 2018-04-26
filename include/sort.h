#ifndef __SORT_H__
#define __SORT_H__
#include <glib.h>

/**\
*@file
*Modulo que define funções de comparação.
*/ 

/**\ Compara dois IDs. 
 *@param num_a Apontador para IDa
 *@param num_b Apontador para IDb
 *@return inteiro
 */
int listG_reverse_sort_id(gconstpointer num_a, gconstpointer num_b);

/**\ Compara o numero de respostas de um post com outro. 
 *@param post_1 Apontador para Post1
 *@param post_2 Apontador para Post2
 *@return inteiro
 */
int listG_reverse_sort_answer(gconstpointer post_1, gconstpointer post_2);

/**\ Compara o score de um post om outro. 
 *@param post_1 Apontador para Post1
 *@param post_2 Apontador para Post2
 *@return inteiro
 */
int listG_reverse_sort_score(gconstpointer post_1, gconstpointer post_2);


#endif