#include <stdlib.h>
#include <stdio.h>
#include "tadCommunity.h"


LONG_list both_participated(TAD_community com, long id1, long id2, int N){

	LONG_list l = create_list(N);
	PROFILE p1 = get_community_profile(com, id1);
	PROFILE p2 = get_community_profile(com, id2);
	GArray* userPosts1 = get_profile_user_posts(p1);
	GArray* userPosts2 = get_profile_user_posts(p2);
	int pCount1 = get_profile_post_count(p1);
	int pCount2 = get_profile_post_count(p2);
	int i, j, h;
	long postID;
	POST post;
	h=0;//index que vai adicionar na lista que retorna os ids das perguntas na lista dos profs


	for(i=0; i<pCount1;i++){
		postID = g_array_index(userPosts1, long, i);
		if(get_post_type(get_community_post(com,postID))==1){
			for(j=0; j<pCount2;j++){
				post = get_community_post(com,g_array_index(userPosts2,long, j));
				if(get_post_type(post)==2){
					if(get_post_parentID(post)==postID){
						set_list(l,h,postID);
						h++;
					}
				}
			}
		}
	}

	for(i=0; i<pCount2;i++){
		postID = g_array_index(userPosts2, long, i);
		if(get_post_type(get_community_post(com,postID))==1){
			for(j=0; j<pCount1;j++){
				post = get_community_post(com,g_array_index(userPosts1,long, j));
				if(get_post_type(post)==2){
					if(get_post_parentID(post)==postID){
						set_list(l,h,postID);
						h++;
					}
				}
			}
		}
	}
	for(int t=0; t<N; t++){
		printf("%ld\n", get_list(l,t));
	}

	return l;
}


