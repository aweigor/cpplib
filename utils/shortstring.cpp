# include <ostream>
# include <string>
# include <iostream>
# include <iomanip>


/**
 *  Новицкий Игорь, вариант 19
 *  
 *  Сформировать новую строку, состоящую из трёх чаще всего встречающихся символов исходной строки. 
 *  Символы новой строки должны следовать в порядке возрастания их кодов ASCII
 *
 **/

/** Максимальныая длина считываемой строки */
const int MAX_ROW_SIZE = 255;

/** Макс количество символов результата */
const int OUT_LIMIT = 3;

/** 
 *  Процедура сортировки массива символов по старшинству в таблице ASCII 
 *  Алгоритм быстрой сортировки
 * */
void sortCString (char* dest, int size);

/** Процедура получения первых N вхождений символов строки */
void getCStringLeadingEntries (const char* src, char* dest, int limit);

/** Процедура перестановки символов в строке си */
void swapChars (char* array, int one, int two);

/***/
char*


void sortCString (char* str, int size) 
{
  int l = 0;
  int r = size - 1;

  char pivot = str[size / 2];

  do {
    while(str[l] < pivot) {
      l++;
    };
    while(str[r] > pivot) {
      r--;
    }
    if (l <= r) {
      ::swapChars(str, l, r);
      l++;
      r--;
    }
  } while (l <= r);

  if (r > 0) {
    sortCString(str, r);
  }

  if (l < size) {
    sortCString(&str[l], size - l);
  }
};

void getCStringLeadingEntries(const char* src, char* dest, int limit) 
{
  int i = 0;
  while (*src && i != 3) {
    if (*(dest + i - 1) != *src) {
      *(dest + i) = *src;
      ++i;
    }
    ++src;
  }
  *(dest + i) = '\0';
};

/**/
void swapChars (char* array, int l, int r)
{
  char tmp = *(array + l);
  *(array + l) = *(array + r);
  *(array + r) = tmp;
}

/**
 *   
 *
 *
 * */
int main (void) 
{
  char cstrSource[MAX_ROW_SIZE] = "cccbbbaaa";
  char cstrOccurence[OUT_LIMIT] = "";

  sortCString(cstrSource, 9);
  getCStringLeadingEntries(cstrSource, cstrOccurence, OUT_LIMIT);

  std::cout << cstrOccurence << std::endl;

  //std::cout << "Enter string without spaces: ";
  //std::cin >> std::setw(MAX_ROW_SIZE) >> cstrSource;

  //calcOccurrence(cstrOccurence, cstrSource, OUT_LIMIT);
  //std::cout << "String character occurrence: " << cstrOccurence << std::endl;

};


