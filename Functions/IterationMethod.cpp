#include <iostream>
#include <cmath>

using namespace std;

typedef float(*fptr) (float);

float func(float x) // Функция
{
  float res = (3.8 - 3.0 * sin(sqrt(x))) / 0.35;
  return res;
}

// Метод простых итераций
float root(fptr f, float first, float second, float eps)
{
  float x0 = first;
  float x1 = second;

  while (abs(x1 - x0) > eps)
  {
    x1 = (*f)(x0);
    x0 = x1;
  }

  return x1;
}

int main()
{
  cout << root(func, 2.0, 3.0, 0.001) << endl;
  return 0;
}