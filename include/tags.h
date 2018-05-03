#ifndef __TAG_H__
#define __TAG_H__

/**\
*@file
*Modulo cria e define uma tag.
*/

typedef struct tag *TAG;

/**\ @brief Cria uma Tag. 
 *@param name  String que contém a tag
 *@param tagID ID da tag
 *@return      tag
 */
TAG create_tag(char* name, long tagID);

/**\ @brief Retorna o nome de uma tag. 
 *@param t Tag
 *@return nome da tag
 */
char* get_tag_name(TAG t);

/**\ @brief Retorna o ID de uma tag. 
 *@param t Tag
 *@return ID da tag
 */
long  get_tag_id(TAG t);

/**\ @brief Limpa da memória uma Tag. 
 *@param t Apontador para a Tag
 *@return 
 */
void free_tag(void* t);

#endif