#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "User.hpp"  // para usar a classe User
#include "User.cpp"
#include "Board.hpp" // para usar a classe Board
#include "Board.cpp"
#include "Task.hpp"  // para usar a classe Task
#include "Task.cpp"
#include "TaskManager.hpp" // para usar a classe TaskManager
#include "TaskManager.cpp"
#include "DataStorage.hpp" // para usar a classe DataStorage
#include "DataStorage.cpp"
#include "Menu.hpp" // para usar a classe Menu
#include "Menu.cpp"

// USER TESTES
TEST_CASE("Teste existencia e criacao de usuarios") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == false) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    CHECK(dataStorage.getUser("Teste2") != false);

    CHECK(dataStorage.getUser("USUARIOQUENAOEXISTE000") == false);
}

TEST_CASE("Teste remocao de usuario") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == false) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    CHECK(dataStorage.getUser("Teste2") != false);

    dataStorage.removeUser("Teste2");

    CHECK(dataStorage.getUser("Teste2") == false);
}