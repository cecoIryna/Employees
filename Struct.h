#pragma once

const int MAX_LENGTH = 100;

struct Employee {
    char* surname;
    char* name;
    char* phone;
    double salary;
};

// Функции
void loadFromFile(Employee*& employees, int& employeeCount);
void saveToFile(Employee* employees, int employeeCount);
void displayEmployees(Employee* employees, int employeeCount);
void searchByLastName(Employee* employees, int employeeCount, const char* lastName);
void searchBySalaryRange(Employee* employees, int employeeCount, double minSalary, double maxSalary);
void sortByLastName(Employee* employees, int employeeCount);
void addEmployee(Employee*& employees, int& employeeCount);
void deleteEmployee(Employee*& employees, int& employeeCount);
bool isPhoneNumberValid(const char* phoneNumber);