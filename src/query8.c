#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "interface.h"
#include "list.h"
#include "posts.h"
#include "tadCommunity.h"

// Dado uma palavra, devolver uma lista com os IDs de N perguntas cujos tıtulos a contenham, ordenados por cronologia inversa;

long f_compare(long num_a, long num_b){
	return(num_b - num_a);
}

LONG_list contains_word(TAD_community com, char* word, int N){

	int i, keys_size, index = 0;
	long id;
	
	POST p;
	LONG_list last_n;
	dynamic_list* keys = get_all_keys_post(com);
	keys = sort_list(keys, f_compare);
	keys_size = list_size(keys);
	last_n = create_list(keys_size);

	for(i = 0; i < keys_size && index < N; i++, keys = next(keys)){
		
		id = get_data_from_list(keys);
		p = get_community_post(com, id);
		
		if(get_post_type(p) == 1){
			if(str_in_postTitle(p, word)){

				set_list(last_n, index, get_post_id(p));
				index++;
			}
		}
	}

	return last_n;
}
 