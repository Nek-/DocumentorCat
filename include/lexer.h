#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include <wchar.h>
#include "utils.h"

typedef struct StringElement StringElement;
struct StringElement
{
    String* str;
    StringElement* next;
    char hasNext;
};

typedef struct
{
    StringElement *first;
    StringElement *last;
    int size;

} StringList;

typedef struct
{
    wchar_t* start;
    wchar_t* end;
} Pattern;

typedef struct
{
    int start;
    int end;
} BufferRange;


StringList* search(Pattern* m, String* s);

StringList* newStringList();
StringElement* newStringElement(String* s);
Pattern* newPattern(wchar_t* start, wchar_t* end);

void addToStringList(StringList* list, String* s);


void printStringList(StringList* list);


#endif // LEXER_H_INCLUDED
