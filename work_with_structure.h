#pragma once
enum gender { Male = 1, Female = 2 };

typedef struct person {
    char* name;
    int age;
    enum gender gender;
    
}person;
struct person create_person(void);
void delete_person(person* array, int* size, int delete_number);
void output(person* array, int size);