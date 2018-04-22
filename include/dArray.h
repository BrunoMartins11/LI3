#ifndef __LISTG_H__
#define __LISTG_H__
#include "par.h"

#define get_listG_index(array, t, i) (g_array_index(get_GArray(array), t, i))
#define append_listG(array, value) (g_array_append_val(get_GArray(array), value))

typedef struct listG *LISTG;

LISTG create_listG(int size);

void set_listG(LISTG array, GArray* g_array);

void insert_listG_par(LISTG list,PAR p);

PAR get_listG_par(LISTG list, int n);

LISTG sort_listG_par(LISTG array, GCompareFunc func);

GArray* get_GArray(LISTG array);

int listG_size(LISTG array);

void sort_listG(LISTG array, GCompareFunc func);

int listG_reverse_sort(gconstpointer num_a, gconstpointer num_b);



#endif