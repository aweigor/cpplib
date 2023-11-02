# include <iostream>
# include <cmath>

/*
 * Range of Integration
 **/
struct IntegrationRange {
  float from;
  float to;
  int precision;
};

struct IntegrationResult {
  float integral;
  float error;
};

/*
 * Integration by the method of midpoint rectangles
 **/
int midpoint(IntegrationRange r, float (*y) (float)) 
{
  float integral = 0;
  float step = ( r.to - r.from ) / r.precision;
  
  for (float x = r.from; x <= r.to; x += step) {
    integral += y(x - (step / 2));
  }
  
  integral *= step;

  return integral;
}

/*
 * Calculation endpoint
 **/
IntegrationResult integrate(
  float (*y) (float),
  float from,
  float to,
  int precision,
  int mode
) {
  IntegrationRange r1 = { from, to, precision };
  IntegrationRange r2 = { from, to, precision * 2 };

  float integral1n = midpoint(r1, y);
  float integral2n = midpoint(r2, y);

  return (IntegrationResult){ integral1n, integral2n - integral1n };
}

/*
 * Test function
 **/
float y (float x) 
{
  return std::pow(2, x);
}

int main() 
{
  IntegrationResult i1 = integrate(::y, 1.0, 10.0, 20, 0);
  std::cout << "Result: " << i1.integral << std::endl;
  std::cout << "Error: " << i1.error << std::endl;

  return 0;
}
