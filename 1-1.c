#include "functions.h"

int main(){

    int * arr, num;

    printf("Введите размер массива:\n");
    num = check();

    arr = (int*)malloc(sizeof(int) * num);

    initialize_arr(arr, num);

    printf("\n_______\\________\n");

    selection_sort_even(arr, num);

    print_arr(arr, num);

    free(arr);

    return 0;
}
