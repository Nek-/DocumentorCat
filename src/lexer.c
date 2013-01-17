#include "lexer.h"
#include "utils.h"

StringList* search(Pattern* p, String* s) {
    int i, j;
    String* buffer;
    BufferRange range;
    char buffering = 0,
         detecting = 0;
    StringList* list = newStringList();

    for (i = 0; i < s->length; i++) {
        // This condition fully use lazy execution
        if (buffering || detecting > 0 || (s->str[i] == p->start[0])) {

            // Trying to start buffering
            if (!buffering) {
                detecting++;
                if (p->start[detecting] == '\0') {
                    detecting = 0;
                    buffering = 1;

                    // Starting buffer
                    range.start = i - buffering;

                } else if (p->start[detecting] != s->str[i]) {
                    detecting = 0;
                }
            } else {
                // Trying to stop buffering
                if(detecting > 0 || s->str[i] == p->end[0]) {

                    if (p->end[detecting] == '\0') {
                        detecting = 0;
                        buffering = 0;

                        // Saving the buffer in a list
                        range.end = i;

                        buffer = newString(range.end - range.start);
                        for (j = 0; j < buffer->length; j++) {
                            buffer->str[j] = s->str[j+range.start];
                        }

                        addToStringList(list, buffer);

                    } else if (s->str[i] != p->end[detecting]) {
                        detecting = 0;
                    }

                } else {
                    addToString(buffer, s->str[i]);
                }
            }
        }
    }
}

StringList* newStringList() {
    StringList* list = malloc(sizeof(StringList));

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
    se->str = s;
    se->hasNext = 0;

    return se;
}
