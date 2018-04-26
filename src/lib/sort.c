#include <glib.h>
#include "sort.h"
#include "posts.h"

int reverse_sort_id(gconstpointer num_a, gconstpointer num_b){

	long* id_1 = (long*) num_a;
	long* id_2 = (long*) num_b;

	return (int) (*id_2 - *id_1);
}

int reverse_sort_answer(gconstpointer post_1, gconstpointer post_2){
	
	POST* p1 = (POST*) post_1;
	POST* p2 = (POST*) post_2;

	return (int) (get_post_awnser_count(*p2) - get_post_awnser_count(*p1));
}

int reverse_sort_score(gconstpointer post_1, gconstpointer post_2){
	
	POST* p1 = (POST*) post_1;
	POST* p2 = (POST*) post_2;

	if(get_post_score(*p1) > get_post_score(*p2))
		return -1;

	else if(get_post_score(*p2) > get_post_score(*p1))
		return 1;

	else
		return 0;
}