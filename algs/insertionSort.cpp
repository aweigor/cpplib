/* Igor Novitskiy
 * Insertion Sort
 * */

# include <iostream>

/* 
 * Функция меняет местами элементы, используя дополнительную переменную
 * */
void swap (int* array, int one, int two);

/*
 * Процедура сортирует указанный массив методом вставок
 * */
void insertionSort (int* array, int n);

/*
 * Процедура распечатывает массив
 * */
void printArray (int* array, int n);

/**/
int main (void) 
{
  int array[] = { 7, 6, 5, 4, 3, 2, 1 };

  insertionSort(array, 7);

  printArray(array, 7);
}

/**/
void swap (int* array, int one, int two) 
{
  int tmp = *(array + one);
  
  *(array + one) = *(array + two);
  
  *(array + two) = tmp;
}

/**/
void insertionSort(int* array, int n) 
{
  int j;

  for (int i = 1; i < n; i++) 
  {
    j = i;

    while (j > 0 && array[j] < array[j - 1]) 
    {
      swap(array, j, j - 1);
      
      j--;
    }
  }
}

/**/
void printArray(int* array, int n) 
{
  for (int i = 0; i < n; i++) 
  {
    std::cout << array[i] << ' ';
  }
  std::cout << std::endl;
}
