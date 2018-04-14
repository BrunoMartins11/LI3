#include "tadCommunity.h"

USER get_user_info(TAD_community com, long id){
	
	PROFILE p = get_community_profile(com,id);
	
	return(create_user(get_profile_about(p), (long*)get_profile_user_posts(p)));
}

