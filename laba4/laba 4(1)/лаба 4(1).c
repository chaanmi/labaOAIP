#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define MAX_ROWS 100
#define MAX_COLS 100

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


int getRowSum(int arr[MAX_ROWS][MAX_COLS], int row, int col) {
    int sum = 0;
    for (int j = 0; j < col; j++) {
        if (arr[row][j] > 0 && arr[row][j] % 2 == 0) {
            sum += arr[row][j];
        }
    }
    return sum;
}


void swapRows(int arr[MAX_ROWS][MAX_COLS], int row1, int row2, int col) {
    for (int j = 0; j < col; j++) {
        int temp = arr[row1][j];
        arr[row1][j] = arr[row2][j];
        arr[row2][j] = temp;
    }
}


void sortRows(int arr[MAX_ROWS][MAX_COLS], int row, int col) {
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < row - i - 1; j++) {
            if (getRowSum(arr, j, col) > getRowSum(arr, j + 1, col)) {
                swapRows(arr, j, j + 1, col);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int arr[MAX_ROWS][MAX_COLS];
    int row = getNum(), col = getNumber();
    int choice;

    printf("Вы хотите заполнить массив случайными значениями? (1-нет/2-да): ");
    scanf_s("%d", &choice);

    if (choice == 2) {
        srand(time(0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = rand() % 81-20;
            }
        }
    }
    else {
        printf("Введите %d x %d элементов массива:\n", row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
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

    sortRows(arr, row, col);


    printf("\nНовый массив:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

