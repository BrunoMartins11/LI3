#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "posts.h"
#include "list.h"
#include "profile.h"
#include "tadCommunity.h"
#include "par.h"

/**\ @brief Compara os valores do PostCount de dois pares como função de comparação para ordenar o GPtrArray.
 *@param p1  Apontador para o valor a comparar
 *@param p2  Apontador para o elemento do GPtrArray 
 *@return  	 gint resultante da subtração do PostCount dos dois pares
 */
gint fcompare(gconstpointer p1, gconstpointer p2){
	PAR par1 = *((PAR*) p1);
	PAR par2 = *((PAR*) p2);
	return (gint) (get_par_pCount(par2)-get_par_pCount(par1));
}


/**\ @brief Insere no GPtrArray o par que contem o ID do utilizador e o seu respetivo PostCount.
 *@param key   Apontador para a chave do profile
 *@param value Apontador para o profile
 *@param list  Apontador para a estrutura onde vai inserir o par
 *@return  
 */
void insert_pCount_GList_user(gpointer key, gpointer value, gpointer list){
	
	long profileID = get_profile_id((PROFILE)value);
	int pCount = get_profile_post_count((PROFILE)value);

	if(profileID > 0 && pCount > 0){ //verifica se sao NULL
		PAR p = make_new_par(profileID, pCount);// insere no par
		g_ptr_array_add(list, p); //insere na lista
	}
}


/**\ @brief Cria o GPtrArray onde vão ser inseridos os elementos resultantes da função que itera a GHashTable 
	de Profiles.
 *@param com  Estrutura global
 *@param func Função que vai ser aplicada a todos os Profiles
 *@return  	  GPtrArray que contem a informação selecionada
 */
GPtrArray* create_GList_user_pCount(TAD_community com, GHFunc func){

	GPtrArray* array = g_ptr_array_new_with_free_func((GDestroyNotify) free_par);
	iterate_community_users(com, func, array); // itera os users
	g_ptr_array_sort(array, fcompare);
	
	return array;
}


/**\ Procura os N IDs dos utilizadores que mais posts fizeram.
 *@param com   Estrutura global 
 *@param N     Número de utilizadores a retornar
 *@return  	   Lista que contém IDs de utilizadores
 */
LONG_list top_most_active(TAD_community com, int N){
	
	if (N<=0) return NULL;

	LONG_list l = create_list(N);

	int i=0;
	GPtrArray* array = create_GList_user_pCount(com, insert_pCount_GList_user);
	//g_ptr_array_sort(array, (GCompareFunc)fcompare);
	
	while(i<N && i<array->len){
		set_list(l, i, get_par_id(g_ptr_array_index(array, i)));
		printf("%ld\n", get_list( l, i));
		i++;	
	}

	g_ptr_array_free(array,TRUE);

	return l;
}