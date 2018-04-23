#include "interface.h"
#include "posts.h"
#include "tadCommunity.h"
#include "dArray.h"
#include "date.h"
#include "postsDate.h"

// Dado um intervalo de tempo4 arbitrário, obter o número total de posts (identificando perguntas e respostas separadamente) neste período
LONG_pair total_posts(TAD_community com, Date begin, Date end){

	long questions = 0, answer = 0, id;
	int size;
	POST p;

	// Lista dos posts no intervalo de datas
	POSTSDATE p_date = get_postsdate(com);
	LISTG id_list = posts_id_between_dates2(p_date, begin, end);
	size = listG_size(id_list);

	//Contabiliza a quantidade de perguntas e respostas
	for(int i = 0; i < size; i++){

		id = get_listG_index(id_list, long, i);
		p = get_community_post(com, id);

		if(get_post_type(p) == 1)
			questions++;
		else
			answer++;
	}

	LONG_pair ret = create_long_pair(questions, answer);

	return ret;	
}