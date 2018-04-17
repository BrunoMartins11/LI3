#ifndef __LISTG_H__
#define __LISTG_H__
#include "par.h"

typedef struct listG *LISTG;

GList* create_listG();

void insert_listG_par(GList* list,PAR p, GCompareFunc func);

PAR get_listG_par(GList* list, guint n);

#endif