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
  STR_pair x = info_from_post(com, 9); 
  LONG_list l = top_most_active(com, 10);
  
  printf("%s, %s\n", get_fst_str(x),get_snd_str(x));

  return 0;
} 
