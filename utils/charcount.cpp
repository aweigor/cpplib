#include <ostream>
# include <string>
# include <iostream>
#include <iomanip>

/** Максимальныая длина считываемой строки */
const int MAX_ROW_SIZE = 32;
/** Макс количество символов результата */
const int OUT_LIMIT = 3;

/** Функция принимает строку cstring, возвращает строку cstring с наиболее часто встречающимися символами ASCII*/
char * calcOccurrence (char *dest, char *src, int limit);

/** Функция меняет местами элементы, используя дополнительную переменную */
void swap (char* array, int one, int two);

int main (void) {

  char cstrSource[MAX_ROW_SIZE] = "";
  char cstrOccurence[OUT_LIMIT] = "";

  std::cout << "Enter string without spaces: ";
  std::cin >> std::setw(MAX_ROW_SIZE) >> cstrSource;

  calcOccurrence(cstrOccurence, cstrSource, OUT_LIMIT);
  std::cout << "String character occurrence: " << cstrOccurence << std::endl;

};


char * calcOccurrence (char *dest, char *src, int limit = 3) 
{
  char tmp [MAX_ROW_SIZE] = "";
  int j;
  
  for (int i = 0; i < MAX_ROW_SIZE ; i++) {
    if (! *(src + i)) {
      break;
    }
    *(tmp + i) = *src;
    
    j = i;
    while (j > 0 && tmp[j] < tmp[j - 1]) {
      ::swap(tmp, j, j - 1);
    };

    src++;
  }

  j = 1;

  dest[0] = *tmp;
  // std::cout << *tmp << std::endl; 
  while (*tmp && j < limit) 
  {
    std::cout << *tmp << std::endl;

    if (*tmp != *(tmp + 1)) {
      
      dest[j] = *(tmp + 1);
      
      j++;
    }
  }

  return dest;
}

/**/
void swap (char* array, int one, int two)
{
  char tmp = *(array + one);

  *(array + one) = *(array + two);

  *(array + two) = tmp;
}




