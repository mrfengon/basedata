#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "basedata.h"

int main(int argc, char const *argv[])
{
    record* database[20];
    size_t current_size = 0;
    unsigned num;

    char surname[20];
    char initials[5];
    char gender;
    int group;
    int discrete;
    int linal;
    int mathan;
    int pml;
    int english;
    int russian;

    int command;
    while (command != 7) {
        printf(
            "\n0 - print database, 1 - add rec, "
            "2 - delete rec, 3 - print rec, 4 - save database "
            "to file, 5 - load database from file, 6 - show "
            "group with max number of girls with max average, "
            "7 - exit\n"
        );
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            for (size_t i = 0; i < current_size; i++) {
                print_record(database[i]);
            }
            break;
        case 1:
            printf("please input surname: ");
            scanf("%s", surname);
            printf("please input initials: ");
            scanf("%s", initials);
            printf("please input gender: ");
            scanf(" %c", &gender);
            printf("please input group: ");
            scanf("%d", &group);
            printf("please input discrete: ");
            scanf("%d", &discrete);
            printf("please input linal: ");
            scanf("%d", &linal);
            printf("please input mathan: ");
            scanf("%d", &mathan);
            printf("please input pml: ");
            scanf("%d", &pml);
            printf("please input english: ");
            scanf("%d", &english);
            printf("please input russian: ");
            scanf("%d", &russian);
            database[current_size++] = create_record(
                surname, initials, gender, group,
                discrete, linal, mathan,
                pml, english == 1, russian == 1
            );
            break;
        case 2:
            printf("enter num: ");
            scanf("%u", &num);
            if (num < current_size) {
                free(database[num]);
                for (size_t i = num; i < current_size - 1; i++) {
                    database[i] = database[i + 1];
                }
                current_size--;
            } else {
                printf("no such rec\n");
            }
            break;
        case 3:
            printf("enter num: ");
            scanf("%u", &num);
            if (num < current_size) {
                print_record(database[num]);
            } else {
                printf("no such rec\n");
            }
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        }
    }
    return 0;
}