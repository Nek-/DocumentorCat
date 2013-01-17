#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include <wchar.h>
#include "utils.h"


typedef struct {
    String* str;
    StringElement *next;
    char hasNext = 0;
} StringElement;

typedef struct {
    StringElement *first;
    StringElement *last;
    int size = 0;

} StringList;

typedef struct {
    wchar_t* start;
    wchar_t* end;
} Pattern;

typedef struct {
    int start;
    int end;
} BufferRange;


StringList* search(Pattern* m, String* s);

StringList* newStringList();
StringElement* newStringElement(String*);

void addToStringList(StringList*, String*);


#endif // LEXER_H_INCLUDED
