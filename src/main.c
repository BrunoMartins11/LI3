#include "interface.h"
#include <stdio.h>

int main(){
  TAD_community com;
  com = init();
  load(com, "/home/BrunoMartins/LI3/");
  STR_pair x = info_from_post(com, 9); 
  LONG_list l = top_most_active(com,50);

  printf("%s, %s\n", get_fst_str(x),get_snd_str(x));
  return 0;
} 
