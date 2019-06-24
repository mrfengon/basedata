#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "basedata.h"

int main(int argc, char const *argv[]) {
    if (argc < 2)
    {
        printf("Please pass -f to print database or -p to perform query.");
        return 1;
    }

    FILE *database_file;
    record *database[20];
    size_t current_size = 0;
    record* rec;

    if (strcmp(argv[1], "-f") == 0) {
        database_file = fopen("database.bin", "rb");
        while (1) {
            rec = load_record_from_file(database_file);
            if (!feof(database_file)) {
                database[current_size++] = rec;
            } else {
                break;
            }
        }
        fclose(database_file);
        for (size_t i = 0; i < current_size; i++) {
            print_record(database[i]);
        }
    } else if (strcmp(argv[1], "-p") == 0) {
        database_file = fopen("database.bin", "rb");
        while (1) {
            rec = load_record_from_file(database_file);
            if (!feof(database_file)) {
                database[current_size++] = rec;
            } else {
                break;
            }
        }
        fclose(database_file);

        // perform query

    } else {
        printf("Incorrect parameter.");
        return 1;
    }
    
    return 0;
}
