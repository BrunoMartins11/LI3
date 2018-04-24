#include "interface.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

  TAD_community com;
  com = init();
  char *home = getenv("HOME");
  char path[30];
  sprintf(path, "%s%s", home, "/LI3/");
  load(com, path);
  //STR_pair x = info_from_post(com, 796430); 
  //LONG_list l = top_most_active(com, 10);
  //USER u = get_user_info(com, 1550);
  //LONG_list h = both_participated(com, 5, 4, 10);
  //for(int t=0; t<10; t++)
  //  printf("%ld\n", get_list(h,t));*/
  //printf("%s, %s\n", get_fst_str(x),get_snd_str(x));

  Date begin = createDate(1, 1, 2008);
  Date end = createDate(23 , 4, 2012);

  LONG_pair p = total_posts(com, begin, end);

  //LONG_list h = both_participated(com, 7, 21, 5);
  //for(int t=0; t<10; t++)
  //  printf("%ld\n", get_list(h,t));
  //long thing = better_answer(com,3883);
  //printf("%ld\n", thing);
  //clean(com);
  return 0;
} 
