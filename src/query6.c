#include "interface.h"
#include "posts.h"
#include "tadCommunity.h"
#include "dArray.h"
#include "date.h"
#include "postsDate.h"

//Dado um intervalo de tempo arbitrario, devolver os IDs das N respostas com mais votos, 
//em ordem decrescente do numero de votos; O nuumero de votos devera ser obtido pela diferença entre 
//Up Votes (UpMod6) e Down Votes (DownMod).

LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end){

	int i, size;
	long id;

	POST p;
	POSTSDATE p_date = get_postsdate(com);
	LISTG answers_post = create_listG(sizeof(POST));
	LONG_list ret = create_list(N);

	//Lista de todos os posts entre as datas 
	LISTG id_list_date = posts_id_between_dates2(p_date, begin, end);
	size = listG_size(id_list_date);

	//Filtra todos as respostas entre os posts
	for(i = 0; i < size; i++){

		id = get_listG_index(id_list_date, long, i);
		p = get_community_post(com, id);

		if(get_post_type(p) == 2)
			append_listG(answers_post, p);
	}

	//Ordena a lista pelas respostas com mais score
	sort_listG(answers_post, listG_reverse_sort_score);
	size = listG_size(answers_post);

	//Preenche a lista de retorno com os N primeiros elementos do array answers_post
	for(i = 0; i < N && i < size; i++){

		p = get_listG_index(answers_post, POST, i);
		set_list(ret, i, get_post_id(p));
	}

	return ret;
}