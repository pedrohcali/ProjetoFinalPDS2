#include "doctest.h"

#include "User.hpp"  // para usar a classe User
#include "Board.hpp" // para usar a classe Board
#include "Task.hpp"  // para usar a classe Task
#include "TaskManager.hpp" // para usar a classe TaskManager
#include "DataStorage.hpp" // para usar a classe DataStorage
#include "Menu.hpp" // para usar a classe Menu

// USER TESTES
TEST_CASE("Teste existencia e criacao de usuarios") {
    TaskManager taskManager;
    DataStorage dataStorage("src/output/BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == nullptr) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    CHECK(dataStorage.getUser("Teste2") != nullptr);

    CHECK(dataStorage.getUser("USUARIOQUENAOEXISTE000") == nullptr);
}

TEST_CASE("Teste remocao de usuario") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == nullptr) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    CHECK(dataStorage.getUser("Teste2") != nullptr);

    dataStorage.removeUser("Teste2");

    CHECK(dataStorage.getUser("Teste2") == nullptr);
}