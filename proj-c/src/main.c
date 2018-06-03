#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "posts.h"
#include "date.h"
#include "pair.h"
#include "tadCommunity.h"
#include "tags.h"
#include <glib.h>


int main(){

  TAD_community com;
  com = init();
  char *home = getenv("HOME");
  char path[30];
  sprintf(path, "%s%s", home, "/LI3/");
  load(com, path);
  //STR_pair x = info_from_post(com, 9); 
  //LONG_list l = top_most_active(com, 5);
  //USER u = get_user_info(com, 1550);
  //LONG_list h = both_participated(com, 5, 4, 10);
  //for(int t=0; t<10; t++)
  //  printf("%ld\n", get_list(h,t));
  //printf("%s, %s\n", get_fst_str(x),get_snd_str(x));

/*
  POST p = get_community_post(com, 3);
  
  TAGSPOST tp = get_all_tags(p);

  char* tname = get_tag_index(tp, 0);
  //char* tname = "software-center";

  for(int i = 0; get_tag_index(tp, i); i++)
    printf("tag%d: %s\n", i, get_tag_index(tp, i));

  TAG teste = get_community_tag(com, tname);

  printf("tag: %s - ID: %ld\n", tname, get_tag_id(teste));

*/
  POST p;
  Date begin = createDate(1, 11, 2013);
  Date end = createDate(30, 11, 2015);
  Date d;

  //LONG_list l = most_answered_questions(com, 10, begin, end);

  LONG_list best_tags = most_used_best_rep(com, 5, begin, end);

  //LONG_list a = contains_word(com, "install", 10);

  //LONG_list t = questions_with_tag(com, "package-management", begin, end);

  //LONG_list e = most_voted_answers(com, 10, begin, end);

  //LONG_pair r = total_posts(com, begin, end);

  //printf("%s\n", get_post_tags(p));

  //TAGSPOST tp = get_all_tags(p);


  
for(int i = 0; i < 5; i++){
  //printf("tag%d: %s\n", i, get_tag_index(tp, i));

  printf("tag ID: %ld\n", get_list(best_tags, i));  




/*  
    p = get_community_post(com, get_list(t, i));
    d = get_post_date(p);

    printf("ID: %ld - Titulo do post: %s\n", get_post_id(p), get_post_title(p));
    printf("Quantidade de respostas: %ld\n", get_post_awnser_count(p));
    printf("Score da resposta: %ld\n", get_post_score(p));
    printf("Tags: %s\n", get_post_tags(p));
    printf("Data: %d/%d/%d\n\n", get_day(d), get_month(d), get_year(d));
    */
  }

  return 0;
} 
