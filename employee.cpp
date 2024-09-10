#include "Struct.h"
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

void loadFromFile(Employee*& employees, int& employeeCount) {
    ifstream inFile("employees.txt");
    if (!inFile) {
        cout << "������ �������� �����!" << endl;
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
    cout << "���������� ������� ���������";
}

void saveToFile(Employee* employees, int employeeCount) {
    ofstream outFile("employees.txt");
    if (!outFile) {
        cout << "������ �������� �����!" << endl;
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
    cout << "���������� ������� ���������";
}

void displayEmployees(Employee* employees, int employeeCount) {
    for (int i = 0; i < employeeCount; i++) {
        cout << "��������� " << i + 1 << ":" << endl;
        cout << "�������: " << employees[i].surname << endl;
        cout << "���: " << employees[i].name << endl;
        cout << "����� ��������: " << employees[i].phone << endl;
        cout << "��������: " << employees[i].salary << endl;
        cout << "--------------------------" << endl;
    }
}

void searchByLastName(Employee* employees, int employeeCount, const char* lastName) {
    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].surname, lastName) == 0) {
            cout << "�������: " << employees[i].surname << endl;
            cout << "���: " << employees[i].name << endl;
            cout << "����� ��������: " << employees[i].phone << endl;
            cout << "��������: " << employees[i].salary << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "��������� �� ������." << endl;
    }
}

void searchBySalaryRange(Employee* employees, int employeeCount, double minSalary, double maxSalary) {
    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            cout << "�������: " << employees[i].surname << endl;
            cout << "���: " << employees[i].name << endl;
            cout << "����� ��������: " << employees[i].phone << endl;
            cout << "��������: " << employees[i].salary << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "����������� � ��������� ��������� ������� �� �������." << endl;
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
    cout << "���������� ������������� �� �������." << endl;
}

void addEmployee(Employee*& employees, int& employeeCount) {
    Employee* newEmployees = new Employee[employeeCount + 1];

    for (int i = 0; i < employeeCount; i++) {
        newEmployees[i] = employees[i];
    }

    newEmployees[employeeCount].surname = new char[255];
    newEmployees[employeeCount].name = new char[255];
    newEmployees[employeeCount].phone = new char[255];

    cout << "������� �������: ";
    cin.ignore();
    cin.getline(newEmployees[employeeCount].surname, 255);

    cout << "������� ���: ";
    cin.getline(newEmployees[employeeCount].name, 255);

    cout << "������� ����� �������� (10 �����): ";
    cin.getline(newEmployees[employeeCount].phone, 255);

    while (strlen(newEmployees[employeeCount].phone)!=10) {
        cout << "�������� ������ ������ ��������. ���������� ��� ���: ";
        cin.getline(newEmployees[employeeCount].phone, 255);
    }

    cout << "������� ��������: ";
    cin >> newEmployees[employeeCount].salary;

    delete[] employees;
    employees = newEmployees;
    employeeCount++;

    cout << "��������� ������� ��������." << endl;
}

void deleteEmployee(Employee*& employees, int& employeeCount) {
    char lastName[255];
    cout << "������� ������� ����������, �������� ����� �������: ";
    cin.ignore();
    cin.getline(lastName, 255);

    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].surname, lastName) == 0) {
            cout << "�� �������, ��� ������ ������� ����� ����������? (��-1/���-0) ";
            char confirmation;
            cin >> confirmation;
            if (confirmation == '1') {
                for (int j = i; j < employeeCount - 1; j++) {
                    employees[j] = employees[j + 1];
                }
                employeeCount--;
                cout << "��������� ������� ������." << endl;
                return;
            }
            else {
                cout << "�������� ��������." << endl;
                return;
            }
        }
    }
    cout << "��������� �� ������." << endl;
}
