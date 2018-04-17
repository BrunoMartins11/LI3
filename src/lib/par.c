#include <stdlib.h>
#include "par.h"

struct par {
	long id;
	int pCount;
};

PAR make_new_par(long id, int pCount){
	
	PAR p = malloc(sizeof(struct par));
	p->id=id;
	p->pCount=pCount;

	return p;

}

long get_par_id(PAR p){
	return p->id;
}

int get_par_pCount(PAR p){
	return p->pCount;
}


void free_par(PAR p){
	free(p);
}