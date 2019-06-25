#ifndef BASEDATA_H_
#define BASEDATA_H_

#include <stdbool.h>
#include <stdio.h>

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
void save_record_to_file(record* rec, FILE* file);
record* load_record_from_file(FILE *file);

#endif