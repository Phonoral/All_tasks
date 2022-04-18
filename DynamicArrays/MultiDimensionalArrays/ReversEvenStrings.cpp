#include <iostream>

using namespace std;

// Формирование массива
int** form_mas(int str_cnt, int col_cnt)
{
  int** new_mas = nullptr; // Новый массив
  if (str_cnt > 0 && col_cnt > 0)
  {
    new_mas = new int* [str_cnt]; // Строки
    for (int i = 0; i < str_cnt; i++) new_mas[i] = new int[col_cnt]; // Столбцы
  }
  // Если размер не корректен
  else cout << "Ошибка: Количество строк или столбцов не корректно" << endl;

  return new_mas;
}

// Инициализация значений массива
void init_mas(int** mas_ptr, int str_cnt, int col_cnt)
{
  if (mas_ptr != nullptr) // Проверка создания массива
  {
    for (int i = 0; i < str_cnt; i++)
    {
      for (int j = 0; j < col_cnt; j++)
      {
        mas_ptr[i][j] = rand() % 10 * 2 - 10;
      }
    }
  }
  // Если массив не создан
  else cout << "Ошибка: Массив не инициализирован" << endl;
}

// Вывод массива
void print_mas(int** mas_ptr, int str_cnt, int col_cnt)
{
  if (mas_ptr != nullptr)
  {
    cout << "Массив: " << endl;
    for (int i = 0; i < str_cnt; i++)
    {
      for (int j = 0; j < col_cnt; j++)
      {
        cout << mas_ptr[i][j] << " ";
      }
      cout << endl;
    }
  }
  else cout << "Ошибка: Массив не инициализирован" << endl;
}

// Очистка памяти
int** del_mas(int** mas_ptr, int str_count)
{
  if (mas_ptr != nullptr) // Проверка создания массива
  {
    for (int i = 0; i < str_count; i++) delete mas_ptr[i];
    delete mas_ptr; // Очистка памяти
    mas_ptr = nullptr; // Нулевой указатель
    cout << "Память очищена" << endl;
  }
  else cout << "Ошибка: Массив не инициализирован" << endl;

  return mas_ptr;
}

// Поменять местами указатели на строки
void swap(int** a, int** b)
{
  int *tmp = *a;
  *a = *b;
  *b = tmp;
}

// Сортировка четных строк
void reverse_even_str(int** mas_ptr, int str_cnt)
{
  if (mas_ptr != nullptr) // Проверка создания массива
  {
    int back_cnt = str_cnt; // Индекс с конца
    if (back_cnt % 2 != 0) back_cnt--;
    for (int i = 0; i < str_cnt / 2; i++)
    {
      if (i % 2 == 0)
      {
        swap(&mas_ptr[i], &mas_ptr[back_cnt]);
        back_cnt -= 2;
      }
    }
    cout << "Обработка завершена" << endl;
  }
  else
  {
    cout << "Ошибка: Массив не инициализирован" << endl;
  }
}

int main()
{
  setlocale(LC_ALL, "Russian"); /// Русский в консоли
  int** mas = nullptr;
  int str_count = 0;
  int col_count = 0;

  cout << "1. Формирование массива" << endl;
  cout << "2. Вывод массива" << endl;
  cout << "3. Удаление массива" << endl;
  cout << "4. Развернуть четные строки" << endl;
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
      cout << "Введите количество строк: ";
      cin >> str_count;
      cout << "Введите количество столбцов: ";
      cin >> col_count;
      mas = form_mas(str_count, col_count);
      init_mas(mas, str_count, col_count);
      break;
    };
    case 2:
    {
      print_mas(mas, str_count, col_count);
      break;
    }
    case 3:
    {
      mas = del_mas(mas, str_count);
      break;
    }
    case 4:
    {
      reverse_even_str(mas, str_count);
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
