#include <iostream>
#include "terminal_colors.h"
#include <Vector>
#include "Contact.h"

int main() {
    int choice;
    std::vector<Contact> contacts;
    while (1) {
        std::cout << BOLDWHITE "Welcome" RESET << std::endl;
        std::cout << MAGENTA "chooce an option:" RESET << std::endl;
        std::cout << CYAN "1: show all contacts" << std::endl;
        std::cout << "2: show all favorites" << std::endl;
        std::cout << "3: create contact" << std::endl;
        std::cout << "4: sort contacts (not ready)" << std::endl;
        std::cout << "5: search contacts (not ready)" RESET << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                {
                    for (int i = 0; i < contacts.size(); i++) {
                        Contact contact = contacts.at(i);
                        std::cout << contact.getName() << ": " << contact.getInfo().number << "(" << contact.getInfo().type << ")" << std::endl;
                    }
                }
                break;
            case 2:
                {
                    for (int i = 0; i < contacts.size(); i++) {
                        Contact contact = contacts.at(i);
                        if (contact.isFavorite()) {
                            std::cout << contact.getName() << ": " << contact.getInfo().number << "(" << contact.getInfo().type << ")" << std::endl;
                        }
                    }
                }
                break;
            case 3:
                {
                    std::string name, number, type;
                    std::cout << "Enter name:" << std::endl;
                    std::cin >> name;
                    std::cout << "Enter number:" << std::endl;
                    std::cin >> number;
                    std::cout << "chooce contact type:" << std::endl;
                    std::cout << "1. Home\n2. Work\n3. Cell" << std::endl;
                    std::cin >> choice;
                    switch (choice) {
                        case 1:
                            type = "Home";
                            break;
                        case 2:
                            type = "Work";
                            break;
                        case 3:
                            type = "Cell";
                            break;
                        default:
                            std::cout << BOLDRED "Wrong Type!" RESET << std::endl;
                            break;
                    }
                    try {
                        contacts.emplace_back(Contact(name, Contact_Info(number, type)));
                    }
                    catch(const std::exception& e) {
                        std::cout << BOLDRED "Error While Creating The New Contact!" RESET << std::endl;
                        std::cerr << e.what() << std::endl;
                    }
                }
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;
            case 6:
                /* code */
                break;
            
            default:
                std::cout << BOLDRED "Wrong Choice" RESET << std::endl;
                return 0;
        }
    }
    return 0;
}