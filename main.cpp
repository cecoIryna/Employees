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
        cout << "����:\n";
        if (employeeCount == 0) {
            cout << "1. ��������� ���������� �� �����\n";
            cout << "2. �������� ������ ����������\n";
            cout << "3. �����\n";
        }
        else {
            cout << "1. ��������� ���������� �� �����\n";
            cout << "2. �������� ���������� � ����\n";
            cout << "3. �������� ���� �����������\n";
            cout << "4. ����� �� �������\n";
            cout << "5. ����� �� ��������� ���������� �����\n";
            cout << "6. ���������� �� �������\n";
            cout << "7. �������� ������ ����������\n";
            cout << "8. ������� ����������\n";
            cout << "9. �����\n";
        }

        cout << "�������� �����: ";
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
                cout << "�������� �����. ���������� �����.\n";
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
                cout << "������� ������� ��� ������: ";
                cin.ignore();
                cin.getline(lastName, 255);
                searchByLastName(employees, employeeCount, lastName);
            }
            break;
            case 5:
            {
                double minSalary, maxSalary;
                cout << "������� ����������� ��������: ";
                cin >> minSalary;
                cout << "������� ������������ ��������: ";
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
                cout << "�������� �����. ���������� �����.\n";
            }
        }
    }


    return 0;
}