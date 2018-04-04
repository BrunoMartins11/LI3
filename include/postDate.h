#ifndef __POSTDATE__
#define __POSTDATE__

typedef struct postDate* POSTDATE;
POSTDATE create_postDate(Date data, long postID);
Date get_Date(POSTDATE p);
long get_postID_date(POSTDATE p);
void free_postDate();
#endif