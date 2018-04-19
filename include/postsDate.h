#ifndef __POSTSDATE__
#define __POSTSDATE__

typedef struct postsDate* POSTSDATE;

int date_to_int(Date d);

POSTSDATE init_id_matrix();

void insert_id_to_matrix(POSTSDATE p, long id, Date d);

GArray* get_id_array(Date d, POSTSDATE p);

#endif