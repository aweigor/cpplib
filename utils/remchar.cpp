#include <iostream>
#include <memory>

void remchar (const char* input, char charToRemove, char* output) {
  int outIndex{}; 
  for (int i{}; input[i] != '\0'; ++i) {
    if (input[i] != charToRemove) {
      output[outIndex] = input[i];
      outIndex++;
    }
  }

  output[outIndex] = '\0';
  return output;
}


int main () {
  const char* input{ "Hello!" };
  const char charToRemove{ "0" };

  auto size{ std::strlen(inputString) + 1 };
  auto output{ std::make_unique<char[]>(size) };
  char str[30];

  ::remchar(input, charToRemove, output.get());

  std::cout << "input string: " << input
            << "\noutput string: " << output << '\n'; 

  return 0;
}
