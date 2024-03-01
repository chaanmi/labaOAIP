typedef struct person {
    char* name;
    int age;
    enum gender gender;  
}person;
void quick_sort(person* array, float** data, int size, int left, int right, int s) {
    int i = left, j = right;
    float test = data[s][(left + right) / 2];
    float temp = 0;
    person temporary;
    do {
        while (data[s][i] < test)
            i++;
        while (data[s][j] > test)
            j--;
        if (i <= j) {
            temp = data[0][i];
            data[0][i] = data[0][j];
            data[0][j] = temp;

            temp = data[1][i];
            data[1][i] = data[1][j];
            data[1][j] = temp;

            temporary = array[i];
            array[i] = array[j];
            array[j] = temporary;

            i++; j--;
        }
    } while (i <= j);
    if (i < right)
        quick_sort(array, data, size, i, right, s);
    if (j > left)
        quick_sort(array, data, size, left, j, s);
}

float** copy_data(person* array, float** data, int size, int s) {
    int option = 0;
    option = getNumSort();
    switch (option) {
    case 1:
        for (int i = 0; i < size; i++)
            data[s][i] = array[i].gender;
        break;

    case 2:
        for (int i = 0; i < size; i++)
            data[s][i] = array[i].age;
        break;

    case 3:
        for (int i = 0; i < size; i++)
            data[s][i] = array[i].name[0];
        break;
    }
    return data;
}

