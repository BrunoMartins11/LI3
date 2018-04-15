#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "interface.h"
#include "list.h"
#include "posts.h"

// Dado uma palavra, devolver uma lista com os IDs de N perguntas cujos tıtulos a contenham, ordenados por cronologia inversa;

gint fcompare(gconstpointer num_a, gconstpointer num_b){
	return((gint) (*num_b - *num_a));
}

LONG_list contains_word(TAD community com, char* word, int N){

	int i, keys_size, index = 0;
	
	POST p;
	LONG_list last_n;
	GList keys = g_hash_table_get_values(com->posts);
	keys = g_list_sort(keys, (GCompareFunc)fcompare);
	keys_size = (int) g_list_length(keys);
	last_n = create_list(keys_size);

	for(i = 0; i < keys_size && index < N; i++, keys = &(keys->next)){
		
		p = g_hash_table_lookup(com->posts, &(keys->data));
		
		if(get_post_type(p) == 1){
			if(g_strrstr((gchar) get_post_title(p), (gchar) word) != NULL){

				set_list(last_n, index, get_post_id(p));
				index++;
			}
		}
	}

	return last_n;
}




	

 