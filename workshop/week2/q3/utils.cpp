#include <iostream>
#include "types.h"
#include "terminal_colors.h"
#include "utils.h"

using namespace std;

void target_sec(human** humans, int length) {
    human temp;
    bool is_swapped = false;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (humans[j]->age > humans[j+1]->age) {
                temp.age = humans[j+1]->age;
                humans[j+1]->age = humans[j]->age;
                humans[j]->age = temp.age; 
                is_swapped = true;
            }
        }
        if (!is_swapped) break;
    }
    printHuman(humans[length - 2]);
}

void target_sec(student** students, int length) {
    student temp;
    bool is_swapped = false;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (students[j]->avg > students[j+1]->avg) {
                temp.avg = students[j+1]->avg;
                students[j+1]->avg = students[j]->avg;
                students[j]->avg = temp.avg; 
                is_swapped = true;
            }
        }
        if (!is_swapped) break;
    }
    printStudent(students[length - 2]);
}

void target_sec(student** students, int length, bool flag) {
    if (flag) {
        student temp;
        bool is_swapped = false;
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (students[j]->avg > students[j+1]->avg) {
                    temp.avg = students[j+1]->avg;
                    students[j+1]->avg = students[j]->avg;
                    students[j]->avg = temp.avg; 
                    is_swapped = true;
                }
            }
            if (!is_swapped) break;
        }
        cout << "second student average in the list: " << MAGENTA << students[length - 2]->h.name << RESET << endl; 
    } else {
        student temp;
        bool is_swapped = false;
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (students[j]->h.age > students[j+1]->h.age) {
                    temp.h.age = students[j+1]->h.age;
                    students[j+1]->h.age = students[j]->h.age;
                    students[j]->h.age = temp.h.age; 
                    is_swapped = true;
                }
            }
            if (!is_swapped) break;
        }
        cout << "second old student in the list: " << MAGENTA << students[length - 2]->h.name << RESET << endl; 
    }
}

human* makePeople(int number) {
    human* people = new human[number];
    for (int i = 0; i < number; i++) {
        people[i].family = new char[50];
    }
    cout << BLUE << number << " people created successfully" << RESET << endl;
    return people;
}

void killPeople(human** people, int number) {
    for (int i = 0; i < number; i++) {
        delete[] people[i]->family;
        delete[] people[i];
    }
    delete[] people;
    cout << BLUE << "killed people successfully" << RESET << endl;
}

void killStudents(student** students, int number) {
    for (int i = 0; i < number; i++) {
        delete[] students[i];
    }
    delete[] students;
    cout << BLUE << "killed students successfully" << RESET << endl;
}

void printHuman(const human *human) {
    cout << MAGENTA << human->name << " " << human->family 
    << BOLDWHITE << ": is " << MAGENTA << human->age << BOLDWHITE << " years old. " 
    << BOLDWHITE << "with code: " << MAGENTA << human->n_code
    << RESET << endl;
}

void printHumans(const human **humans, const int length) {
    for (int i = 0; i < length; i++) {
        cout << MAGENTA << humans[i]->name << " " << humans[i]->family 
        << BOLDWHITE << ": is " << MAGENTA << humans[i]->age << BOLDWHITE << " years old. " 
        << BOLDWHITE << "with code: " << MAGENTA << humans[i]->n_code
        << RESET << endl;
    }
}

void printStudent(const student *student) {
    cout << MAGENTA << student->h.name << " " << student->h.family 
    << BOLDWHITE << ": is " << MAGENTA << student->h.age << BOLDWHITE << " years old. " 
    << BOLDWHITE << "with code: " << MAGENTA << student->h.n_code
    << BOLDWHITE << " and has the average of " << MAGENTA << student->avg
    << BOLDWHITE << " in " << MAGENTA << student->field
    << BOLDWHITE << " using student code: " << MAGENTA << student->std_no
    << RESET << endl;
}

void printStudents(const student **students, const int length) {
    for (int i = 0; i < length; i++) {
        cout << MAGENTA << students[i]->h.name << " " << students[i]->h.family 
        << BOLDWHITE << ": is " << MAGENTA << students[i]->h.age << BOLDWHITE << " years old. " 
        << BOLDWHITE << "with code: " << MAGENTA << students[i]->h.n_code
        << BOLDWHITE << " and has the average of " << students[i] << students[i]->avg
        << BOLDWHITE << " in " << MAGENTA << students[i]->field
        << BOLDWHITE << " using student code: " << MAGENTA << students[i]->std_no
        << RESET << endl;
    }
}