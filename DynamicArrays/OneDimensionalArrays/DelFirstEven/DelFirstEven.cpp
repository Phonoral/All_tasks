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
    for (int i = 0; i < mas_size; i++) mas_ptr[i] = rand() % 10;
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

int* del_first_par(int* mas_ptr, int& mas_size)
{
  int par_index = -1; // Индекс первого четного элемента
  int* new_mass = nullptr; // Указатель на новый массив

  if (mas_ptr != nullptr)
  {
    // Поиск первого четного элемента
    for (int i = 0; i < mas_size; i++)
    {
      if (mas_ptr[i] % 2 == 0) // Условие
      {
        par_index = i;
        break;
      }
    }
    if (par_index == -1) // Проверяем, что элемент найден
    {
      cout << "Ошибка: В массиве нет четных элементов" << endl;
      new_mass = mas_ptr;
    }
    else // Создаем новый массив
    {
      new_mass = new int[mas_size - 1]; // Выделяем память под новый массив
      // Добавляем элементы до найденного
      for (int i = 0; i < par_index; i++) new_mass[i] = mas_ptr[i];
      // Добавляем элементы после найденного
      for (int i = par_index; i < mas_size - 1; i++) new_mass[i] = mas_ptr[i + 1];
      mas_size--; // Уменьшаем размер
    }
    cout << "Четный элемент удален" << endl;
  }
  else cout << "Ошибка: Массив не инициализирован" << endl;

  return new_mass;
}

int main()
{
  setlocale(LC_ALL, "Russian"); /// Русский в консоли
  int* mas = nullptr;
  int mas_size = 0;
  cout << "1. Формирование массива" << endl;
  cout << "2. Вывод массива" << endl;
  cout << "3. Удаление массива" << endl;
  cout << "4. Удалить первый четный элемент" << endl;
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
      mas = del_first_par(mas, mas_size);
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
