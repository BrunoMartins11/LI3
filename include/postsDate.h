#ifndef __POSTSDATE__
#define __POSTSDATE__

typedef struct postsDate* POSTSDATE;

int date_to_int(Date d);

long* get_id_array(Date d, POSTSDATE p);

#endif