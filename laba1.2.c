#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "work_with_structure.h"
#include "check_errors.h"
#include "sort.h"
#include "parce.h"
#include "menu.h"

//enum gender { Male = 1, Female = 2 };
//
//typedef struct person {
//    char* name;
//    int age;
//    enum gender gender;
//}person;
//
//int getNumber() {
//    int num;
//    while (scanf_s("%d", &num) != 1) {
//        while (getchar() != '\n');
//        printf("Неверное значение, введите другое:\n");
//    }
//    return num;
//}
//
//float getfloatNumber() {
//    float number;
//    while (scanf_s("%f", &number) != 1) {
//        while (getchar() != '\n');
//        printf("Неверное значение, введите другое:\n");
//    }
//    return number;
//}
//
//int getNumSort() {
//    int option;
//    while ((scanf_s("%d", &option) != 1) || (option != 1 && option != 2 && option != 3 && option != 4)) {
//        while (getchar() != '\n');
//        printf("Было введено неверное значение! Повторите попытку.\n");
//    }
//    return option;
//}
//
//void ErrorReturnNull(void* obj, char* error) {
//    if (obj == NULL) {
//        printf("%s", error);
//        exit(EXIT_FAILURE);
//    }
//}
//
//struct person create_person(void) {
//    person new_person;
//
//    new_person.name = (char*)malloc(30 * sizeof(char));
//    printf("Enter name: ");
//    getchar();
//    fgets(new_person.name, 30, stdin);
//    int i = 0;
//    while (new_person.name[i] != '\n' && new_person.name[i] != '\0') {
//        i++;
//    }
//    new_person.name[i] = '\0';
//   
//    printf("\nEnter age: ");
//    new_person.age = getNumber();
//    
//    int gender = 0;
//    printf("\nПол (мужской - 1, женский - 2): ");
//    gender = getNumber();
//    switch (gender) {
//    case 1:
//        new_person.gender = Male;
//        break;
//    case 2:
//        new_person.gender = Female;
//        break;
//    default:
//        printf("Произошла непредвиденная ошибка.");
//        break;
//    }
//    return new_person;
//}
//
//void delete_person(person* array, int* size, int delete_number) {
//    if (delete_number >= 0 && delete_number < (*size)) {
//        for (int i = delete_number; i < (*size) - 1; i++) {
//            array[i] = array[i + 1];
//        }
//        (*size)--;
//        array = realloc(array, (*size) * sizeof(person));
//        printf("Объект удален\n");
//    }
//    else {
//        printf("Объекта с таким номером нет\n");
//    }
//}
//
// 
//void output(person* array, int size) {
//    for (int i = 0; i < size; i++) {
//        char* gender = "";
//        switch (array[i].gender) {
//        case 1:
//            gender = "мужской";
//            break;
//        case 2:
//            gender = "женский";
//            break;
//        }
//        printf("%d. Имя: %s, возраст: %d, пол: %s.\n", i + 1, array[i].name, array[i].age, gender); 
//    }
//}
//
//void quick_sort(person* array, float** data, int size, int left, int right, int s) {
//    int i = left, j = right;
//    float test = data[s][(left + right) / 2];
//    float temp = 0;
//    person temporary;
//    do {
//        while (data[s][i] < test)
//            i++;
//        while (data[s][j] > test)
//            j--;
//        if (i <= j) {
//            temp = data[0][i];
//            data[0][i] = data[0][j];
//            data[0][j] = temp;
//
//            temp = data[1][i];
//            data[1][i] = data[1][j];
//            data[1][j] = temp;
//
//            temporary = array[i];
//            array[i] = array[j];
//            array[j] = temporary;
//
//            i++; j--;
//        }
//    } while (i <= j);
//    if (i < right)
//        quick_sort(array, data, size, i, right, s);
//    if (j > left)
//        quick_sort(array, data, size, left, j, s);
//}
//
//float** copy_data(person* array, float** data, int size, int s) {
//    int option = 0;
//    float tmp = 0;
//    option = getNumSort();
//    switch (option) {
//    case 1:
//        for (int i = 0; i < size; i++)
//            data[s][i] = array[i].gender;
//        break;
//
//    case 2:
//        for (int i = 0; i < size; i++)
//            data[s][i] = array[i].age;
//        break;
//
//    case 3:
//        for (int i = 0; i < size; i++)
//            data[s][i] = array[i].name[0];
//        break;
//    }
//    return data;
//}
//
//void loadFromFile(const char* filename, person** array, char*** file_name, int* size) {
//    FILE* f = fopen(filename, "r");
//    if (!f) {
//        printf("Ошибка: файл не удалось открыть.\n");
//        return;
//    }
//
//    while (!feof(f)) {
//        (*size)++;
//        *array = realloc(*array, (*size) * sizeof(person));
//        *file_name = realloc(*file_name, (*size) * sizeof(char*));
//        (*file_name)[*size - 1] = malloc(20 * sizeof(char));
//
//
//        fscanf(f, "%s", (*file_name)[*size - 1]);
//        (*array)[*size - 1].name = (*file_name)[*size - 1];
//        fscanf(f, "%d", &(*array)[*size - 1].age);
//        int file_gender;
//        fscanf(f, "%d", &file_gender);
//
//        switch (file_gender) {
//        case 1:
//            (*array)[*size - 1].gender = Male;
//            break;
//        case 2:
//            (*array)[*size - 1].gender = Female;
//            break;
//        default:
//            printf("Ошибка: некорректное значение пола.\n");
//            fclose(f);
//            return;
//        }
//    }
//
//    fclose(f);
//}
//
//
//void menu(int size, person* array, float** data) {
//    char** file_name = NULL;
//        int flag = -1;
//        while (flag != 6) {
//            printf("выберите действие:\n1-добавить объект\n2-удалить объект\n3-вывести объект(ы) на экран\n4-отсортировать объекты\n5-завершить программу\n");
//            flag = getNumber();
//            switch (flag) {
//            case 1:
//                size++;
//                array = realloc(array, size * sizeof(person));
//                array[size - 1] = create_person();
//                break;
//    
//            case 2:;
//                int delete_number = -1;
//                printf("Какой объект вы хотите удалить?\nВведите его порядковый номер: ");
//                delete_number = getNumber();
//                delete_person(array, &size, delete_number - 1);
//                break;
//    
//            case 3:
//                output(array, size);
//                break;
//    
//            case 4:
//                printf("Выберите первое поле для сортировки: 1 - пол, 2 - возраст, 3 - имя.\n");
//                data = copy_data(array, data, size, 0);
//    
//                printf("Выберите второе поле для сортировки: 1 - пол, 2 - возраст, 3 - имя.\n(Для сортировки по одному полю еще раз введите предыдущее выбранное число)\n");
//                data = copy_data(array, data, size, 1);
//    
//                quick_sort(array, data, size, 0, size - 1, 0);
//    
//                int left, right;
//                for (int i = 0; i < size - 1; i++) {
//                    if (data[0][i] == data[0][i + 1]) {
//                        left = i, right = i + 1;
//                        for (int j = i + 2; data[0][j] == data[0][i]; j++)
//                            right++;
//                        quick_sort(array, data, size, left, right, 1);
//                    }
//                }
//                printf("Объекты отсортированы.");
//                break;
//    
//            case 5:
//                loadFromFile("C:/Users/Vova/Desktop/labaOAIP/labs 2sem/laba1.2/people.txt", &array, &file_name, &size);
//                break;
//            case 6:
//                printf("Программа завершена!");
//                default:
//                break;
//            }
//            printf("\n");
//        }
//    }
//
//


