#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <wchar.h>

typedef struct {
    wchar_t* str;
    int length;
} String;

String* newString();
String* newStringFromInt(int length);
String* newStringFromWchar(wchar_t* str);

void addStringToString(String* base, String* addition);
void addWcharToString(String* s, wchar_t* s2, int length2);

void printString(String* s);

#endif // UTILS_H_INCLUDED
