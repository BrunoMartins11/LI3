#ifndef __TAG_H__
#define __TAG_H__

typedef struct tag *TAG;

TAG create_tag(char* name, long tagID);

char* get_tag_name(TAG t);

long  get_tag_id(TAG t);

void free_tag(void* t);

#endif