#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"

void showMenu() {
    printf("1. Add New Employee \n");
    printf("2. Show All Employees\n");
    printf("3. Show Total Salary\n");
    printf("4. Show Average Salary\n");
    printf("5. Top Salaries\n");
    printf("6. Bottom Salaries\n");
    printf("7. Exit\n");
}

int main() {
    Employee* employeeList = NULL;
    int choice;
    
    do {
        showMenu();
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char firstName[50], lastName[50];
                int salary;
                DateOfBirth dob;
                
                printf("Name: ");
                scanf("%s", firstName);
                printf("Last Name: ");
                scanf("%s", lastName);
                printf("Salary: ");
                scanf("%d", &salary);
                printf("Birthday: ");
                scanf("%d %d %d", &dob.day, &dob.month, &dob.year);
                
                Employee* newEmployee = createEmployee(firstName, lastName, salary, dob);
                addEmployee(&employeeList, newEmployee);
                break;
            }
            case 2:
                displayEmployees(employeeList);
                break;
            case 3:
                printf("Total Salaries: %d\n", totalSalary(employeeList));
                break;
            case 4:
                printf("Average Salaries: %.2f\n", averageSalary(employeeList));
                break;
            case 5: {
                Employee* maxEmployee = highestSalaryEmployee(employeeList);
                if (maxEmployee != NULL) {
                    printf("Top Salaries: %s %s with %d\n", maxEmployee->firstName, maxEmployee->lastName, maxEmployee->salary);
                } else {
                    printf("Empty List.\n");
                }
                break;
            }
            case 6: {
                Employee* minEmployee = lowestSalaryEmployee(employeeList);
                if (minEmployee != NULL) {
                    printf("Bottom Salaries: %s %s with %d\n", minEmployee->firstName, minEmployee->lastName, minEmployee->salary);
                } else {
                    printf("Empty List.\n");
                }
                break;
            }
            case 7:
                printf("Exiting...\n");
                freeList(employeeList);
                break;
            default:
                printf("انتخاب نامعتبر!\n");
        }
    } while (choice != 7);

    return 0;
}
