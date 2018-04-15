#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "interface.h"
#include "profile.h"
#include "posts.h"
#include "tadCommunity.h"



/**\ Procura o nome do utilizador que fez a pergunta e o titulo dela 
 *@param qs  Estrutura global e Post
 *@return  	 Par de strings em que a primeira é o nome do utilizador e a segunda é o titulo da pergunta
 */
STR_pair search_post_info(TAD_community com, POST p){

	long ownerID = get_post_owner(p);
	PROFILE u = get_community_profile(com,ownerID);
	
	if(get_post_title(p) == NULL){
		return create_str_pair(get_profile_name(u), NULL);
	}

	return  create_str_pair(get_profile_name(u), get_post_title(p));
}

/**\ Titulo de uma pergunta e nome do respetivo utilizador que a fez (em caso de ser resposta retornar
a informaçao da pergunta a que responde)
 *@param qs  Estrutura global e ID do post
 *@return  	 Par de strings em que a primeira é o nome do utilizador e a segunda é o titulo da pergunta
 */
STR_pair info_from_post(TAD_community com, long id){
	
	POST p = get_community_post(com,id);
	long ownerID = get_post_owner(p);//testar postCount
	PROFILE u = get_community_profile(com,ownerID);//testar postCount

	if(!p) return NULL;
	if (get_post_type(p) == 2){	
		POST po = get_community_post(com, get_post_parentID(p));
		printf("Post Count: %d\n", get_profile_post_count(u));//testar postCount
		return search_post_info(com,po);
	}
	printf("Post Count: %d\n", get_profile_post_count(u));//testar postCount
	return search_post_info(com,p);
} 


