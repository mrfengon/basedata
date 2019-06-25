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

void save_record_to_file(record *rec, FILE *file) {
    fwrite(rec->surname, sizeof(char), 20, file);
    fwrite(rec->initials, sizeof(char), 5, file);
    fwrite(&(rec->gender), sizeof(char), 1, file);
    fwrite(&(rec->group), sizeof(int), 1, file);
    fwrite(&(rec->discrete), sizeof(int), 1, file);
    fwrite(&(rec->linal), sizeof(int), 1, file);
    fwrite(&(rec->mathan), sizeof(int), 1, file);
    fwrite(&(rec->pml), sizeof(int), 1, file);
    fwrite(&(rec->english), sizeof(bool), 1, file);
    fwrite(&(rec->russian), sizeof(bool), 1, file);
}

record *load_record_from_file(FILE *file) {
    record* rec = (record*) malloc(sizeof(record));

    fread(rec->surname, sizeof(char), 20, file);
    fread(rec->initials, sizeof(char), 5, file);
    fread(&(rec->gender), sizeof(char), 1, file);
    fread(&(rec->group), sizeof(int), 1, file);
    fread(&(rec->discrete), sizeof(int), 1, file);
    fread(&(rec->linal), sizeof(int), 1, file);
    fread(&(rec->mathan), sizeof(int), 1, file);
    fread(&(rec->pml), sizeof(int), 1, file);
    fread(&(rec->english), sizeof(bool), 1, file);
    fread(&(rec->russian), sizeof(bool), 1, file);

    return rec;
}

