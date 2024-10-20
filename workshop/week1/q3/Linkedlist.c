#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"

Employee* createEmployee(char* firstName, char* lastName, int salary, DateOfBirth dob) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmployee->firstName, firstName);
    strcpy(newEmployee->lastName, lastName);
    newEmployee->salary = salary;
    newEmployee->dob = dob;
    newEmployee->next = NULL;
    return newEmployee;
}

void addEmployee(Employee** head, Employee* newEmployee) {
    if (*head == NULL) {
        *head = newEmployee;
    } else {
        Employee* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmployee;
    }
}

void displayEmployees(Employee* head) {
    Employee* temp = head;
    if (temp == NULL) {
        printf("No Employees!\n");
        return;
    }
    while (temp != NULL) {
        printf("Name: %s %s، Salary: %d، Birthday: %d/%d/%d\n", temp->firstName, temp->lastName, temp->salary, temp->dob.day, temp->dob.month, temp->dob.year);
        temp = temp->next;
    }
}

int totalSalary(Employee* head) {
    int total = 0;
    Employee* temp = head;
    while (temp != NULL) {
        total += temp->salary;
        temp = temp->next;
    }
    return total;
}

double averageSalary(Employee* head) {
    int count = 0;
    int total = totalSalary(head);
    Employee* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    if (count == 0) return 0;
    return (double)total / count;
}

Employee* highestSalaryEmployee(Employee* head) {
    if (head == NULL) return NULL;
    Employee* maxEmployee = head;
    Employee* temp = head->next;
    while (temp != NULL) {
        if (temp->salary > maxEmployee->salary) {
            maxEmployee = temp;
        }
        temp = temp->next;
    }
    return maxEmployee;
}

Employee* lowestSalaryEmployee(Employee* head) {
    if (head == NULL) return NULL;
    Employee* minEmployee = head;
    Employee* temp = head->next;
    while (temp != NULL) {
        if (temp->salary < minEmployee->salary) {
            minEmployee = temp;
        }
        temp = temp->next;
    }
    return minEmployee;
}

void freeList(Employee* head) {
    Employee* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
