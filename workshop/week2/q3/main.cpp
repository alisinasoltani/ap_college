#include <iostream>
#include <string.h>
#include "types.h"
#include "utils.h"

using namespace std;

int main() {
    human* people = makePeople(3);
    
    strcpy(people[0].name, "Ali");
    strcpy(people[0].family, "Rezaei1");
    people[0].n_code = 1234567890;
    people[0].age = 25;

    strcpy(people[1].name, "Sina");
    strcpy(people[1].family, "Rezaei2");
    people[1].n_code = 1234567890;
    people[1].age = 26;

    strcpy(people[2].name, "Alisina");
    strcpy(people[2].family, "Rezaei");
    people[2].n_code = 1234567890;
    people[2].age = 27;

    for (int i = 0; i < 3; i++) {
        cout << "name: " << people[i].name << endl;
        cout << "family: " << people[i].family << endl;
        cout << "age: " << people[i].age << endl;
    }

    target_sec(&people, 3);

    killPeople(people, 3);
    return 0;
}