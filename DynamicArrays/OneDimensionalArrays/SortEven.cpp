#include <iostream>

using namespace std;

// Формирование массива
int* form_mas(int mas_size)
{
  int* new_mas = nullptr; // Новый массив

  if (mas_size > 0) // Проверка размера
  {
    new_mas = new int[mas_size]; // Выделение памяти
    cout << "Массив инициализирован" << endl;
  }
  // Если размер не корректен
  else cout << "Ошибка: Размер массива меньше нуля" << endl;

  return new_mas;
}

// Инициализация значений массива
void init_mas(int* mas_ptr, int mas_size)
{
  if (mas_ptr != nullptr) // Проверка создания массива
  {
    // Заполнение случайными числами от 0 до 9
    for (int i = 0; i < mas_size; i++) mas_ptr[i] = rand() % 10 * 2 -10;
    cout << "Массив заполнен" << endl;
  }
  // Если массив не создан
  else cout << "Ошибка: Массив не инициализирован" << endl;
}

// Вывод массива
void print_mas(int* mas_ptr, int mas_size)
{
  if (mas_ptr != nullptr)
  {
    cout << "Массив: ";
    for (int i = 0; i < mas_size; i++) cout << mas_ptr[i] << " ";
    cout << endl;
  }
  else cout << "Ошибка: Массив не инициализирован" << endl;
}

// Очистка памяти
int* del_mas(int* mas_ptr)
{
  if (mas_ptr != nullptr) // Проверка создания массива
  {
    delete mas_ptr; // Очистка памяти
    mas_ptr = nullptr; // Нулевой указатель
    cout << "Память очищена" << endl;
  }
  else cout << "Ошибка: Массив не инициализирован" << endl;

  return mas_ptr;
}

// Поменять местами элементы
void swap(int* a, int* b)
{
  int tmp = *a;
  a = b;
  *b = tmp;
}

// Сортировка четных
void sort_par(int* mas_ptr, const int mas_size)
{
  for (int i = 0; i < mas_size - 1; i++)
    for (int j = i + 1; j < mas_size; j++)
      if (mas_ptr[i] % 2 == 0 && mas_ptr[j] % 2 == 0 && mas_ptr[i] > mas_ptr[j]) swap(mas_ptr[i], mas_ptr[j]);
}

int main()
{
  setlocale(LC_ALL, "Russian"); /// Русский в консоли
  int* mas = nullptr;
  int mas_size = 0;
  cout << "1. Формирование массива" << endl;
  cout << "2. Вывод массива" << endl;
  cout << "3. Удаление массива" << endl;
  cout << "4. Отсортировать четные" << endl;
  cout << "5. Выход" << endl;
  int k = 0;
  do
  {
    cout << "Введите команду: ";
    cin >> k;
    switch (k)
    {
    case 1:
    {
      cout << "Введите размер нового массива: ";
      cin >> mas_size;
      mas = form_mas(mas_size);
      init_mas(mas, mas_size);
      break;
    };
    case 2:
    {
      print_mas(mas, mas_size);
      break;
    }
    case 3:
    {
      mas = del_mas(mas);
      break;
    }
    case 4:
    {
      sort_par(mas, mas_size);
      break;
    }
    case 5:
    {
      cout << "Выход" << endl;
      break;
    }
    default:
    {
      cout << "Ошибка: Неизвестная команда" << endl;
      break;
    }
    }
  } while (k != 5);

  return 0;
}
