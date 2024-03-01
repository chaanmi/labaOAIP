#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void ErrorReturnNull(void* obj, char* error) {
    if (obj == NULL) {
        printf("%s", error);
        exit(EXIT_FAILURE);
    }
}

int getNumber() {
    int num;
    while (scanf_s("%d", &num) != 1) {
        while (getchar() != '\n');
        printf("�������� ��������, ������� ������:\n");
    }
    return num;
}

float getfloatNumber() {
    float number;
    while (scanf_s("%f", &number) != 1) {
        while (getchar() != '\n');
        printf("�������� ��������, ������� ������:\n");
    }
    return number;
}

int getNumSort() {
    int option;
    while ((scanf_s("%d", &option) != 1) || (option != 1 && option != 2 && option != 3 && option != 4)) {
        while (getchar() != '\n');
        printf("���� ������� �������� ��������! ��������� �������.\n");
    }
    return option;
}
