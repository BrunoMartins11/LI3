#include <stdlib.h>
#include <stdio.h>
#include "tadCommunity.h"


LONG_list both_participated(TAD_community com, long id1, long id2, int N){

	LONG_list l = create_list(N);
	PROFILE p1 = get_community_profile(com, id1);
	PROFILE p2 = get_community_profile(com, id2);
	GArray* userPosts1 = get_profile_user_posts(p1);
	GArray* userPosts2 = get_profile_user_posts(p2);
	int pCount1 = get_profile_post_count(p1);
	int pCount2 = get_profile_post_count(p2);
	int i, j, h;
	long postID;
	POST post, post1, post2;
	h=0;//index que vai adicionar na lista que retorna os ids das perguntas na lista dos profs

	for(int u=0; u < N; u++)
		set_list(l, u, 0);

	//percorrer o array com os ids de um dos users
	for(i=0; i<pCount1;i++){
		postID = g_array_index(userPosts1, long, i); // vai buscar o id do post naquela posiçao do array
		
		if(get_post_type(get_community_post(com,postID))==1){//verifica se esse post e uma pergunta
			
			for(j=0; j<pCount2;j++){//se for pergunta procura se exite uma resposta do outro user
				post = get_community_post(com,g_array_index(userPosts2,long, j)); //vai buscar o post naquele indice
				
				if(get_post_type(post)==2){//verifica se ele e resposta
					
					if(get_post_parentID(post)==postID){//verifica se o post a que responde é o post inicial do outro user
						set_list(l,h,postID);//se sim insere na lista
						h++;//incrementa o indice da lista 
					}
				}
			}
		}
	}
	//faz a mesma coisa do ciclo anterior so que de forma invertida(começa no outro user)
	for(i=0; i<pCount2;i++){
		postID = g_array_index(userPosts2, long, i);
		
		if(get_post_type(get_community_post(com,postID))==1){
		
			for(j=0; j<pCount1;j++){
				post = get_community_post(com,g_array_index(userPosts1,long, j));
		
				if(get_post_type(post)==2){
		
					if(get_post_parentID(post)==postID){
						set_list(l,h,postID);
						h++;
					}
				}
			}
		}
	}


	/*for(i=0; i < pCount1; i++){
		postID = g_array_index(userPosts1, long, i);
		
		if(get_post_type(get_community_post(com, postID))==2){
			post1 = get_community_post(com, g_array_index(userPosts1,long, i));
			
			for(j=0; j < pCount2; j++){ 
				post2 = get_community_post(com, g_array_index(userPosts2,long, j));

				if((get_post_type(post2) == 2) && (get_post_parentID(post1) == get_post_parentID(post2))){
					set_list(l, h, get_post_parentID(post1));
					h++;
				}
			}
		}
	}
*/
	for(int t=0; t<N; t++)
		printf("%ld\n", get_list(l,t));


	return l;
}

