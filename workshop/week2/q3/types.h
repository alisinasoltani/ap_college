#ifndef __TYPES__
    #define __TYPES__
    struct human
    {
        char name[30];
        char *family;
        int n_code; // کد ملی
        int age;
    };
    struct student
    {
        human h;
        int std_no; // شماره دانشجویی
        char field[50]; // فیلد رشته تحصیلی
        double avg; // معدل
    };
#endif