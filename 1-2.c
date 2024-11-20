#include "functions2.h"

int main(){
    int col, row, ** arr;
    //size_array(&col, &row);

    printf("Введите количество ячеек\n");
    row = check();
    col = check();

    arr = (int**)malloc(sizeof(int*) * row);
    for(int i = 0; i < row; i++)
        arr[i] = (int*)malloc(sizeof(int) * (col + 1));

    initialize_arr(arr, col, row);

    printf("\n_____________\\____________\n");

    shell_sort(arr, col, row);

    print_arr(arr, col, row);


}
