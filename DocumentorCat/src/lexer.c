#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "lexer.h"
#include "utils.h"

StringList* search(Pattern* p, String* s) {
    int i, j;
    String* buffer;
    BufferRange range;
    unsigned char buffering = 0,
                  detecting = 0;
    StringList* list = newStringList();

    unsigned char buffering_after = 0,
                  detecting_after = 0;

    for (i = 0; i < s->length; i++) {
        // This condition fully use lazy execution
        if (buffering || detecting > 0 || (s->str[i] == p->start[0])) {

            // Trying to start buffering
            if (!buffering) {

                if (p->start[detecting] == L'\0') {

                    // Starting buffer
                    range.start = i - detecting;

                    detecting = 0;
                    buffering = 1;


                } else if (p->start[detecting] != s->str[i]) {
                    detecting = 0;
                } else {
                    detecting++;
                }
            } else {
                // Trying to stop buffering
                if(detecting > 0 || s->str[i] == p->end[0]) {

                    if (p->end[detecting] == L'\0') {
                        detecting = 0;
                        buffering = 0;

                        // Saving the buffer in a list
                        range.end = i;

                        buffer = newStringFromInt(range.end - range.start);
                        for (j = 0; j < buffer->length; j++) {
                            buffer->str[j] = s->str[j+range.start];
                        }

                        addToStringList(list, buffer);

                        // Starting buffering "after"
                        buffering_after = 1;

                    } else if (s->str[i] != p->end[detecting]) {
                        detecting = 0;
                    } else {
                        detecting++;
                    }

                }
            }
        } else {
            detecting = 0;
        }

        // Getting the prototype of the function
        if(buffering_after) {
            // If it's a new line, detection comes to 0
            if(s->str[i] == L'\n') {
                detecting_after = 0;

            } else if (detecting_after > 4 && s->str[i] == L')') {

                buffering_after = 0;
                list->last->after = newStringFromInt(detecting_after+1);
                int itmp = i - detecting_after;
                for (j=0; j <= detecting_after; j++) {

                    list->last->after->str[j] = s->str[itmp+j];
                }

                list->last->hasAfter = 1;
                detecting_after = 0;

            } else if(s->str[i] == L';') {
                buffering_after = 0;
                detecting_after = 0;
            } else if(detecting_after > 0) {
                detecting_after++;
            } else if(s->str[i] != L' ') {
                detecting_after++;
            }
        }
    }

    return list;
}

StringList* newStringList() {
    StringList* list = malloc(sizeof(StringList));
    list->size = 0;

    return list;
}

void addToStringList(StringList* list, String* s) {
    if (list->size == 0) {
        list->first = newStringElement(s);
        list->last = list->first;
    } else {
        list->last->next = newStringElement(s);
        list->last->hasNext = 1;
        list->last = list->last->next;
    }

    list->size++;
}

StringElement* newStringElement(String* s) {
    StringElement* se = malloc(sizeof(StringElement));
    se->str           = s;
    se->hasNext       = 0;
    se->hasAfter      = 0;

    return se;
}

Pattern* newPattern(wchar_t* start, wchar_t* end) {
    Pattern* p = malloc(sizeof(Pattern));
    p->start   = start;
    p->end     = end;

    return p;
}

char searchAndFind(Pattern* m, String* str) {
    char* res = 0;
    char* post;
	int index =0;
    unsigned char buffering = 0;

        	if( strstr(str,"///") == str)
        		index=3;
        	if( strstr(str,"/**") == str)
        		index=3;
        	if(res=strstr(str,"\\author")){
        		int i = strlen(line);
        		int max = strlen(res);
        		while((res[i]==' ' || res[i]=='\t')&& i<=max)
        			i++;
            	char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&res[i])));
                if(tmp==NULL)
                	exit(EXIT_FAILURE);
                strcpy(tmp,&marker[i]);
        	}
        	if(res=strstr(str,"\\date")){
		    	int i = strlen(line);
		    		int max = strlen(res);
		    		while((res[i]==' ' || res[i]=='\t')&& i<=max)
		    			i++;
		        	char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&res[i])));
		            if(tmp==NULL)
		            	exit(EXIT_FAILURE);
		            strcpy(tmp,&marker[i]);
		    }
        	if(res=strstr(str,"\\version")){
		    	int i = strlen(line);
		    		int max = strlen(res);
		    		while((res[i]==' ' || res[i]=='\t')&& i<=max)
		    			i++;
		        	char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&res[i])));
		            if(tmp==NULL)
		            	exit(EXIT_FAILURE);
		            strcpy(tmp,&marker[i]);
		    }
        	if(res=strstr(str,"\\brief")){
		    	int i = strlen(line);
		    		int max = strlen(res);
		    		while((res[i]==' ' || res[i]=='\t')&& i<=max)
		    			i++;
		        	char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&res[i])));
		            if(tmp==NULL)
		            	exit(EXIT_FAILURE);
		            strcpy(tmp,&marker[i]);
		    }
        	if(res=strstr(str,"\\details")){
		    	int i = strlen(line);
		    		int max = strlen(res);
		    		while((res[i]==' ' || res[i]=='\t')&& i<=max)
		    			i++;
		        	char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&res[i])));
		            if(tmp==NULL)
		            	exit(EXIT_FAILURE);
		            strcpy(tmp,&marker[i]);
		    }
        	if(res=strstr(str,"\\fn")){
		    	int i = strlen(line);
		    		int max = strlen(res);
		    		while((res[i]==' ' || res[i]=='\t')&& i<=max)
		    			i++;
		        	char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&res[i])));
		            if(tmp==NULL)
		            	exit(EXIT_FAILURE);
		            strcpy(tmp,&marker[i]);
		    }
        	if(res=strstr(str,"\\param")){
		    	int i = strlen(line);
		    		int max = strlen(res);
		    		while((res[i]==' ' || res[i]=='\t')&& i<=max)
		    			i++;
		        	char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&res[i])));
		            if(tmp==NULL)
		            	exit(EXIT_FAILURE);
		            strcpy(tmp,&marker[i]);
		    }
        	if(res=strstr(str,"\\return")){
		    	int i = strlen(line);
		    		int max = strlen(res);
		    		while((res[i]==' ' || res[i]=='\t')&& i<=max)
		    			i++;
		        	char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&res[i])));
		            if(tmp==NULL)
		            	exit(EXIT_FAILURE);
		            strcpy(tmp,&marker[i]);
		    }
        	if(res=strstr(str,"\\bug")){
		    	int i = strlen(line);
		    		int max = strlen(res);
		    		while((res[i]==' ' || res[i]=='\t')&& i<=max)
		    			i++;
		        	char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&res[i])));
		            if(tmp==NULL)
		            	exit(EXIT_FAILURE);
		            strcpy(tmp,&marker[i]);
		    }
        	
        	
        }
    }
}

void printStringList(StringList* list) {

    if(list->size > 0) {
        StringElement* e = list->first;
        printString(e->str);
        if(e->hasAfter) {
            printString(e->after);
        }

        while(e->hasNext) {
            e = e->next;
            printString(e->str);
            if(e->hasAfter) {
                printString(e->after);
            }
        }

    }
    wprintf(L"\n");
}
