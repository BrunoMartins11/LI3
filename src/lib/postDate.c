#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#include "postDate.h"


struct postDate{
	Date data;
	long postID;
};

POSTDATE create_postDate(Date data, long postID){
	POSTDATE p = malloc(sizeof(struct postDate));
	p->data = data;
	p->postID = postID;
	return p;
}

Date get_Date(POSTDATE p){
	return p->data;
}

long get_postID_date(POSTDATE p){
	return p->postID;
}

void free_postDate(POSTDATE p){	
	free_date(p->data);

}