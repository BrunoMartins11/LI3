#include <stdlib.h>
#include <stdio.h>
#include "tadCommunity.h"

USER get_user_info(TAD_community com, long id){
	
	PROFILE p = get_community_profile(com,id);
	int pcount = get_profile_post_count(p);
	GArray* userPosts = get_profile_user_posts(p);
	long* aux = malloc(sizeof (long)*10);
	int i;

	for(i=0; i<get_profile_post_count(p) && i<10; i++){
		aux[i]= g_array_index(userPosts, long, i);
		printf("%ld\n",aux[i]);
		pcount--;
	}
	if(i<10){
		while(i<10){
			aux[i]=0;
			i++;
			printf("%ld\n",aux[i]);
		}
	}

	return(create_user(get_profile_about(p), aux));
}
