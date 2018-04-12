/*#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "interface.h"
#include "posts.h"
#include "list.h"


LONG_list top_most_active(TAD_community com, int N){
	
	if(N<=0) return NULL;
	int i=0;
	LONG_list l=create_list(N);
	int count[N];
	copy(count, get_top(com,N), N);

	while(N>0){
		set_list(l,i,count[i]);
		i++;
		N--;
	}
	return l;
} 


int get_top(TAD_community com, int N){

	GHashTable* x = get_profile_hash(com);
	int size = (int)g_hash_table_size(com);
	GHashTable table = g_hash_table_new_full( g_int64_hash, g_int64_equal, g_free, g_free);
	
	int p = 1;
	int i = 0;
	POST post;

	for(int f=0; f<size; usercount[f++]=0);
	usercount[get_owner(post)]++;
	
	while(size>i){
		if(g_hash_table_contains(com,&p)) {
			post = (POST)g_hash_table_lookup(com,&p);
			i++; 
		}
		p++;
	}

	return maxIndexArray(usercount, size, N);
}

int maxIndex(int array[], int size){

	int maxI, max;
	max=maxI=0;
	for(int i=0; i<size; i++){
		if(max<array[i]) {maxI=i; max=array[i];}
	}
	array[maxI]=0;

	return maxI;
}

int maxIndexArray(int array[], int size, int N){

	int index[N];

	for(int i=0; N>0; i++){
		index[i]=maxIndex(array,size);
	}

	return index;
}

void copy(int a1[], int a2[], int n){
	for(int i=0; n<i; i++) a1[i]=a2[i];
}
*/