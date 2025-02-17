#include "types.h"

Person *newPerson(char *name, int age);
Person *addPerson(Person *head, char *name, int age);
Person *getPerson(Person *head, char *name);
void printAll(Person *head);
Person *updatePerson(Person *head, char *name, int age);
Person *deletePerson(Person *head, char *name);
void sort(Person *head);
void reverse(Person *head);
void concat(Person *first_head, Person *second_head);
// Person *slice(Person *head);

