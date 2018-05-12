#ifndef __TAG_H__
#define __TAG_H__
#include "posts.h"

/**\
*@file
*Modulo cria e define uma tag.
*/
typedef struct tag *TAG;

typedef struct TagsFromPost *TAGSPOST;

/**\ @brief Cria TAGSPOST. 
 *@return      Estrutura TAGSPOST
 */
TAGSPOST create_tagspost();

/**\ @brief Estrutura TAGSPOST com todas as tags de um post. 
 *@param p Post para analisar as Tags
 *@return Estrutura TAGSPOST
 */
TAGSPOST get_all_tags(POST p);

/**\ @brief Retorna o nome da tag em um determinado índice. 
 *@param tp Estrutura TAGSPOST
 *@param index índice
 *@return nome da tag
 */
char* get_tag_index(TAGSPOST tp, int index);

/**\ @brief Limpa da memória uma TAGSPOST. 
 *@param tp Apontador para a TAGSPOST
 *@return 
 */
void free_tagspost(TAGSPOST tp);

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