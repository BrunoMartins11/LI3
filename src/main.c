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
/*
  STR_pair x = info_from_post(com, 801049); 
  free_str_pair(x);
  LONG_list l = top_most_active(com, 10);
  free_list(l);
  USER c = get_user_info(com, 15811);
  free_user(c);
  LONG_list u = both_participated(com, 87, 5691, 10);
  free_list(u);
  //for(int t=0; t<100; t++)
  //  printf("%ld\n", get_list(l,t));
  //STR_pair x = info_from_post(com, 796430); 
  LONG_list a = top_most_active(com, 10);
  free_list(a);
   LONG_list e = both_participated(com, 5, 4, 10);
   free_list(e);
  //for(int t=0; t<10; t++)
  //  printf("%ld\n", get_list(h,t));
  //printf("%s, %s\n", get_fst_str(x),get_snd_str(x));

  Date begin = createDate(1, 11, 2015);
  Date end = createDate(31 , 11, 2015);

  LONG_pair f = total_posts(com, begin, end);
  free_long_pair(f);
  //printf("%ld, %ld\n", get_fst_long(p),get_snd_long(p));
  LONG_list p = most_voted_answers(com, 5, begin, end);
  free_list(p);
  //for(int t=0; t<10; t++)
  //printf("%ld\n", get_list(h,t));
  //long thing = better_answer(com,30334);
  //printf("%ld\n", thing);
  free_date(begin);
  free_date(end);
  */
  clean(com);
 return 0;
} 
