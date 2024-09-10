#include "Struct.h"

#include <iostream>
#include <Windows.h>
#pragma warning(disable : 4996)
#include <cstring>
#include <fstream>


using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 0;
    Employee* employees = new Employee[size];

    int choice = 0;
    int employeeCount = 0;

    while (choice != 9) {
        cout << "Меню:\n";
        if (employeeCount == 0) {
            cout << "1. Загрузить информацию из файла\n";
            cout << "2. Добавить нового сотрудника\n";
            cout << "3. Выйти\n";
        }
        else {
            cout << "1. Загрузить информацию из файла\n";
            cout << "2. Записать информацию в файл\n";
            cout << "3. Показать всех сотрудников\n";
            cout << "4. Поиск по фамилии\n";
            cout << "5. Поиск по диапазону заработной платы\n";
            cout << "6. Сортировка по фамилии\n";
            cout << "7. Добавить нового сотрудника\n";
            cout << "8. Удалить сотрудника\n";
            cout << "9. Выйти\n";
        }

        cout << "Выберите опцию: ";
        cin >> choice;
        cin.ignore();

        if (employeeCount == 0) {
            switch (choice) {
            case 1:
                loadFromFile(employees, employeeCount);
                break;
            case 2:
                addEmployee(employees, employeeCount);
                break;
            case 3:
                return 0;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
        else {
            switch (choice) {
            case 1:
                loadFromFile(employees, employeeCount);
                break;
            case 2:
                saveToFile(employees, employeeCount);
                break;
            case 3:
                displayEmployees(employees, employeeCount);
                break;
            case 4:
            {
                char lastName[255];
                cout << "Введите фамилию для поиска: ";
                cin.ignore();
                cin.getline(lastName, 255);
                searchByLastName(employees, employeeCount, lastName);
            }
            break;
            case 5:
            {
                double minSalary, maxSalary;
                cout << "Введите минимальную зарплату: ";
                cin >> minSalary;
                cout << "Введите максимальную зарплату: ";
                cin >> maxSalary;
                searchBySalaryRange(employees, employeeCount, minSalary, maxSalary);
            }
            break;
            case 6:
                sortByLastName(employees, employeeCount);
                break;
            case 7:
                addEmployee(employees, employeeCount);
                break;
            case 8:
                deleteEmployee(employees, employeeCount);
                break;
            case 9:
                return 0;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
    }


    return 0;
}