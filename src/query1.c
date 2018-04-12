#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "interface.h"
#include "profile.h"
#include "posts.h"
#include "tadCommunity.h"



// recebe o apontador calculado na funçao anterior e retorna a string com o nome e titulo do post
STR_pair get_info(POST p){

	long ownerID = get_post_owner(p);
	PROFILE u = get_community_profile(com,ownerID);
	
	if(get_post_title(p) == NULL){
		return create_str_pair(get_profile_name(u), NULL);
	}

	return  create_str_pair(get_profile_name(u), get_title(p));
}

STR_pair info_from_post(TAD_community com, long id){
	
	POST p = get_community_post(com,id);
	
	if(!p) return NULL;
	if (get_post_type(p) == 2){	
		POST po = get_community_post(com, get_post_parentID(p));
		return get_info(po);
	}
	return get_info(p);
} 


