#include <glib.h>
#include "interface.h"
#include "posts.h"
#include "tadCommunity.h"
#include "sort.h"
#include "date.h"
#include "postsDate.h"

/**\Dado um intervalo de tempo arbitrario, devolver os IDs das N respostas com mais votos, 
em ordem decrescente do numero de votos; O nuumero de votos devera ser obtido pela diferença entre 
Up Votes (UpMod6) e Down Votes (DownMod).
*@param com    Estrutura global 
 *@param begin  Início do intervalo de tempo
 *@param end    Fim do intervalo de tempo
 *@param N		Número de IDs esperados na lista de retorno
 *@return  	 Lista de longs com os IDs das N respostas com mais votos, em ordem decrescente
 */
LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end){

	int i, size;
	long id;

	POST p;
	POSTSDATE p_date = get_postsdate(com);
	GArray* answers_post = g_array_new(FALSE, TRUE, sizeof(POST));;
	LONG_list ret = create_list(N);

	//Lista de todos os posts entre as datas 
	GArray* id_list_date = posts_id_between_dates(p_date, begin, end);
	size = (int) id_list_date->len;

	//Filtra todos as respostas entre os posts
	for(i = 0; i < size; i++){

		id = g_array_index(id_list_date, long, i);
		p = get_community_post(com, id);

		if(get_post_type(p) == 2)
			g_array_append_val(answers_post, p);
	}

	//Ordena a lista pelas respostas com mais score
	g_array_sort(answers_post, reverse_sort_score);
	size = (int) answers_post->len;

	//Preenche a lista de retorno com os N primeiros elementos do array answers_post
	for(i = 0; i < N && i < size; i++){

		p = g_array_index(answers_post, POST, i);
		set_list(ret, i, get_post_id(p));
	}

	g_free(g_array_free(answers_post, FALSE));

	return ret;
}