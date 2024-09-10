#include "Struct.h"
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

void loadFromFile(Employee*& employees, int& employeeCount) {
    ifstream inFile("employees.txt");
    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    inFile >> employeeCount;
    inFile.ignore();

    employees = new Employee[employeeCount];

    for (int i = 0; i < employeeCount; i++) {
        employees[i].surname = new char[255];
        employees[i].name = new char[255];
        employees[i].phone = new char[255];

        inFile.getline(employees[i].surname, 255);
        inFile.getline(employees[i].name, 255);
        inFile.getline(employees[i].phone, 255);
        inFile >> employees[i].salary;
        inFile.ignore();
    }
    inFile.close();
    cout << "Информация успешно загружена";
}

void saveToFile(Employee* employees, int employeeCount) {
    ofstream outFile("employees.txt");
    if (!outFile) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    outFile << employeeCount << endl;

    for (int i = 0; i < employeeCount; i++) {
        outFile << employees[i].surname << endl;
        outFile << employees[i].name << endl;
        outFile << employees[i].phone << endl;
        outFile << employees[i].salary << endl;
    }

    outFile.close();
    cout << "Информация успешно загружена";
}

void displayEmployees(Employee* employees, int employeeCount) {
    for (int i = 0; i < employeeCount; i++) {
        cout << "Сотрудник " << i + 1 << ":" << endl;
        cout << "Фамилия: " << employees[i].surname << endl;
        cout << "Имя: " << employees[i].name << endl;
        cout << "Номер Телефона: " << employees[i].phone << endl;
        cout << "Зарплата: " << employees[i].salary << endl;
        cout << "--------------------------" << endl;
    }
}

void searchByLastName(Employee* employees, int employeeCount, const char* lastName) {
    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].surname, lastName) == 0) {
            cout << "Фамилия: " << employees[i].surname << endl;
            cout << "Имя: " << employees[i].name << endl;
            cout << "Номер Телефона: " << employees[i].phone << endl;
            cout << "Зарплата: " << employees[i].salary << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Сотрудние не найден." << endl;
    }
}

void searchBySalaryRange(Employee* employees, int employeeCount, double minSalary, double maxSalary) {
    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            cout << "Фамилия: " << employees[i].surname << endl;
            cout << "Имя: " << employees[i].name << endl;
            cout << "Номер Телефона: " << employees[i].phone << endl;
            cout << "Зарплата: " << employees[i].salary << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Сотрудников в указанном диапазоне зарплат не найдено." << endl;
    }
}

void sortByLastName(Employee* employees, int employeeCount) {
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = i + 1; j < employeeCount; j++) {
            if (strcmp(employees[i].surname, employees[j].name) > 0) {
                swap(employees[i], employees[j]);
            }
        }
    }
    cout << "Сотрудники отсортированы по фамилии." << endl;
}

void addEmployee(Employee*& employees, int& employeeCount) {
    Employee* newEmployees = new Employee[employeeCount + 1];

    for (int i = 0; i < employeeCount; i++) {
        newEmployees[i] = employees[i];
    }

    newEmployees[employeeCount].surname = new char[255];
    newEmployees[employeeCount].name = new char[255];
    newEmployees[employeeCount].phone = new char[255];

    cout << "Введите фамилию: ";
    cin.ignore();
    cin.getline(newEmployees[employeeCount].surname, 255);

    cout << "Введите имя: ";
    cin.getline(newEmployees[employeeCount].name, 255);

    cout << "Введите номер телефона (10 чисел): ";
    cin.getline(newEmployees[employeeCount].phone, 255);

    while (strlen(newEmployees[employeeCount].phone)!=10) {
        cout << "Неверный формат номера телефона. Попробуйте еще раз: ";
        cin.getline(newEmployees[employeeCount].phone, 255);
    }

    cout << "Введите зарплату: ";
    cin >> newEmployees[employeeCount].salary;

    delete[] employees;
    employees = newEmployees;
    employeeCount++;

    cout << "Сотрудник успешно добавлен." << endl;
}

void deleteEmployee(Employee*& employees, int& employeeCount) {
    char lastName[255];
    cout << "Введите фамилию сотрудника, которого нужно удалить: ";
    cin.ignore();
    cin.getline(lastName, 255);

    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].surname, lastName) == 0) {
            cout << "Вы уверены, что хотите удалить этого сотрудника? (да-1/нет-0) ";
            char confirmation;
            cin >> confirmation;
            if (confirmation == '1') {
                for (int j = i; j < employeeCount - 1; j++) {
                    employees[j] = employees[j + 1];
                }
                employeeCount--;
                cout << "Сотрудник успешно удален." << endl;
                return;
            }
            else {
                cout << "Удаление отменено." << endl;
                return;
            }
        }
    }
    cout << "Сотрудник не найден." << endl;
}
