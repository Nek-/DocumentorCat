#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

typedef struct rep_list{
	char name[MAX_LENGTH];
	char path[MAX_LENGTH];
	struct rep_list* next;

}List;


List* add_file(List* l , char* name,char* path);
void display (List* l);
