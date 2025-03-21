#include <iostream>
#include <string>

using namespace std;

class Student {
 public:
  string name;
  int growth;
  double weight;
  Student* next;

  Student(string name, int growth, double weight) {
    this->name = name;
    this->growth = growth;
    this->weight = weight;
    this->next = nullptr;
  }
};

class StudentList {
 private:
  Student* head;

 public:
  StudentList() { head = nullptr; }

  void addToBeginning(string name, int growth, double weight) {
    Student* newStudent = new Student(name, growth, weight);
    newStudent->next = head;
    head = newStudent;
  }

  void addToEnd(string name, int growth, double weight) {
    Student* newStudent = new Student(name, growth, weight);
    if (head == nullptr) {
      head = newStudent;
      return;
    }
    Student* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newStudent;
  }

  void addAfter(string targetName, string name, int growth, double weight) {
    Student* temp = head;
    while (temp != nullptr && temp->name != targetName) {
      temp = temp->next;
    }
    if (temp != nullptr) {
      Student* newStudent = new Student(name, growth, weight);
      newStudent->next = temp->next;
      temp->next = newStudent;
    } else {
      cout << "Студент с именем " << targetName << " не найден." << endl;
    }
  }

  void addBefore(string targetName, string name, int growth, double weight) {
    if (head == nullptr) {
      cout << "Список пуст." << endl;
      return;
    }
    if (head->name == targetName) {
      addToBeginning(name, growth, weight);
      return;
    }
    Student* temp = head;
    while (temp->next != nullptr && temp->next->name != targetName) {
      temp = temp->next;
    }
    if (temp->next != nullptr) {
      Student* newStudent = new Student(name, growth, weight);
      newStudent->next = temp->next;
      temp->next = newStudent;
    } else {
      cout << "Студент с именем " << targetName << " не найден." << endl;
    }
  }

  void deleteElement(string targetName) {
    if (head == nullptr) {
      cout << "Список пуст." << endl;
      return;
    }
    if (head->name == targetName) {
      Student* temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Student* temp = head;
    while (temp->next != nullptr && temp->next->name != targetName) {
      temp = temp->next;
    }
    if (temp->next != nullptr) {
      Student* toDelete = temp->next;
      temp->next = temp->next->next;
      delete toDelete;
    } else {
      cout << "Студент с именем " << targetName << " не найден." << endl;
    }
  }

  void printList() {
    Student* temp = head;
    while (temp != nullptr) {
      cout << "Имя: " << temp->name << ", Рост: " << temp->growth
           << ", Вес: " << temp->weight << endl;
      temp = temp->next;
    }
  }
};

int main() {
  StudentList students;

  students.addToEnd("Максим", 180, 75.5);
  students.addToEnd("Ярослав", 200, 80.2);
  students.addToBeginning("Эмиль", 179, 68.3);

  cout << "Список студентов:" << endl;
  students.printList();

  students.addAfter("Максим", "Иван", 185, 77.0);
  cout << "\nСписок после добавления Ивана после Максима:" << endl;
  students.printList();

  students.addBefore("Ярослав", "Алексей", 178, 72.5);
  cout << "\nСписок после добавления Алексея перед Ярославом:" << endl;
  students.printList();

  students.deleteElement("Максим");
  cout << "\nСписок после удаления Максима:" << endl;
  students.printList();

  return 0;
}

