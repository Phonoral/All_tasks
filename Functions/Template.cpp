#include <iostream>

using namespace std;

// Поиск среднего арифметичского массива
template <typename T>
double average(int count, T* array)
{
  double avg = 0.0;

  T summ = 0;

  for (int i = 0; i < count; i++) summ += array[i];
  
  avg = summ / count;

  return avg;
}

int main()
{
  setlocale(LC_ALL, "Russian"); /// Русский в консоли
  int mas[3] = { 5, 5, 5};
  int res = average(3, mas);
  cout << res << endl;
  return 0;
}