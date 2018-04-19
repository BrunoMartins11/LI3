#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "interface.h"
#include "list.h"
#include "posts.h"
#include "tadCommunity.h"
#include "dArray.h"

// Dado uma palavra, devolver uma lista com os IDs de N perguntas cujos tıtulos a contenham, ordenados por cronologia inversa;

LONG_list contains_word(TAD_community com, char* word, int N){

	int i, keys_size, index = 0;
	long id;

	POST p;
	LONG_list last_n;
	LISTG keys = create_listG(sizeof(long));
	iterate_community_posts(com, add_questions_to_array, keys);
	sort_listG(keys, listG_reverse_sort);
	keys_size = listG_size(keys);
	last_n = create_list(keys_size);


	for(i = 0; i < keys_size && index < N; i++){
		
		id = get_listG_index(keys, long, i);
		p = get_community_post(com, id);
		
		if(str_in_postTitle(p, word)){

			set_list(last_n, index, get_post_id(p));
			index++;
		}
	}

	return last_n;
}