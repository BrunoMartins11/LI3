#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "interface.h"

STR_pair pair_info_from_post(TAD_community com, int id); //função que vai ser executada no interface

// retorna o apontador do post que procuramos
gpointer get_post(int IDp){
	gconstpointer IDaux = IDp;
	guint hash = g_direct_hash(IDaux);
	if (g_hash_table_contains(aDefinir, hash)){
		return	g_hash_table_lookup(aDefinir, hash)
	}
	return NULL;
}

// recebe o apontador calculado na funçao anterior e retorna a string com o nome e titulo do post
STR_pair get_info(int IDp){

	gpointer pIDp = get_post(IDp);  
	if (pIDp -> postType == 2){
		 pIDP = get_post(pIDp -> parentID);
	}
	return create_str_pair(pIDp->name, pIDp->title);
}



