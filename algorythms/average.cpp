/* Igor Novitskiy 
 * Var 19
 * */

# include <iostream>

/* Функция счтает среднее значение четных элементов массива
 * int* array - массив целочисленных элементов
 * Конечный индекс используется как счетчик
 * */
double countEvenElementsAverage(int* array, int n);


/**/
int main (void)
{
  int array[] = {1, 2, 3, 4, 5, 6, 7}; 

  std::cout << countEvenElementsAverage(array, 7) << std::endl;
}

/**/
double countEvenElementsAverage(int* array, int n)
{  
  double average = *array;
  
  int i = 1;

  while (i * 2 < n) {
    
    average = ( average + array[ i++ * 2 ] );
  
  };

  return average / i;
}
