#include <glib.h>
#include <gmodule.h>
#include "interface.h"
#include "list.h"
#include "posts.h"
#include "tadCommunity.h"
#include "date.h"
#include "sort.h"
#include "pair.h"


//Retorna o indice em que o primeiro elemento do par (id) está na list ou -1 caso o par nao esteja na lista
int pair_fst_in_list(GArray* array, long id){

    int i;
    LONG_pair list_pair;

    for(i = 0; i < array->len; i++){

        list_pair = g_array_index(array, LONG_pair, i);
        
        if(get_fst_long(list_pair) == id)
            return i;
    }
    return -1;
}


//Dado um intervalo arbitrario de tempo, devolver os identificadores das N tags mais usadas pelos N  
//utilizadores com melhor reputaçao. Em ordem decrescente do numero de vezes em que a tag foi usada
LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end){

    int i, j, index, size;
	long id;

	POST p;
    PROFILE prof;
    TAGSPOST tp;
    LONG_pair pair;
	POSTSDATE p_date = get_postsdate(com);
    GArray* questions_post = g_array_new(FALSE, TRUE, sizeof(POST));
    GArray* best_users = g_array_new(FALSE, TRUE, sizeof(PROFILE));
	GArray* tags_app = g_array_new(FALSE, TRUE, sizeof(LONG_pair));
	LONG_list ret = create_list(N);

    //Lista ordenada por reputação de todos os utilizadores
    iterate_community_users(com, add_profiles_to_array, best_users);
    g_array_sort(best_users, listG_reverse_sort_rep);

	//Lista de todos os posts entre as datas 
	GArray* id_list_date = posts_id_between_dates(p_date, begin, end);
	size = (int) id_list_date->len;

	//Filtra todos as perguntas, entre as datas, dos N utilizadores com melhor reputação
	for(i = 0; i < size; i++){

		id = g_array_index(id_list_date, long, i);
		p = get_community_post(com, id);

        if(get_post_type(p) == 1){
            for(j = 0; j < N; j++){

                prof = g_array_index(best_users, PROFILE, j);

                if(get_post_owner(p) == get_profile_id(prof))
                    g_array_append_val(questions_post, p);
            }
        }
    }

    g_free(g_array_free(id_list_date, FALSE));
    g_free(g_array_free(best_users, FALSE));

    //Analise as tags de cada post, separa em pares em faz a contagem
    for(i = 0; i < questions_post->len; i++){

        p = g_array_index(questions_post, POST, i);
        tp = get_all_tags(p);

        for(j = 0; get_tag_index(tp, j); j++){

            char* tagname = get_tag_index(tp, j);
            id = get_tag_id(get_community_tag(com, tagname));
            index = pair_fst_in_list(tags_app, id);

            if(index > -1){
                pair = g_array_index(tags_app, LONG_pair, index);
                set_snd_long(pair, get_snd_long(pair) + 1);
            }
            else{
                pair = create_long_pair(id, 0);
                g_array_append_val(tags_app, pair);
            }
        }

        free_tagspost(tp);
    }
        
	//Ordena a lista pelas perguntas com mais repostas
	g_array_sort(tags_app, listG_reverse_sort_pair_snd);
	size = (int) tags_app->len;

    //Preenche a lista de retorno com os N primeiros elementos do array questions_post
	for(i = 0; i < N && i < size; i++){

        pair = g_array_index(tags_app, LONG_pair, i);
		set_list(ret, i, get_fst_long(pair));
	}

    g_free(g_array_free(questions_post, FALSE));
    g_free(g_array_free(tags_app, FALSE));

	return ret;
}