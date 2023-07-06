#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "User.hpp"  // para usar a classe User
#include "Board.hpp" // para usar a classe Board
#include "Task.hpp"  // para usar a classe Task
#include "TaskManager.hpp" // para usar a classe TaskManager
#include "DataStorage.hpp" // para usar a classe DataStorage
#include "Menu.hpp" // para usar a classe Menu

// BOARD TESTES
TEST_CASE("Teste existencia e criacao de boards") {
    TaskManager taskManager;
    DataStorage dataStorage("src/output/BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == nullptr) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    User* user2 = dataStorage.getUser("Teste2");

    if(user2->getBoard("QuadroTeste") == nullptr) {
        auto board = std::make_unique<Board>("QuadroTeste");
        user2->addBoard(std::move(board));
    }

    CHECK(user2->getBoard("") == nullptr);

    CHECK(user2->getBoard("QuadroTeste") != nullptr);

    CHECK(user2->getBoard("QuadroTesteNAOEXISTE") == nullptr);
}

TEST_CASE("Teste remocao de board") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == nullptr) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    User* user2 = dataStorage.getUser("Teste2");

    if(user2->getBoard("QuadroTeste") == nullptr) {
        auto board = std::make_unique<Board>("QuadroTeste");
        user2->addBoard(std::move(board));
    }

    CHECK(user2->getBoard("QuadroTeste") != nullptr);

    user2->removeBoard("QuadroTeste");

    CHECK(user2->getBoard("QuadroTeste") == nullptr);
}

TEST_CASE("Teste lista boards") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == nullptr) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    User* user2 = dataStorage.getUser("Teste2");

    if(user2->getBoard("QuadroTeste") == nullptr) {
        auto board = std::make_unique<Board>("QuadroTeste");
        user2->addBoard(std::move(board));
    }

    if(user2->getBoard("QuadroTeste2") == nullptr) {
        auto board = std::make_unique<Board>("QuadroTeste2");
        user2->addBoard(std::move(board));
    }

    if(user2->getBoard("QuadroTeste3") == nullptr) {
        auto board = std::make_unique<Board>("QuadroTeste3");
        user2->addBoard(std::move(board));
    }
    
    const std::vector<std::unique_ptr<Board>>& boards = user2->getBoards();

    CHECK(boards[0]->getName() == "QuadroTeste");
    CHECK(boards[1]->getName() == "QuadroTeste2");
    CHECK(boards[2]->getName() == "QuadroTeste3");
}