#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "work_with_structure.h"

struct person create_person(void) {
    person new_person;

    new_person.name = (char*)malloc(30 * sizeof(char));
    printf("Enter name: ");
    getchar();
    fgets(new_person.name, 30, stdin);
    int i = 0;
    while (new_person.name[i] != '\n' && new_person.name[i] != '\0') {
        i++;
    }
    new_person.name[i] = '\0';
   
    printf("\nEnter age: ");
    new_person.age = getNumber();
    
    int gender = 0;
    printf("\n��� (������� - 1, ������� - 2): ");
    gender = getNumber();
    switch (gender) {
    case 1:
        new_person.gender = Male;
        break;
    case 2:
        new_person.gender = Female;
        break;
    default:
        printf("��������� �������������� ������.");
        break;
    }
    return new_person;
}

void delete_person(person* array, int* size, int delete_number) {
    if (delete_number >= 0 && delete_number < (*size)) {
        for (int i = delete_number; i < (*size) - 1; i++) {
            array[i] = array[i + 1];
        }
        (*size)--;
        array = realloc(array, (*size) * sizeof(person));
        printf("������ ������\n");
    }
    else {
        printf("������� � ����� ������� ���\n");
    }
}

 
void output(person* array, int size) {
    for (int i = 0; i < size; i++) {
        char* gender = "";
        switch (array[i].gender) {
        case 1:
            gender = "�������";
            break;
        case 2:
            gender = "�������";
            break;
        }
        printf("%d. ���: %s, �������: %d, ���: %s.\n", i + 1, array[i].name, array[i].age, gender); 
    }
}