#include "Employee.h"

#ifndef LINKEDLIST_H
    #define LINKEDLIST_H
    Employee* createEmployee(char* firstName, char* lastName, int salary, DateOfBirth dob);
    void addEmployee(Employee** head, Employee* newEmployee);
    void displayEmployees(Employee* head);
    int totalSalary(Employee* head);
    double averageSalary(Employee* head);
    Employee* highestSalaryEmployee(Employee* head);
    Employee* lowestSalaryEmployee(Employee* head);
    void freeList(Employee* head);
#endif
