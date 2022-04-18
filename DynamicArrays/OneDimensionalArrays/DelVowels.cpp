#include <iostream>
#include <string.h>

void del_vowels(char* str) 
{
  char vowels[] = "aoeiyuAOEIYU"; // Гласные
  int v_cnt = sizeof(vowels); // Размер строки гласных
  int str_size = strlen(str); // Размер нашей строки
  int flag = 0; // Флаг наличия гласной
  char* new_str = new char[str_size]; // Новая строка
  int iter = 0; // Индекс для новой строки
  for (int i = 0; i < str_size; i++)
  {
    flag = 0; // Обнуляем флаг
    for (int j = 0; j < v_cnt; j++)
    {
      if (str[i] == vowels[j])
      {
        flag++; // Увеличиваем флаг
      }
    }
    if (flag == 0) // Добавляем символ в новую строку
    {
      new_str[iter] = str[i];
      iter++;
    }
  }
  new_str[iter] = '\0'; // Завершаем новую строку
  strcpy(str, new_str); // Копируем новую строку в старую
}

int main(void) {
  setlocale(LC_ALL, "Russian"); /// Русский в консоли
  char str[128];
  printf("Введите строку (на английском): ");
  gets_s(str);
  del_vowels(str);
  printf("Результат: ");
  puts(str);
  return 0;
}