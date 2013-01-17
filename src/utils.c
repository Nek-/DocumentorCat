#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "utils.h"
#include "regex.h"


String* newString() {
    String * s = malloc(sizeof(String));
    s->str     = {'\0'};
    s->length  = 0;

    return s;
}
String* newString(wchar_t* str) {
    String s  = malloc(sizeof(String));
    s->str    = str;
    s->length = wcslen(str);

    return s;
}
String* newString(int length) {
    String s  = malloc(sizeof(String));
    s->str    = malloc(sizeof(wchar_t) * (length + 1));
    s->length = length;

    s->str[length] = '\0';

    return s;
}


void addToString(String* s, String* s2) {

    addToString(s, s->str, length2);
}

void addToString(String* s, wchar_t* s2, int length2) {
    wchar_t* tmp = s->str;
    int length   = s->length;

    s->length = s->length + length2;
    s->str = malloc((s->length+1) * sizeof(wchar_t));


    int i;
    for (i=0; i < s->length; i++) {
        if (i < size)
            s->str[i] = tmp[i];
        else
            s->str[i] = s2[i];
    }
    s->str[i+1] = '\0';

    free(tmp);
}

void addToString()

void printString(String* s) {
    wprintf(L"%ls", s->str);
}
