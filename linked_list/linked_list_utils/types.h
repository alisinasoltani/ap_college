#ifndef __TYPES__
    #define __TYPES__
    typedef struct Person {
        char *name;
        int age;
        Person *next;
    } Person;
#endif