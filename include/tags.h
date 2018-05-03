#ifndef __TAG_H__
#define __TAG_H__
#include "posts.h"

/**\
*@file
*Modulo cria e define uma tag.
*/
typedef struct tag *TAG;

typedef struct TagsFromPost *TAGSPOST;

TAGSPOST create_tagspost();

TAGSPOST get_all_tags(POST p);

char* get_tag_index(TAGSPOST tp, int index);

void free_tagspost(TAGSPOST tp);

/**\ Cria uma Tag. 
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