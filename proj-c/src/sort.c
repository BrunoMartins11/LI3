#include <glib.h>
#include "sort.h"
#include "posts.h"
#include "profile.h"
#include "pair.h"
#include "postsDate.h"

int listG_reverse_sort_id(gconstpointer num_a, gconstpointer num_b){

	long* id_1 = (long*) num_a;
	long* id_2 = (long*) num_b;

	return (int) (*id_2 - *id_1);
}

int listG_reverse_sort_answer(gconstpointer post_1, gconstpointer post_2){
	
	POST* p1 = (POST*) post_1;
	POST* p2 = (POST*) post_2;

	return (int) (get_post_awnser_count(*p2) - get_post_awnser_count(*p1));
}

int listG_reverse_sort_score(gconstpointer post_1, gconstpointer post_2){
	
	POST* p1 = (POST*) post_1;
	POST* p2 = (POST*) post_2;

	if(get_post_score(*p1) > get_post_score(*p2))
		return -1;

	else if(get_post_score(*p2) > get_post_score(*p1))
		return 1;

	else
		return 0;
}

int listG_reverse_sort_rep(gconstpointer prf_1, gconstpointer prf_2){
	
	PROFILE* p1 = (PROFILE*) prf_1;
	PROFILE* p2 = (PROFILE*) prf_2;

	if(get_profile_rep(*p1) > get_profile_rep(*p2))
		return -1;

	else if(get_profile_rep(*p2) > get_profile_rep(*p1))
		return 1;

	else
		return 0;
}

int listG_reverse_sort_pair_snd(gconstpointer pair_1, gconstpointer pair_2){
	
	LONG_pair* p1 = (LONG_pair*) pair_1;
	LONG_pair* p2 = (LONG_pair*) pair_2;

	return (int) (get_snd_long(*p2) - get_snd_long(*p1));
}

int listG_reverse_sort_date(gconstpointer post_1, gconstpointer post_2){
	
	POST* p1 = (POST*) post_1;
	POST* p2 = (POST*) post_2;

	return (int) (date_to_int(get_post_date(*p2)) - date_to_int(get_post_date(*p1)));
}
