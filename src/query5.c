#include <stdlib.h>
#include "tadCommunity.h"

USER get_user_info(TAD_community com, long id){
	
	PROFILE p = get_community_profile(com,id);
	int pcount = get_profile_post_count(p);
	long* userposts = (long*)get_profile_user_posts(p);
	long* aux = malloc(sizeof (long)*pcount);


	for(int i=0; i>get_profile_post_count(p); i++){
		aux[i]=userposts[pcount-1];
		pcount--;
	}

	return(create_user(get_profile_about(p), aux));
}
