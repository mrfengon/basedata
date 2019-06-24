#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "basedata.h"

int main(int argc, char const *argv[])
{
    printf(
        "\n0 - print database, 1 - add rec, 2 - edit rec, "
        "3 - delete rec, 4 - print rec, 5 - save database "
        "to file, 6 - load database from file, 7 - show "
        "group with max number of girls with max average\n"
    );
    int command;
    record* database[20];
    size_t current_size = 0;
    scanf("%d", &command);
    switch (command)
    {
    case 0:
        for (size_t i = 0; i < current_size; i++) {
            print_record(database[i]);
        }
        break;
    case 1:
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
            *surname, *initials, gender, group,
            discrete, linal, mathan,
            pml, english, russian
        );
        break;
    case 2:
        /* code */
        break;
    case 3:
        unsigned num;
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
    case 4:
        unsigned num;
        printf("enter num: ");
        scanf("%u", &num);
        if (num < current_size) {
            print_record(database[num]);
        } else {
            printf("no such rec\n");
        }
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    }
    return 0;
}