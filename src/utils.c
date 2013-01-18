#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "utils.h"
#include "regex.h"


String* newString() {
    String* s = malloc(sizeof(String));
    s->str    = malloc(sizeof(wchar_t));
    s->str[0] = L'\0';
    s->length = 0;

    return s;
}

String* newStringFromWchar(wchar_t* str) {
    String* s = malloc(sizeof(String));
    s->str    = str;
    s->length = wcslen(str);

    return s;
}

String* newStringFromInt(int length) {
    String* s = malloc(sizeof(String));
    s->str    = malloc(sizeof(wchar_t) * (length + 1));
    s->length = length;

    s->str[length] = '\0';

    return s;
}


void addStringToString(String* base, String* addition) {

    addWcharToString(base, addition->str, addition->length);
}

void addWcharToString(String* base, wchar_t* addition, int addition_length) {
    wchar_t* tmp = base->str;
    int length   = base->length;

    base->length = base->length + addition_length;
    base->str = malloc((base->length+1) * sizeof(wchar_t));


    int i;
    for (i=0; i < base->length; i++) {
        if (i < length)
            base->str[i] = tmp[i];
        else
            base->str[i] = addition[i];
    }
    base->str[i+1] = '\0';

    free(tmp);
}


void printString(String* s) {
    wprintf(L"%ls", s->str);
}
