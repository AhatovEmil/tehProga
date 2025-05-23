#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Phone {
 public:
  string brand;
  string model;
  int    ram;
  double price;
};

void saveToFile(const vector<Phone>& phones, const string& filename) {
  ofstream file(filename);
  for (const Phone& p : phones) {
    file << p.brand << " " << p.model << " " << p.ram << " " << p.price << "\n";
  }
}

vector<Phone> loadFromFile(const string& filename) {
  vector<Phone> phones;
  ifstream file(filename);
  Phone p;
  while (file >> p.brand >> p.model >> p.ram >> p.price) {
    phones.push_back(p);
  }
  return phones;
}

void addPhone(vector<Phone>& phones) {
  Phone p;
  cout << "Марка: ";
  cin >> p.brand;
  cout << "Модель: ";
  cin >> p.model;
  cout << "ОЗУ (ГБ): ";
  cin >> p.ram;
  cout << "Цена: ";
  cin >> p.price;
  phones.push_back(p);
  cout << "Телефон добавлен!\n";
}

void deletePhone(vector<Phone>& phones) {
  if (phones.empty()) {
    cout << "Список пуст.\n";
    return;
  }
  cout << "Введите номер для удаления (1 - " << phones.size() << "): ";
  int idx;
  cin >> idx;
  if (idx >= 1 && idx <= phones.size()) {
    phones.erase(phones.begin() + idx - 1);
    cout << "Удалено.\n";
  } else {
    cout << "Нет такого номера.\n";
  }
}

void updatePhone(vector<Phone>& phones) {
  if (phones.empty()) {
    cout << "Список пуст.\n";
    return;
  }
  cout << "Введите номер для изменения (1 - " << phones.size() << "): ";
  int idx;
  cin >> idx;
  if (idx >= 1 && idx <= phones.size()) {
    Phone& p = phones[idx - 1];
    cout << "Новая марка: ";
    cin >> p.brand;
    cout << "Новая модель: ";
    cin >> p.model;
    cout << "Новое ОЗУ (ГБ): ";
    cin >> p.ram;
    cout << "Новая цена: ";
    cin >> p.price;
    cout << "Изменено.\n";
  } else {
    cout << "Нет такого номера.\n";
  }
}

void printPhones(const vector<Phone>& phones) {
  if (phones.empty()) {
    cout << "Список пуст.\n";
    return;
  }
  cout << "Телефоны:\n";
  for (int i = 0; i < phones.size(); ++i) {
    const Phone& p = phones[i];
    cout << i + 1 << ") " << p.brand << " " << p.model
         << " | " << p.ram << " ГБ | " << p.price << " руб.\n";
  }
}

int main() {
  vector<Phone> phones;
  const string filename = "phones.txt";

  phones = loadFromFile(filename);

  while (true) {
    cout << "\nМеню:\n";
    cout << "1. Показать телефоны\n";
    cout << "2. Добавить телефон\n";
    cout << "3. Удалить телефон\n";
    cout << "4. Изменить телефон\n";
    cout << "5. Сохранить и выйти\n";
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    switch (choice) {
      case 1: printPhones(phones); break;
      case 2: addPhone(phones); break;
      case 3: deletePhone(phones); break;
      case 4: updatePhone(phones); break;
      case 5:
        saveToFile(phones, filename);
        cout << "Сохранено. До свидания!\n";
        return 0;
      default:
        cout << "Неверный ввод.\n";
    }
  }
}
