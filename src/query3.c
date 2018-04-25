#include <glib.h>
#include "interface.h"
#include "posts.h"
#include "tadCommunity.h"
#include "sort.h"
#include "date.h"
#include "postsDate.h"


/**\ Dado um intervalo de tempo arbitrário obte o número total de posts
	 (identificando perguntas e respostas separadamente) neste período.
 *@param com    Estrutura global 
 *@param begin  Início do intervalo de tempo
 *@param end    Fim do intervalo de tempo
 *@return  	 Par de longs em que o primeiro é o número de perguntas e o segundo o número de respostas
 */
LONG_pair total_posts(TAD_community com, Date begin, Date end){

	long questions = 0, answer = 0, id;
	int size;
	POST p;

	// Lista dos posts no intervalo de datas
	POSTSDATE p_date = get_postsdate(com);
	GArray* id_list = posts_id_between_dates(p_date, begin, end);
	size = (int) id_list->len;

	//Contabiliza a quantidade de perguntas e respostas
	for(int i = 0; i < size; i++){

		id = g_array_index(id_list, long, i);
		p = get_community_post(com, id);

		if(get_post_type(p) == 1)
			questions++;
		else
			answer++;
	}

	LONG_pair ret = create_long_pair(questions, answer);

	return ret;	
}