#include "types.h"
#ifndef __UTILS__
    #define __UTILS__
    void target_sec(human **humans, int length);
    void target_sec(student **students, int length);
    void target_sec(student **students, int length, bool flag);
    human* makePeople(int number);
    void killPeople(human **people, int number);
    void killStudents(student** students, int number);
    void printHuman(const human *human);
    void printHumans(const human **human, const int length);
    void printStudent(const student *student);
    void printStudents(const student **students, const int length);
#endif