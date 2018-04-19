#ifndef __LISTG_H__
#define __LISTG_H__
#include "par.h"

typedef struct listG *LISTG;

LISTG create_listG();

void insert_listG_par(LISTG list,PAR p);

PAR get_listG_par(LISTG list, int n);

LISTG sort_listG_par(LISTG list, GCompareFunc func);

#endif