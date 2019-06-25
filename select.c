#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "basedata.h"

int avg_score(record* rec) {
    return (
        rec->discrete +
        rec->linal +
        rec->mathan +
        rec->pml
    ) / 4;
}

int main(int argc, char const *argv[]) {
    if (argc < 2)
    {
        printf("Please pass -f to print database or -p to perform query.\n");
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

        int max_avg_score = 0;
        for (size_t i = 0; i < current_size; i++)
        {
            int avg = avg_score(database[i]);
            if (avg > max_avg_score) {
                max_avg_score = avg;
            }
        }

        int girls_with_max_avg_by_groups[20] = {
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };
        for (size_t i = 0; i < current_size; i++) {
            if (
                    (database[i]->gender == 'f')
                    &&
                    (avg_score(database[i]) == max_avg_score)
                ) {
                girls_with_max_avg_by_groups[database[i]->group]++;
            }
        }
        
        int resulting_group = 0;
        for (size_t i = 1; i < 20; i++)
        {
            if (girls_with_max_avg_by_groups[i] >
                girls_with_max_avg_by_groups[resulting_group]) {
                resulting_group = i;
            }
        }
        
        printf("Found group: %d\n", resulting_group);

    } else {
        printf("Incorrect parameter.\n");
        return 1;
    }
    
    return 0;
}
