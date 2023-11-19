#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define COLS 100
#define ROWS 100

int getNum() {
    int row;
    while (printf("Введите значение N:") && scanf_s("%d", &row) != 1) {
        while (getchar() != '\n');
        printf("Неверное значение, введите другое:\n");
    }
    return row;
}


int main() {
    setlocale(LC_ALL, "Rus");
    int i, j;
    int choice = 0;
    int arr[ROWS][COLS];
    int rows= getNum();
    int cols;
    int min;


   
    cols = rows;
    printf("Вы хотите заполнить массив случайными значениями? (1-да/2-нет): ");
    scanf_s("%d", &choice);

    if (choice == 2) {
        printf("Введите %d x %d элементов массива:\n", rows, cols);
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                printf("arr[%d][%d]: ", i, j);
                scanf_s("%d", &arr[i][j]);
            }
        }
    }
    else if (choice == 1) {
        {
            srand(time(0));
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    arr[i][j] = rand() % 90 + 10;
                }
            }
        }
    }



    printf("\nМассив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


    min = arr[rows - 1][cols - 1];
    for (int i = rows - 1; i >= rows / 2; i--) {
        for (int j = cols - 1; j >= cols / 2; j--)
        {
            if (j >= i) {
                if (arr[i][j] < min) {
                    min = arr[i][j];
                }
            }
        }

    }
    for (int i = rows / 2 - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= cols / 2; j--) {
            if (j >= rows - 1 - i) {
                if (arr[i][j] < min) {
                    min = arr[i][j];
                }
            }
        }
    }


    printf("\nМинимальный элемент 2 области:\n");
    printf("%d", min);

    return 0;
}
