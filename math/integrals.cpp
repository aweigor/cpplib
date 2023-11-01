# include <iostream>
# include <cmath>

int midpoint(int l, int r, int (*func) (int)) {
  int ret;
  // step of integration
  int step = r - l / 2;
  // sum of heights
  for (int i = 1; i < r; i++) {
    ret += func(i - (step / 2));
  }
  // return multiplication of sums
  std::cout << step << std::endl;
  return ret * step;
}

int y (int x) {
  return std::pow(2, x);
}

int main() 
{
  std::cout << midpoint(0, 10, &::y) << std::endl;
}
