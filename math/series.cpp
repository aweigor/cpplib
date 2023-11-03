# include <iostream>
# include <cmath>

struct Serie {
  float first;
  float (*next) (float prev, float x, int n);
};

/*
 * N term formula of expression 1 / sqrt(1 + x)
 * */
float nTerm (float pTerm, float x, int n) 
{
  return std::pow(-1, n) * ( pTerm * ( ( 2 * n - 1 ) * x ) / (2 * n) );
}

/*
 * Serie of the expression
 * */
static Serie expSerie = { 1, nTerm };

/*
 * Find serie summa with max number of components and given absolute error 
 * */
float solve (Serie* serie, float x, float err, int depth ) 
{
  float next = serie->first;
  float sum = next;
  
  for (int i = 1; i <= depth; ++i) {
    if (std::abs(next) < err) {
      break;
    }

    next = serie->next(next, x, i);
    sum += next;
  }

  if (std::abs(next) > err) {
    throw std::runtime_error("too little depth to reach the error");
  }

  return sum;
}

int main (void) 
{
  float x;
  float err;
  int depth;

  std::cout << "x:" << std::endl;
  
  try {
    std::cin >> x;
    if (x <= -1 || x >= 1) {
      throw std::runtime_error("x must be in range of (-1, 1)");
    }
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "err:" << std::endl;
  
  try {
    std::cin >> err;
    if (err < 0) {
      throw std::runtime_error("error must be positive");
    }
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "depth:" << std::endl;

  try {
    std::cin >> depth;
    if (depth < 1) {
      throw std::runtime_error("depth must be greater than zero");
    }
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::cout << ::solve(&::expSerie, x, err, depth) << std::endl;
  } catch (const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }
}
