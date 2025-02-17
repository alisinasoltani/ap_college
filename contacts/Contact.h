#include <iostream>

#ifndef __CONTACT__
    #define __CONTACT__
    struct Contact_Info {
        std::string number;
        std::string type;
        Contact_Info(const std::string& number, const std::string& type): number(number), type(type) {}
        Contact_Info(): number(""), type("") {}
    };

    class Contact {
        protected:
            std::string name;
            Contact_Info info;
            bool is_favorite;

        public:
            Contact();
            Contact(const std::string& name, const Contact_Info& info);
            void setName(const std::string& name);
            void setInfo(const Contact_Info& info);
            void makeFavorite();
            std::string getName() const;
            Contact_Info getInfo() const;
            bool isFavorite() const;
    };
#endif