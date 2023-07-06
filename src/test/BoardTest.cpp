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


// BOARD TESTES
TEST_CASE("Teste existencia e criacao de boards") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == false) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    User* user2 = dataStorage.getUser("Teste2");

    if(user2->getBoard("QuadroTeste") == false) {
        auto board = std::make_unique<Board>("QuadroTeste");
        user2->addBoard(std::move(board));
    }

    CHECK(user2->getBoard("") == false);

    CHECK(user2->getBoard("QuadroTeste") != false);

    CHECK(user2->getBoard("QuadroTesteNAOEXISTE") == false);
}

TEST_CASE("Teste remocao de board") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == false) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    User* user2 = dataStorage.getUser("Teste2");

    if(user2->getBoard("QuadroTeste") == false) {
        auto board = std::make_unique<Board>("QuadroTeste");
        user2->addBoard(std::move(board));
    }

    CHECK(user2->getBoard("QuadroTeste") != false);

    user2->removeBoard("QuadroTeste");

    CHECK(user2->getBoard("QuadroTeste") == false);
}

TEST_CASE("Teste lista boards") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == false) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    User* user2 = dataStorage.getUser("Teste2");

    if(user2->getBoard("QuadroTeste") == false) {
        auto board = std::make_unique<Board>("QuadroTeste");
        user2->addBoard(std::move(board));
    }

    if(user2->getBoard("QuadroTeste2") == false) {
        auto board = std::make_unique<Board>("QuadroTeste2");
        user2->addBoard(std::move(board));
    }

    if(user2->getBoard("QuadroTeste3") == false) {
        auto board = std::make_unique<Board>("QuadroTeste3");
        user2->addBoard(std::move(board));
    }
    
    const std::vector<std::unique_ptr<Board>>& boards = user2->getBoards();

    CHECK(boards[0]->getName() == "QuadroTeste");
    CHECK(boards[1]->getName() == "QuadroTeste2");
    CHECK(boards[2]->getName() == "QuadroTeste3");
}