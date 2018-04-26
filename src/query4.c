#include <glib.h>
#include "interface.h"
#include "posts.h"
#include "tadCommunity.h"
#include "sort.h"
#include "date.h"
#include "postsDate.h"

/**\Dado um intervalo de tempo arbitrario, retornar todas as perguntas contendo uma determinada tag. 
O retorno da funçao deveraa ser uma lista com os IDs das perguntas ordenadas em cronologia inversa.
*@param com    Estrutura global 
*@param tag		A tag procurada
*@param begin  Início do intervalo de tempo
*@param end    Fim do intervalo de tempo
*@return  	 Lista de longs com os IDs das perguntas que contenham a tag procurada, em ordem cronológica inversa
*/
LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end){

    int i, size;
	long id;

	POST p;
	POSTSDATE p_date = get_postsdate(com);
	GArray* posts_with_tag = g_array_new(FALSE, TRUE, sizeof(long));

	//Lista de todos os posts entre as datas 
	GArray* id_list_date = posts_id_between_dates(p_date, begin, end);
	size = (int) id_list_date->len;

    //Filtra todos os posts com a tag passada no argumento da função
	for(i = 0; i < size; i++){

		id = g_array_index(id_list_date, long, i);
		p = get_community_post(com, id);

		if(tag_in_post(p, tag) && get_post_type(p) == 1)
			g_array_append_val(posts_with_tag, id);
	}

    //Ordena a lista em ordem cronológica inversa
	g_array_sort(posts_with_tag, listG_reverse_sort_id);
    size = (int) posts_with_tag->len;

    LONG_list ret = create_list(size);

	//Preenche a lista de retorno com os N primeiros elementos do array posts_with_tag
	for(i = 0; i < size; i++){

		id = g_array_index(posts_with_tag, long, i);
		set_list(ret, i, id);
	}

    g_free(g_array_free(posts_with_tag, FALSE));
    g_free(g_array_free(id_list_date, FALSE));

    return ret;
}