#include <stdlib.h>
#include <stdio.h>
#include "tadCommunity.h"


/**\ @brief Procura o About Me de um utilizador e os seus respetivos ultimos 10 Posts.  
 *@param com  Estrutura global 
 *@param id   ID do utilizador
 *@return  	  USER que contém About Me e array com os ultimos 10 Posts ordenados por cronologia
 			  inversa
 */
USER get_user_info(TAD_community com, long id){
	
	PROFILE p = get_community_profile(com,id);
	int pcount = get_profile_post_count(p);
	GArray* userPosts = get_profile_user_posts(p);
	long aux[10];
	int i;

	for(i=0; i<get_profile_post_count(p) && i<10; i++){
		aux[i]= g_array_index(userPosts, long, i);
		//printf("%ld\n",aux[i]);
		pcount--;
	}
	if(i<10){
		while(i<10){
			aux[i]=0;
			i++;
			//printf("%ld\n",aux[i]);
		}
	}

	return(create_user(get_profile_about(p), aux));
}
