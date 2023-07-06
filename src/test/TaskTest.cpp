#include "doctest.h"

#include "User.hpp"  // para usar a classe User
#include "Board.hpp" // para usar a classe Board
#include "Task.hpp"  // para usar a classe Task
#include "TaskManager.hpp" // para usar a classe TaskManager
#include "DataStorage.hpp" // para usar a classe DataStorage
#include "Menu.hpp" // para usar a classe Menu

// TASK TESTES
TEST_CASE("Teste existencia e criacao de tasks") {
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

    Board* board2 = user2->getBoard("QuadroTeste");

    if(taskManager.getTask(board2, "TesteTitulo") == nullptr) {
        Task* task = taskManager.createTask("TesteTitulo", "TesteDescricao", "2003-08-25");
        board2->addTask(task);
    }

    CHECK(taskManager.getTask(board2, "") == nullptr);

    CHECK(taskManager.getTask(board2, "TesteTitulo") != nullptr);

    CHECK(taskManager.getTask(board2, "TesteTituloNAOEXISTE") == nullptr);
}

TEST_CASE("Teste remocao de task") {
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

    Board* board2 = user2->getBoard("QuadroTeste");

    if(taskManager.getTask(board2, "TesteTitulo") == nullptr) {
        Task* task = taskManager.createTask("TesteTitulo", "TesteDescricao", "2003-08-25");
        board2->addTask(task);
    }

    CHECK(taskManager.getTask(board2, "TesteTitulo") != nullptr);

    board2->removeTask(taskManager.getTask(board2, "TesteTitulo"));

    CHECK(taskManager.getTask(board2, "TesteTitulo") == nullptr);
}

TEST_CASE("Teste lista de tasks") {
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

    Board* board2 = user2->getBoard("QuadroTeste");

    if(taskManager.getTask(board2, "TesteTitulo") == nullptr) {
        Task* task = taskManager.createTask("TesteTitulo", "TesteDescricao", "2003-08-25");
        board2->addTask(task);
    }

    if(taskManager.getTask(board2, "TesteTitulo2") == nullptr) {
        Task* task = taskManager.createTask("TesteTitulo2", "TesteDescricao2", "2001-08-24");
        board2->addTask(task);
    }

    if(taskManager.getTask(board2, "TesteTitulo3") == nullptr) {
        Task* task = taskManager.createTask("TesteTitulo3", "TesteDescricao3", "2002-08-24");
        board2->addTask(task);
    }

    std::vector<Task*> tasks = taskManager.getTasks(board2);

    CHECK(tasks[0]->getTitle() == "TesteTitulo");
    CHECK(tasks[1]->getTitle() == "TesteTitulo2");
    CHECK(tasks[2]->getTitle() == "TesteTitulo3");
}

TEST_CASE("Teste ordenacao de tasks") {
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

    Board* board2 = user2->getBoard("QuadroTeste");

    if(taskManager.getTask(board2, "TesteTitulo") == nullptr) {
        Task* task = taskManager.createTask("TesteTitulo", "TesteDescricao", "2003-08-25");
        board2->addTask(task);
    }

    if(taskManager.getTask(board2, "TesteTitulo2") == nullptr) {
        Task* task = taskManager.createTask("TesteTitulo2", "TesteDescricao2", "2001-08-24");
        board2->addTask(task);
    }

    if(taskManager.getTask(board2, "TesteTitulo3") == nullptr) {
        Task* task = taskManager.createTask("TesteTitulo3", "TesteDescricao3", "2002-08-24");
        board2->addTask(task);
    }

    std::vector<Task*> tasksByName = taskManager.getTasksSortedByName(board2);

    std::vector<Task*> tasksByDueDate = taskManager.getTasksSortedByDueDate(board2);

    CHECK(tasksByName[0]->getTitle() == "TesteTitulo");
    CHECK(tasksByName[1]->getTitle() == "TesteTitulo2");
    CHECK(tasksByName[2]->getTitle() == "TesteTitulo3");

    CHECK(tasksByDueDate[0]->getTitle() == "TesteTitulo2");
    CHECK(tasksByDueDate[1]->getTitle() == "TesteTitulo3");
    CHECK(tasksByDueDate[2]->getTitle() == "TesteTitulo");
}

TEST_CASE("Teste movimentacao de tasks") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == nullptr) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    User* user2 = dataStorage.getUser("Teste2");

    if(user2->getBoard("QuadroTeste2") == nullptr) {
        auto board = std::make_unique<Board>("QuadroTeste2");
        user2->addBoard(std::move(board));
    }

    if(user2->getBoard("QuadroTeste3") == nullptr) {
        auto board = std::make_unique<Board>("QuadroTeste3");
        user2->addBoard(std::move(board));
    }

    Board* board2 = user2->getBoard("QuadroTeste2");

    Board* board3 = user2->getBoard("QuadroTeste3");

    if(taskManager.getTask(board2, "TesteTitulo") == nullptr) {
        auto task = taskManager.createTask("TesteTitulo", "TesteDescricao", "2003-08-25");
        board2->addTask(task);
    }

    if(taskManager.getTask(board3, "TesteTitulo2") == nullptr) {
        auto task = taskManager.createTask("TesteTitulo2", "TesteDescricao2", "2001-08-24");
        board3->addTask(task);
    }

    Task* task = taskManager.getTask(board2, "TesteTitulo");
    Task* task2 = taskManager.getTask(board3, "TesteTitulo2");

    
    taskManager.moveTask(task, board2, board3);

    CHECK(taskManager.getTask(board3, "TesteTitulo") != nullptr);
    CHECK(taskManager.getTask(board2, "TesteTitulo") == nullptr);
    
    taskManager.moveTask(task2, board3, board2);

    CHECK(taskManager.getTask(board2, "TesteTitulo2") != nullptr);
    CHECK(taskManager.getTask(board3, "TesteTitulo2") == nullptr);
}

TEST_CASE("Teste edicao de tasks") {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    if(dataStorage.getUser("Teste2") == nullptr) {
        auto user = std::make_unique<User>("Teste2", "m@ufmg.br", taskManager);
        dataStorage.addUser(std::move(user));
    }

    User* user2 = dataStorage.getUser("Teste2");

    if(user2->getBoard("QuadroTeste2") == nullptr) {
        auto board = std::make_unique<Board>("QuadroTeste2");
        user2->addBoard(std::move(board));
    }

    if(user2->getBoard("QuadroTeste3") == nullptr) {
        auto board = std::make_unique<Board>("QuadroTeste3");
        user2->addBoard(std::move(board));
    }

    Board* board2 = user2->getBoard("QuadroTeste2");

    if(taskManager.getTask(board2, "TesteTitulo") == nullptr) {
        auto task = taskManager.createTask("TesteTitulo", "TesteDescricao", "2003-08-25");
        board2->addTask(task);
    }

    Task* task = taskManager.getTask(board2, "TesteTitulo");

    CHECK(task->getTitle() == "TesteTitulo");
    CHECK(task->getDescription() == "TesteDescricao");
    CHECK(task->getDueDate() == "2003-08-25");

    taskManager.editTask(task, "TesteTituloNovo", "TesteDescricaoNovo", "2003-08-26");

    CHECK(task->getTitle() == "TesteTituloNovo");
    CHECK(task->getDescription() == "TesteDescricaoNovo");
    CHECK(task->getDueDate() == "2003-08-26");

    //CHECK(task->getTitle() == "TesteTituloNovo" && task->getDescription() == "TesteDescricaoNovo" && task->getDueDate() == "2003-08-26");
}