#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "tags.h"
#include "posts.h"

struct tag{
	char* name;
	long  tagID;
};

struct TagsFromPost{
	char* tag0;
	char* tag1;
	char* tag2;
	char* tag3;
	char* tag4;
};

TAGSPOST create_tagspost(){
  TAGSPOST tp = malloc(5*sizeof(TAGSPOST));

  tp->tag0 = g_strdup('\0');
  tp->tag1 = g_strdup('\0');
  tp->tag2 = g_strdup('\0');
  tp->tag3 = g_strdup('\0');
  tp->tag4 = g_strdup('\0');

  return tp;
}

TAGSPOST get_all_tags(POST p){
  char* t = get_post_tags(p);
  char temp[30];
  int i;
  int j = 0;

  TAGSPOST tp = create_tagspost();
  
  for(i = 0; t[i]; i++){
      if(t[i] == '<');
      
      else if(t[i] == '>'){
        temp[j] = '\0';
        tp->tag0 = g_strdup(temp);
        memset(temp, 0, sizeof(temp));
        j = 0;
        break;
        }

      else{
        temp[j] = t[i];
        j++;
      }
    }

    for(i += 1; t[i]; i++){
      if(t[i] == '<');
      
      else if(t[i] == '>'){
        temp[j] = '\0';
        tp->tag1 = g_strdup(temp);
        memset(temp, 0, sizeof(temp));
        j = 0;
        break;
        }

      else{
        temp[j] = t[i];
        j++;
      }
    }

    for(i += 1; t[i]; i++){
      if(t[i] == '<');
      
      else if(t[i] == '>'){
        temp[j] = '\0';
        tp->tag2 = g_strdup(temp);
        memset(temp, 0, sizeof(temp));
        j = 0;
        break;
        }

      else{
        temp[j] = t[i];
        j++;
      }
    }

    for(i += 1; t[i]; i++){
      if(t[i] == '<');
      
      else if(t[i] == '>'){
        temp[j] = '\0';
        tp->tag3 = g_strdup(temp);
        memset(temp, 0, sizeof(temp));
        j = 0;
        break;
        }

      else{
        temp[j] = t[i];
        j++;
      }
    }

    for(i += 1; t[i]; i++){
      if(t[i] == '<');
      
      else if(t[i] == '>'){
        temp[j] = '\0';
        tp->tag4 = g_strdup(temp);
        memset(temp, 0, sizeof(temp));
        j = 0;
        break;
        }

      else{
        temp[j] = t[i];
        j++;
      }
    }

    return tp;
}

char* get_tag_index(TAGSPOST tp, int index){
  
  switch(index){
    case 0 :
      if(tp->tag0)
        return g_strdup(tp->tag0);
      else
        return NULL;

    case 1 :
      if(tp->tag1)
        return g_strdup(tp->tag1);
      else
        return NULL;

    case 2 :
      if(tp->tag2)
        return g_strdup(tp->tag2);
      else
        return NULL;

    case 3 :
      if(tp->tag3)
        return g_strdup(tp->tag3);
      else
        return NULL;

    case 4 :
      if(tp->tag4)
        return g_strdup(tp->tag4);
      else
        return NULL;
      
    default :
      return NULL;
  }
}

void free_tagspost(TAGSPOST tp){
  g_free(tp->tag0);
  g_free(tp->tag1);
  g_free(tp->tag2);
  g_free(tp->tag3);
  g_free(tp->tag4);
  free(tp);
}


TAG create_tag(char* name, long tagID){
	TAG t = malloc(sizeof(struct tag));
	t->name = g_strdup(name);
	t->tagID = tagID;
	return t;
}

char* get_tag_name(TAG t){
	return g_strdup(t->name);
}

long get_tag_id(TAG t){
	return t->tagID;
}

void free_tag(void* ta){
	TAG t = (TAG)ta;
	free(t->name);
	free(t);
}