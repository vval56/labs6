#include <stdio.h>
#include <stdlib.h>

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


void scanarr(int * arr, int n){
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void scanarrrand(int * arr, int n){
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
}

void initialize_arr(int * arr, int n){
    int i;
    printf("Выберите способ иницализации массива.\n1 - инициализировать вручную.\nлюбая клавиша -  инициализировать случайными числами\n");
    scanf("%d", &i);
    if(i == 1)
        scanarr(arr, n);
    else
        scanarrrand(arr, n);

    printf("\n");
}

int find_min_even(int * arr, int begin, int end){
    int min;

    for(int i = begin; i < end; i++){
        if(arr[i] % 2 == 0){
            min = i;
            break;
        }
    }

    while(begin < end){
        if(arr[min] > arr[begin] && arr[min] % 2 == 0 && arr[begin] % 2 == 0)
            min = begin;

        begin++;
    }

    return min;
}

void swap(int * a, int * b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void selection_sort_even(int * arr, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            swap(&arr[i], &arr[find_min_even(arr, i, n)]);
        }
        else
            continue;
    }
}

void print_arr(int * arr, int n){
    for(int i = 0 ; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