int main() {
    setlocale(LC_ALL, "Rus");
    int size = 0;

    person* array = (person*)malloc(size * sizeof(person));
    float** data = (float**)malloc(2 * sizeof(float*));
    for (int i = 0; i < 2; i++)
        data[i] = (float*)malloc(10 * sizeof(float));
  
   
    menu(size, array, data);


    for (int i = 0; i < 2; i++) {
        free(data[i]);
    }
    free(data);
    return 0;
    }
    
    



    /*char** file_name = (char**)malloc(size * sizeof(char*));
    int file_gender = 0;
    FILE* f;

    f = fopen("C:/Users/Vova/Desktop/labaOAIP/labs 2sem/laba1.2/people.txt", "r");
    ErrorReturnNull(f, "Error: file is not open");
    while (!feof(f)) {
        size++;
        array = realloc(array, size * sizeof(person));
        file_name = realloc(file_name, size * sizeof(char*));
        for (int j = 0; j < size; j++) {
            file_name[j] = malloc(20 * sizeof(char));
        }

        fscanf(f, "%s", file_name[size - 1]);
        array[size - 1].name = file_name[size - 1];

        fscanf(f, "%d", &array[size - 1].age);

        fscanf(f, "%d", &file_gender);
        switch (file_gender) {
        case 1:
            array[size - 1].gender = Male;
            break;
        case 2:
            array[size - 1].gender = Female;
            break;
        }
    }
    fclose(f);*/


