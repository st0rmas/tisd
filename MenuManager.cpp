#include "MenuManager.h"
#include <iostream>

void MenuManager::addMenuItem(MenuItem item) {
    menuItems.push_back(item);
}

void MenuManager::showMenu() {
    int choice;
    do {
        std::cout << "Menu:\n";
        for (int i = 0; i < menuItems.size(); ++i) {
            std::cout << i + 1 << ". " << menuItems[i].getLabel() << "\n";
        }
        std::cout << "0. Exit\n";
        std::cout << ">>>  ";
        std::cin >> choice;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(INTMAX_MAX, '\n');
            showMenu();

        }
        else{
            if (choice > 0 && choice <= menuItems.size()) {
                menuItems[choice - 1].execute();
            }
            else if (choice != 0) {
                std::cout << "Invalid command.\n";
            }
        }
    } while (choice != 0);
}





