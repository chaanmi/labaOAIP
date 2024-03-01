#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "work_with_structure.h"
#include "check_errors.h"
#include "sort.h"


void menu(int size, person* array, float** data) {
    char** file_name = NULL;
        int flag = -1;
        while (flag != 6) {
            printf("выберите действие:\n1-добавить объект\n2-удалить объект\n3-вывести объект(ы) на экран\n4-отсортировать объекты\n5-парсинг файла\n6-завершить программу\n");
            flag = getNumber();
            switch (flag) {
            case 1:
                size++;
                array = realloc(array, size * sizeof(person));
                array[size - 1] = create_person();
                break;
    
            case 2:;
                int delete_number = -1;
                printf("Какой объект вы хотите удалить?\nВведите его порядковый номер: ");
                delete_number = getNumber();
                delete_person(array, &size, delete_number - 1);
                break;
    
            case 3:
                output(array, size);
                break;
    
            case 4:
                printf("Выберите первое поле для сортировки: 1 - пол, 2 - возраст, 3 - имя.\n");
                data = copy_data(array, data, size, 0);
    
                printf("Выберите второе поле для сортировки: 1 - пол, 2 - возраст, 3 - имя.\n(Для сортировки по одному полю еще раз введите предыдущее выбранное число)\n");
                data = copy_data(array, data, size, 1);
    
                quick_sort(array, data, size, 0, size - 1, 0);
    
                int left, right;
                for (int i = 0; i < size - 1; i++) {
                    if (data[0][i] == data[0][i + 1]) {
                        left = i, right = i + 1;
                        for (int j = i + 2; data[0][j] == data[0][i]; j++)
                            right++;
                        quick_sort(array, data, size, left, right, 1);
                    }
                }
                printf("Объекты отсортированы.\n");
                break;
    
            case 5:
                loadFromFile("C:/Users/Vova/Desktop/labaOAIP/labs 2sem/laba1.2/people.txt", &array, &file_name, &size);
                break;
            case 6:
                printf("Программа завершена!");
            default:
                break;
            }
            printf("\n");
        }
    }