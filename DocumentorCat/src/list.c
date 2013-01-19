#include "list.h"

List* newList(char* name, char* path){	
	List* tmp = malloc(sizeof(List));
	if (tmp != NULL){
		strcncpy(char->name,name,MAX_LENGTH);
		strcncpy(char->path,path,MAX_LENGTH);
		tmp->next = NULL;
	}
	else 
		printf("Allocation failed \n");
		
	return tmp;
}
List* add_file(List* l , char* name,char* path){
	List* tmp = newList(char* name, char* path);
	
	if( l == NULL){
		
		l = tmp;
	}
	
	else{
		List* element = l;
		
		while( element->next != NULL){
			
			element = element->next;
		}
	
		element->next = tmp;
	}

	return l;
}

void display (List* l)
{
   

   while (l != NULL)
   {
      
      printf ("%s \t %s \n", l->path,l->name);

      l = l->next;
   }
  
}

int find_file(char *name, List* l){
	
	if ( l == NULL){
		return 0;
	}
	
	while ( l != NULL){
		if ( (strcmp(name,l->name)) || (strcmp(name,l->path)) )
			
			return 1;
	
		else
			l = l->next;
			
	}
	
	return 0;
}	

void freeList(List* l)
{
  	List tmp;

 	 while (*c != NULL)
  	{
		tmp = *c;
		*c = (*c)->next;
		
		if(tmp->name!=NULL)
			free(temp->name);
		
		if(tmp->path!=NULL)
			free(temp->path);
		
		free(temp);
  }
	
}
