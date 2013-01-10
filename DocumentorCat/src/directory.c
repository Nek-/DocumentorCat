#include "directory.h"


int test_file(char* name)
{
	int n = strlen(name);
	
	if((name[n-2] == '.') && ((name[n-1] == 'c') || (name[n-1] == 'h')))
		
		return 0;
	
	return 1;
}

char* Path(char* directory, char* name)
{
	char tmp[1000] = "";
	strncpy(tmp,directory,MAX_LENGTH);
	strcat(tmp,"/");
	return strcat(tmp,name);
}

List* ReadDirectory(char* name, List* l){
	DIR* rep = NULL;
	struct dirent* current;
	
	
	if ( (rep=opendir(name)) == NULL){
		printf("Error\n");
		
		return NULL;
	}
	
	while ((current = readdir(rep)) != NULL){
		struct stat stats; 
		
		if(strcmp(current->d_name, ".") && strcmp(current->d_name, ".."))
		{	
			char* path = Path(name,current->d_name);
    		
    		stat(path, &stats);
           	
           	if(S_ISDIR(stats.st_mode)){
           		
           		char temp[MAX_LENGTH] = "";
           		
           		strncpy(temp,path,MAX_LENGTH);
           		
           		printf("%s \n", temp);
           		
           		l = ReadDirectory(temp,l);
           	}
		
			else {
				if (test_file(current->d_name) == 0){
					
					char temp[MAX_LENGTH] = "";
					
					strncpy(temp,path,MAX_LENGTH);
					
					printf("%s\n", temp);
					
					l = add_file(l,current->d_name,temp);	
				}
			}
		}
		
	}
	closedir(rep);
	
	return l;
}
