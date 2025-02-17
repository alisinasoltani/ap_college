#include <iostream>
#include <string.h>
#include <cstring>
#include "types.h"
#include "utils.h"
#include "terminal_colors.h"

using namespace std;

Person *newPerson(char *name, int age) {
    Person *new_person = new Person;
    new_person->age = age;
    strcpy(new_person->name, name);
    new_person->next = nullptr;
    return new_person;
}

Person *addPerson(Person *head, char *name, int age) {
    Person *new_person = newPerson(name, age);
    if (head == nullptr) {
        head = new_person;
        head->next = nullptr;
        return head;
    } else {
        Person *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp = new_person;
        temp->next = nullptr;
        return temp;
    }
}

Person *getPerson(Person *head, char *name) {
    Person *temp;
    while (temp->next != nullptr) {
        if (strcmp(temp->name, name) == 0) {
            cout << MAGENTA << temp->name << ": " << temp->age << RESET << endl;
            return temp;
        }
        temp = temp->next;
    }
    cout << RED << "person not found!" << RESET << endl;
    return head;
}

void printAll(Person *head) {
    Person *temp;
    while (temp->next != nullptr) {
        cout << ": " << temp->age << endl;
        cout << "print all start" << endl;
        temp = temp->next;
    }
    cout << "print all end" << endl;
}

Person *updatePerson(Person *head, char *name, int age) {
    Person *temp;
    while (temp->next != nullptr) {
        if (strcmp(temp->name, name) == 0) {
            cout << MAGENTA << temp->name << ": " << temp->age << " (old age)" << RESET << endl;
            temp->age = age;
            cout << GREEN << "age successfully changed to " << age << RESET << endl;
            return temp;
        }
        temp = temp->next;
    }
    cout << RED << "person not found!" << RESET << endl;
    return head;
}

Person *deletePerson(Person *head, char *name) {
    if (strcmp(head->name, name) == 0) {
        head = head->next;
        return head;
    } else {
        Person *temp;
        while (temp->next->next != nullptr) {
            if (strcmp(temp->next->name, name) == 0) {
                temp->next = temp->next->next;
                return temp;
            }
        }
        cout << RED << "person not found!" << RESET << endl;
    }
    return head;
}

void sort(Person *head);
void reverse(Person *head);
void concat(Person *first_head, Person *second_head);
