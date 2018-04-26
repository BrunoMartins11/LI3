#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "interface.h"
#include "list.h"
#include "posts.h"
#include "tadCommunity.h"
#include "date.h"
#include "sort.h"

 /**\Devolve uma lista com os IDs de N perguntas cujos tıtulos contenham uma palavra, ordenados por 
   cronologia inversa. 
 *@param com   Estrutura global 
 *@param word  Palavra  procurar 
 *@param N     Top N
 *@return      Lista que contém os IDs dos posts cujos titulos contem a palavra  	  
 */
LONG_list contains_word(TAD_community com, char* word, int N){

	int i, keys_size, index = 0;
	long id;

	POST p;
	LONG_list last_n;

	//Criação da lista, adição de elementos, ordenação e obtenção do tamanho.
	GArray* keys = g_array_new(FALSE, TRUE, sizeof(long));
	iterate_community_posts(com, add_questions_to_array, keys);
	g_array_sort(keys, listG_reverse_sort_id);
	keys_size = (int) keys->len;

	last_n = create_list(keys_size);


	for(i = 0; i < keys_size && index < N; i++){
		
		//elemento da lista no index i
		id = g_array_index(keys, long, i);

		p = get_community_post(com, id);
		
		//retorna true se a palavra word está no título do post
		if(str_in_postTitle(p, word)){

			set_list(last_n, index, get_post_id(p));
			index++;
		}
	}

	return last_n;
}