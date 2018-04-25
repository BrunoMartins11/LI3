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

  //STR_pair x = info_from_post(com, 801049); 
  LONG_list l = top_most_active(com, 10);
  //USER u = get_user_info(com, 15811);
  //LONG_list h = both_participated(com, 87, 5691, 10);
  //for(int t=0; t<100; t++)
  //  printf("%ld\n", get_list(l,t));
  //STR_pair x = info_from_post(com, 796430); 
  //LONG_list l = top_most_active(com, 10);
  //USER u = get_user_info(com, 1550);
  //LONG_list h = both_participated(com, 5, 4, 10);
  //for(int t=0; t<10; t++)
  //  printf("%ld\n", get_list(h,t));*/
  //printf("%s, %s\n", get_fst_str(x),get_snd_str(x));

  Date begin = createDate(1, 11, 2015);
  Date end = createDate(31 , 11, 2015);

  //LONG_pair p = total_posts(com, begin, end);
  //printf("%ld, %ld\n", get_fst_long(p),get_snd_long(p));
  //LONG_list h = most_voted_answers(com, 5, begin, end);
  //for(int t=0; t<10; t++)
  //printf("%ld\n", get_list(h,t));
  //long thing = better_answer(com,30334);
  //printf("%ld\n", thing);
  clean(com);
 return 0;
} 
