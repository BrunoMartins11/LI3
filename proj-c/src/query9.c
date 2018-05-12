#include <stdlib.h>
#include <stdio.h>
#include "tadCommunity.h"

/**\ @brief Verifica se existem elementos repetidos na lista. 
 *@param l         Lista
 *@param list_size Tamanho da Lista 
 *@param n         Elemento que vericamos se está repetido
 *@return          Inteiro  	  
 */
int check_repeat(LONG_list l, int list_size, long n){

	for(int i = 0; i < list_size; i++)
		if(n == get_list(l, i))
			return 1;

	return 0;
}


/**\ @brief Organiza os Ids dos posts por data. 
 *@param com   Estrutura principal
 *@param l     Lista que contém os Ids dos posts 
 *@param order Tipo de ordenação
 *@return      Lista ordenada  
 */
LONG_list organize_by_date(TAD_community com, LONG_list l, int list_size, int order){ 
								//order == 0 -> por ordem crescente de data, do mais antigo para o mais recente
	long temp;					//order == 1 -> por ordem decrescente de data, do mais recente para o mais antigo			

	for(int i = 0; i < list_size-1 && get_list(l, i+1) != 0 ; i++){

		if(order == 0)
			if(date_to_int(get_post_date(get_community_post(com, get_list(l, i)))) > date_to_int(get_post_date(get_community_post(com, get_list(l, i+1))))){
				temp = get_list(l, i);
				set_list(l, i, get_list(l, i+1));
				set_list(l, i+1, temp);
			}
		if(order == 1)
			if(date_to_int(get_post_date(get_community_post(com, get_list(l, i)))) < date_to_int(get_post_date(get_community_post(com, get_list(l, i+1))))){
				temp = get_list(l, i);
				set_list(l, i, get_list(l, i+1));
				set_list(l, i+1, temp);
			}	
	}

	return l;
}

/**\ @brief Verifica se existem posts em que dois utilizadores interagiram. 
 *@param com  Estrutura principal
 *@param id1  Utilizador1 
 *@param id2  Utilizador2
 *@param N    Top N
 *@return  Lista com os N IDs dos posts em que interagiram    	  
 */
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
					
					if(get_post_parentID(post)==postID && check_repeat(l, N, postID)==0){//verifica se o post a que responde é o post inicial do outro user
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
		
					if(get_post_parentID(post)==postID && check_repeat(l, N, postID)==0){
						set_list(l,h,postID);
						h++;
					}
				}
			}
		}
	}


	for(i=0; i < pCount1; i++){
		postID = g_array_index(userPosts1, long, i);
		
		if(get_post_type(get_community_post(com, postID))==2){
			post1 = get_community_post(com, g_array_index(userPosts1,long, i));
			
			for(j=0; j < pCount2; j++){ 
				post2 = get_community_post(com, g_array_index(userPosts2,long, j));

				if((get_post_type(post2) == 2) && (get_post_parentID(post1) == get_post_parentID(post2)) && check_repeat(l, N, get_post_parentID(post1))==0){
					set_list(l, h, get_post_parentID(post1));
					h++;
				}
			}
		}
	}

	return organize_by_date(com, l, N, 1);
}
