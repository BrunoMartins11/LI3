#ifndef __PAR__
#define __PAR__

/**\
*@file
*Modulo cria e um par contendo um inteiro e long.
*/

typedef struct par *PAR;

/**\ @brief Dado um ID e e um valor associado a esse id cria um par contendo esses valores.
 *@param id     ID de utilizador ou post e 
 *@param value  Valor que é associado a esse ID
 *@return  	    Par criado
 */
PAR make_new_par(long id, int value);

/**\ @brief Dado um par retorna a sua componente do id.
 *@param p  Par
 *@return  	ID
 */
long get_par_id(PAR p);

/**\ @brief Dado um par retorna a sua componente do valor que armazena.
 *@param p  Par
 *@return  	Valor armazenado
 */
int get_par_pCount(PAR p);

/**\ @brief Limpa o espaço de memoria alocado para um par.
 *@param p  Par
 *@return  	
 */
void free_par(PAR p);

#endif