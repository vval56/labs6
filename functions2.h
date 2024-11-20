#include <stdio.h>
#include <stdlib.h>

// void size_array(int * n, int * m){
//     do{
//     printf("введите количество размер матрицы\n");
//     while (1) {
//         if (scanf("%d %d", n, m) != 1){
//             printf("ошибка, попробуйте снова ");
//             while (getchar() != '\n');
//     }
//     else
//         break;
//     }
//     }while(*n > 100 && *m > 100);
// }

int p_1(char *input)
{
  if (input[0] == '-') {
    for (int i = 1; input[i] != '\n'; i++)
    {
      if (input[i] < '0' || input[i] > '9')
      {
        return 0;
      }
    }
  }
  else {
    for (int i = 0; input[i] != '\n'; i++)
    {
      if (input[i] < '0' || input[i] > '9')
      {
        return 0;
      }
    }
  }
  return 1;
}

int p_2(char* input, int* integer)
{
  int temp;
  if (p_1(input) && sscanf(input, "%d", &temp) == 1)
  {
    *integer = temp;
    return 1;
  }
  else
  {
    return 0;
  }
}

int check() {
  char in[256];
  int Int = 0;
  while (1) {

    fgets(in, sizeof(in), stdin);

    if (p_2(&in, &Int) == 1) {

      break;
    }
    else
    {
      printf("Ошибка, введите еще раз!\n");
    }

  }
  return Int;
}

void scan_arr(int ** arr, int col, int row){
    for(int i = 0; i < row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            scanf("%d", &arr[i][j]);
        }
        arr[i][col] = sum;
        printf("   |Сумма элементов: %d\n", sum);
    }
}

void scan_arr_rand(int col, int row, int ** arr){
    for(int i = 0; i < row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            arr[i][j] = rand() % 6;
            printf("%d ", arr[i][j]);
            sum += arr[i][j];
        }

        arr[i][col] = sum;
        printf("   |Сумма элементов: %d\n", arr[i][col]);
    }
}

void initialize_arr(int ** arr, int col ,int row){
    int i;
    printf("Выберите способ иницализации массива.\n1 - инициализировать вручную.\nлюбая клавиша -  инициализировать случайными числами\n");
    scanf("%d", &i);
    if(i == 1)
        scan_arr(arr, row, col);
    else
        scan_arr_rand(col, row, arr);
}

void swap(int * arr, int *brr, int n){
    for(int i = 0; i < n + 1; i++){
        int temp = arr[i];
        arr[i] = brr[i];
        brr[i] = temp;
    }
}

void print_arr(int ** arr, int col, int row){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            printf("%d ", arr[i][j]);

        printf("   |Сумма элементов: %d\n", arr[i][col]);
    }
}

void shell_sort(int ** arr, int col, int row){
    for(int step = row / 2; step > 0; step /= 2){
        for(int i = 0; i < row - step; i++){
            if(arr[i][col] > arr[i + step][col])
                swap(arr[i], arr[i + step], col);
        }
    }
}
