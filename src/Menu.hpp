#ifndef MENU_HPP
#define MENU_HPP

#include <string>

class Menu {
public:
    static void displayMainMenu();
    static void displayUserMenu(const std::string& userName);
    static void displayBoardMenu(const std::string& boardName);
};

#endif //MENU_HPP
