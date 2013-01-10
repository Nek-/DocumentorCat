#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>   
#include <sys/types.h>
#include <sys/stat.h>

char* Path(char* directory, char* name);
List* ReadDirectory(char* name, List* l);
