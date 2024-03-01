#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum gender { Male = 1, Female = 2 };
typedef struct person {
    char* name;
    int age;
    enum gender gender;

}person;

void loadFromFile(const char* filename, person** array, char*** file_name, int* size) {
   
    FILE* f = fopen(filename, "r");

    while (!feof(f)) {
        (*size)++;
        *array = realloc(*array, (*size) * sizeof(person));
        *file_name = realloc(*file_name, (*size) * sizeof(char*));
        (*file_name)[*size - 1] = malloc(20 * sizeof(char));


        fscanf(f, "%s", (*file_name)[*size - 1]);
        (*array)[*size - 1].name = (*file_name)[*size - 1];
        fscanf(f, "%d", &(*array)[*size - 1].age);
        int file_gender;
        fscanf(f, "%d", &file_gender);

        switch (file_gender) {
        case 1:
            (*array)[*size - 1].gender = Male;
            break;
        case 2:
            (*array)[*size - 1].gender = Female;
            break;
        default:
            printf("Ошибка: некорректное значение пола.\n");
            fclose(f);
            return;
        }
    }

    fclose(f);
}