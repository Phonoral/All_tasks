#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian"); // Русский в консоли

  int ** matrix = nullptr; // Указатель на указатель (для динамического выделения памяти)
  int * B = nullptr; // Результирующий массив
  int N = 0; // Строки
  int M = 0; // Столбцы

  // Ввод параметров
  cout << "Введите количество строк N: ";
  cin >> N;
  cout << endl << "Введите количество столбцов M: ";
  cin >> M;
  cout << endl;

  // Выделение памяти
  matrix = new int * [N]; /// Строки
  for (unsigned i = 0; i < N; i++) matrix[i] = new int[M]; // Столбцы
  B = new int[M];
  // Ввод матрицы (построчно)
  for (unsigned i = 0; i < N; i++)
  {
    for (unsigned j = 0; j < M; j++)
    {
      cout << "Введите " << j + 1 << " элемент " << i + 1 << " строки матрицы: ";
      cin >> matrix[i][j];
      cout << endl;
    }
  }
  // Вывод матрицы
  cout << "Матрицы:" << endl;
  for (unsigned i = 0; i < N; i++)
  {
    for (unsigned j = 0; j < M; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  // Рассчеты
  for (unsigned j = 0; j < M; j++)
  {
    int sum = 0;

    for (unsigned i = 0; i < N; i++)
    {
      sum += abs(matrix[i][j]);
    }
    
    if (sum == 0) B[j] = 0;
    else B[j] = 1;
  }
  // Вывод результата
  cout << "Массив В: ";
  for (unsigned j = 0; j < M; j++) cout << B[j] << " ";

  // Очистка выделенной памяти
  for (unsigned i = 0; i < N; i++) delete[] matrix[i];
  delete[] matrix;
  delete[] B;
}

