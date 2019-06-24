#ifndef BASEDATA_H_
#define BASEDATA_H_

#include <stdbool.h>

typedef struct record {
    char surname[20];
    char initials[5];
    char gender;
    int group;
    int discrete;
    int linal;
    int mathan;
    int pml;
    bool english;
    bool russian;
} record;

record* create_record(char *surname, char *initials, char gender, int group,
                      int discrete, int linal, int mathan,
                      int pml, bool english, bool russian);
void print_record(record* rec);

#endif