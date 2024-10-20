#ifndef EMPLOYEE
    #define EMPLOYEE
    typedef struct {
        int day;
        int month;
        int year;
    } DateOfBirth;

    typedef struct Employee {
        char firstName[50];
        char lastName[50];
        int salary;
        DateOfBirth dob;
        struct Employee* next;
    } Employee;
#endif
