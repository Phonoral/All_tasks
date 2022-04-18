#include <iostream>

using namespace std;

char c_name[] = "Иван";
char c_family[] = "Иванов";
char c_otch[] = "Иванович";

void print_fio(char* name = c_name, char* family = c_family, char* otch = c_otch)
{
  cout << family << " " << name << " " << otch << endl;
}


int main()
{
  setlocale(LC_ALL, "Russian"); /// Русский в консоли
  print_fio();
  char t_name[] = "Дмитрий";
  char t_family[] = "Васильев";
  char t_otch[] = "Игоревич";
  print_fio(t_name);
  print_fio(t_name, t_family);
  print_fio(t_name, t_family, t_otch);

  return 0;
}