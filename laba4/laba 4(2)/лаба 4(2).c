#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define COLS 100 

int getNumber() {
    int col;
    while (printf("Введите количество столбцов массива:") && scanf_s("%d", &col) != 1) {
        while (getchar() != '\n');
        printf("Неверное значение, введите другое:\n");
    }
    return col;
}

int getNum() {
    int row;
    while (printf("Введите количество строк массива:") && scanf_s("%d", &row) != 1) {
        while (getchar() != '\n');
        printf("Неверное значение, введите другое:\n");
    }
    return row;
}




int main() {
    setlocale(LC_ALL, "Rus");
    int arr[100][100];
    int i, j;
    int row = getNum(), col = getNumber(), index = 1;
    int choice;

    printf("Вы хотите заполнить массив случайными значениями? (1-нет/2-да): ");
    scanf_s("%d", &choice);
    if (choice == 2) {

        srand(time(0));
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                arr[i][j] = rand() % 81 - 20;



            }
        }

    }

    else {
        printf("Введите %d x %d элементов массива:\n", row, col);
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                printf("arr[%d][%d]: ", i, j);
                scanf_s("%d", &arr[i][j]);
            }
        }
    }
    printf("\nМассив:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int found = 0;
    int nums[100];  
    int nums_count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] < 0) {
                nums[nums_count++] = i;
                printf("\nСтрока %d содержит отрицательный элемент\n", i);
                found = 1;
                
            }
        }
    }

   
    if (found == 1) {
        printf("\nНовый массив:\n");
        double newArr[100][100];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                newArr[i][j] = arr[i][j];
                for (int k = 0; k < nums_count; k++) {
                    if (nums[k] == j) {
                        newArr[i][j] /= 2.0; 
                    }
                }
                printf("%.1f  ", newArr[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Ни одна строка не содержит отрицательных элементов\n");
    }

    return 0;
}