#include "Menu.hpp"
#include <iostream>

void Menu::displayMainMenu() {
    std::cout << "|---------|MENU PRINCIPAL|---------|\n"
              << "Menu principal:\n"
              << "1. Criar um novo usuario\n"
              << "2. Excluir um usuario existente\n"
              << "3. Acessar um usuario existente\n"
              << "4. Sair\n"
              << "Escolha uma opcao: \n"
              << "|----------------------------------|\n\n";
}

void Menu::displayUserMenu(const std::string& userName) {
    std::cout << "|---------|MENU USUARIO|---------|\n"
              << "Menu do usuario (" << userName << "):\n"
              << "1. Criar um novo quadro\n"
              << "2. Excluir um quadro existente\n"
              << "3. Acessar um quadro existente\n"
              << "4. Listar todos os quadros\n"
              << "5. Retornar ao menu principal\n"
              << "Escolha uma opcao: \n"
              << "|--------------------------------|\n\n";
}

void Menu::displayBoardMenu(const std::string& boardName) {
    std::cout << "|---------|MENU QUADRO|---------|\n"
              << "Menu do quadro (" << boardName << "):\n"
              << "1. Adicionar uma tarefa ao quadro\n"
              << "2. Remover uma tarefa do quadro\n"
              << "3. Mover uma tarefa para outro quadro\n"
              << "4. Listar todas as tarefas no quadro ordenadas por adicao\n"
              << "5. Listar todas as tarefas no quadro ordenadas por titulo\n"
              << "6. Listar todas as tarefas no quadro ordenadas por data de vencimento\n"
              << "7. Editar uma tarefa (A implementar)\n"
              << "8. Retornar ao menu do usuario\n"
              << "Escolha uma opcao: \n"
              << "|-------------------------------|\n\n";
}

