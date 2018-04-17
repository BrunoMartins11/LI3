#ifndef __PAR__
#define __PAR__

typedef struct par *PAR;

PAR make_new_par(long id, int index);

long get_par_id(PAR p);

int get_par_pCount(PAR p);

void set_par(long id, int pCount);

void free_par(PAR p);

#endif