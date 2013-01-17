#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <wchar.h>

typedef struct {
    wchar_t* str;
    int length;
} String;

String* newString();
String* newString(int length);
String* newString(wchar_t* str);

void addToString(String* s, String* s2);
void addToString(String* s, wchar_t* s2, int length2);

void printString(String* s);

#endif // UTILS_H_INCLUDED
