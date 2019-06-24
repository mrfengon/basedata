#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "basedata.h"

record *create_record(char *surname, char *initials,
                      char gender, int group,
                      int discrete, int linal, int mathan,
                      int pml, bool english, bool russian) {
    record* rec = (record*) (malloc(sizeof(record)));
    strcpy(rec->surname, surname);
    strcpy(rec->initials, initials);
    rec->gender = gender;
    rec->group = group;
    rec->discrete = discrete;
    rec->linal = linal;
    rec->mathan = mathan;
    rec->pml = pml;
    rec->english = english;
    rec->russian = russian;
    return rec;
}

void print_record(record *rec) {
    printf(
        "%s\t|\t%s\t| %c | %d | %d | %d | %d | %d | %s | %s\n",
        rec->surname,
        rec->initials,
        rec->gender,
        rec->group,
        rec->discrete,
        rec->linal,
        rec->mathan,
        rec->pml,
        rec->english ? "pass" : "fail",
        rec->russian ? "pass" : "fail"
    );
}