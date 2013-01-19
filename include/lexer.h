#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include <wchar.h>
#include "utils.h"

typedef struct StringElement StringElement;
struct StringElement
{
    String* str;
    String* after;
    StringElement* next;
    char hasNext;
    char hasAfter;
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

typedef struct
{
    String* file; // File
    String* fn;   // Function
    char type;    // 0 = file, 1 = function

    String* author;
    String* version;
    String* date;
    String* brief;
    String* details;
    String* fn_argc;
    String* fn_return;
    String* bug;
} DocElement;

StringList* search(Pattern* m, String* s);

// TODO TODO TODO
char searchAndFind(Pattern* m, String* str, String* res);
DocElement* getDocumentation(String* s);


StringList* newStringList();
StringElement* newStringElement(String* s);
Pattern* newPattern(wchar_t* start, wchar_t* end);

void addToStringList(StringList* list, String* s);


void printStringList(StringList* list);


#endif // LEXER_H_INCLUDED
