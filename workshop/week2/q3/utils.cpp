#include <iostream>
#include "types.h"
#include "terminal_colors.h"
#include "utils.h"

using namespace std;

void target_sec(human** humans, int length) {
    int first = INT_MIN, second_first = INT_MIN, second_first_index = 0;
    for (int i = 0; i < length; i++) {
        if (humans[i] == nullptr) {
            continue;
        }
        
        cout << "Human age:\t" << humans[i]->age << endl;

        if (humans[i]->age > first) {
            second_first = first;
            second_first_index = i;
            first = humans[i]->age;
        } else if (humans[i]->age > second_first && humans[i]->age < first) {
            second_first = humans[i]->age;
            second_first_index = i;
        }
    }
    cout << "second old human in the list:\t" << second_first_index << endl;
}

void target_sec(student** students, int length) {
    int first = INT_MIN, second_first = INT_MIN, second_first_index = 0;
    for (int i = 0; i < length; i++) {
        if (students[i]->avg > first) {
            second_first = first;
            first = students[i]->avg;
        } else if (students[i]->avg > second_first && students[i]->avg != first) {
            second_first = students[i]->avg;
        }
    }
    cout << "second student average in the list:\t" << students[second_first_index]->h.name << endl;   
}

void target_sec(student** students, int length, bool flag) {
    if (flag) {
        int first = INT_MIN, second_first = INT_MIN, second_first_index = 0;
        for (int i = 0; i < length; i++) {
            if (students[i]->avg > first) {
                second_first = first;
                first = students[i]->avg;
            } else if (students[i]->avg > second_first && students[i]->avg != first) {
                second_first = students[i]->avg;
            }
        }
        cout << "second student average in the list:\t" << students[second_first_index]->h.name << endl; 
    } else {
        int first = INT_MIN, second_first = INT_MIN, second_first_index = 0;
        for (int i = 0; i < length; i++) {
            if (students[i]->h.age > first) {
                second_first = first;
                first = students[i]->h.age;
            } else if (students[i]->h.age > second_first && students[i]->h.age != first) {
                second_first = students[i]->h.age;
            }
        }
        cout << "second old student in the list:\t" << students[second_first_index]->h.name << endl; 
    }
}

human* makePeople(int number) {
    human* people = new human[number];
    for (int i = 0; i < number; i++) {
        people[i].family = new char[50];
    }
    cout << BLUE << "people created successfully" << RESET << endl;
    return people;
}

void killPeople(human* people, int number) {
    for (int i = 0; i < number; i++) {
        delete people[i].family;
    }
    cout << BLUE << "killed people successfully" << RESET << endl;
    delete people;
}