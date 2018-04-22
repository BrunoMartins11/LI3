#ifndef __POSTSDATE__
#define __POSTSDATE__
#include "dArray.h"

typedef struct postsDate* POSTSDATE;

int date_to_int(Date d);

POSTSDATE init_id_matrix();

void insert_id_to_matrix(POSTSDATE p, long id, Date d);

GArray* get_id_array(Date d, POSTSDATE p);

void clean_postsDate(POSTSDATE p);

GArray* posts_id_between_dates(POSTSDATE p, Date a, Date b);

LISTG posts_id_between_dates2(POSTSDATE p, Date a, Date b);

void add_posts_to_matrix(gpointer key, gpointer value, gpointer user_data);

#endif