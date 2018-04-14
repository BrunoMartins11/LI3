#include "interface.h"
#include <stdio.h>

int main(){
  TAD_community com;
  com = init();
  load(com, "/home/dunnadan/Work/");
  STR_pair x = info_from_post(com, 2); 
  printf("%s, %s\n", get_fst_str(x),get_snd_str(x));
  return 0;
} 
