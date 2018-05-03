#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "posts.h"
#include "list.h"
#include "profile.h"
#include "tadCommunity.h"

/**\ @brief Procura a melhor resposta a uma pergunta.
 *@param com  Estrutura global 
 *@param id   ID da pergunta
 *@return  	  ID da melhor resposta
 */

long better_answer(TAD_community com, long id){

	GArray* answerArray = get_answers(get_community_post(com,id));
	int  max, value;
	long best = 0;
	POST post;
	max = value = 0;

	for(int i=0; i<answerArray->len; i++){
		post = get_community_post(com,g_array_index(answerArray, long, i));
		value = (get_post_score(post))*0.65 + (get_post_comment_count(post))*0.1 
				+ 0.25*(get_profile_rep(get_community_profile(com, get_post_owner(post))));
		if (max<value){
			max = value;
			best = g_array_index(answerArray, long, i);
		}
	}
	return best;
}
