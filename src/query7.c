#include <glib.h>
#include "interface.h"
#include "posts.h"
#include "tadCommunity.h"
#include "sort.h"
#include "date.h"
#include "postsDate.h"


/**\ @brief Dado um intervalo de tempo arbitrario, devolver as IDs das N perguntas com mais respostas, em ordem decrescente do numero
*@param com    Estrutura global 
*@param N		Número de IDs esperados na lista de retorno
*@param begin  Início do intervalo de tempo
*@param end    Fim do intervalo de tempo
*@return  	 Lista de longs com os IDs das N perguntas com mais respostas, em ordem decrescente
*/

LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end){

	int i, size;
	long id;

	POST p;
	POSTSDATE p_date = get_postsdate(com);
	GArray* questions_post = g_array_new(FALSE, TRUE, sizeof(POST));
	LONG_list ret = create_list(N);

	//Lista de todos os posts entre as datas 
	GArray* id_list_date = posts_id_between_dates(p_date, begin, end);
	size = (int) id_list_date->len;

	//Filtra todos as perguntas entre os posts
	for(i = 0; i < size; i++){

		id = g_array_index(id_list_date, long, i);
		p = get_community_post(com, id);

		if(get_post_type(p) == 1)
			g_array_append_val(questions_post, p);
	}

	//Ordena a lista pelas perguntas com mais repostas
	g_array_sort(questions_post, listG_reverse_sort_answer);
	size = (int) questions_post->len;

	//Preenche a lista de retorno com os N primeiros elementos do array questions_post
	for(i = 0; i < N && i < size; i++){

		p = g_array_index(questions_post, POST, i);
		set_list(ret, i, get_post_id(p));
	}

	return ret;
}