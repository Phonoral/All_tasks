#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian"); /// Русский в консоли
  double summ = 0.0; /// Сумма ряда
  double index = 0.0; /// Глубина расчета
  double accuracy = pow(10.0, -3.0); /// Точность

  double var_x = 0.0; /// Х
  
  /// Ввод Х
  cout << "Введите x: ";
  cin >> var_x;
  cout << endl;

  /// Проверка введенных данных
  if (var_x > 1.0)
  {
    cout << "Ошибка: x должен быть < 1" << endl;
    return -1;
  }

  /// Вычисляем сумму ряда
  for (double i = 1; pow(var_x, i) / i > accuracy; i++)
  {
    summ += pow(var_x, i) / i;
    index = i;
  }

  /// Вывод результата
  cout << "Значение ряда: " << summ << endl;
  cout << "Глубина расчетов: " << (int)index << endl;

  return 0;
}
