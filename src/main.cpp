#include <iostream>  // para operações de E/S
#include <string>    // para usar std::string
#include <memory>    // para usar std::unique_ptr
#include <vector>    // para usar std::vector
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

int main() {
    TaskManager taskManager;
    DataStorage dataStorage("BancoDados.txt", taskManager);

    // Carregar dados dos usuários em arquivo externo
    dataStorage.loadData();

    // Loop principal
    while (true) {
        Menu::displayMainMenu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Por favor, insira um numero.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: { // Criar um novo usuário
                std::string username;
                std::cout << "Digite o nome do usuario (apenas uma palavra): ";
                std::cin >> username;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::string email;
                std::cout << "Digite o e-mail do usuario: ";
                std::cin >> email;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                auto user = std::make_unique<User>(username, email, taskManager);
                dataStorage.addUser(std::move(user));
                std::cout << "\n(!) Usuario criado!\n\n";

                break;
            }

            case 2: { // Excluir um usuário existente
                std::cout << "Digite o nome do usuario a ser excluido: ";
                std::string username;
                std::cin >> username;

                dataStorage.removeUser(username);
                std::cout << "\n(!) Usuario excluido!\n\n";

                break;
            }

            case 3: { // Acessar um usuário existente
                std::cout << "Digite o nome do usuario a ser acessado: ";
                std::string username;
                std::cin >> username;

                User* user = dataStorage.getUser(username);
                if (!user) {
                    std::cout << "\n(!) Usuario nao encontrado! Tente novamente. (Dica: maiusculas fazem diferenca!)\n";
                    break;
                }

                bool userLoop = true;
                // Iniciar loop do Menu de Usuário
                while (userLoop) {
                    Menu::displayUserMenu(user->getUsername());
                    int userChoice;
                    if (!(std::cin >> userChoice)) {
                        std::cout << "Por favor, insira um numero.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }

                    switch (userChoice) {
                        case 1: { // Criar um novo quadro
                            std::cout << "Digite o nome do quadro: ";
                            std::string boardName;
                            std::cin >> boardName;

                            auto board = std::make_unique<Board>(boardName);
                            user->addBoard(std::move(board));
                            std::cout << "\n(@) Quadro criado!\n\n";

                            break;
                        }

                        case 2: { // Excluir um quadro existente
                            std::cout << "Digite o nome do quadro a ser excluido: ";
                            std::string boardName;
                            std::cin >> boardName;

                            user->removeBoard(boardName);
                            std::cout << "\n(@) Quadro deletado!\n\n";

                            break;
                        }

                        case 3: { // Acessar um quadro existente
                            std::cout << "Digite o nome do quadro a ser acessado: ";
                            std::string boardName;
                            std::cin >> boardName;

                            Board* board = user->getBoard(boardName);
                            if (!board) {
                                std::cout << "\n(@) Quadro nao encontrado.\n\n";
                                break;
                            }

                            // Iniciar loop do Menu do quadro
                            bool boardLoop = true;
                            while (boardLoop) {
                                std::string selectedBoardName = boardName;
                                Menu::displayBoardMenu(selectedBoardName);
                                int boardChoice;
                                std::cin >> boardChoice;

                                switch (boardChoice) {
                                    case 1: { // Adicionar uma tarefa ao quadro
                                        std::string taskTitle, taskDescription, taskDueDate;
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                        std::cout << "Digite o titulo da tarefa: ";
                                        std::getline(std::cin, taskTitle);

                                        std::cout << "Digite a descricao da tarefa: ";
                                        std::getline(std::cin, taskDescription);

                                        std::cout << "Digite a data de vencimento da tarefa (formato YYYY-MM-DD): ";
                                        std::getline(std::cin, taskDueDate);

                                        Task* task = taskManager.createTask(taskTitle, taskDescription, taskDueDate);
                                        board->addTask(task);
                                        std::cout << "\n(#) Tarefa adicionada!\n\n";

                                        break;
                                    }

                                    case 2: { // Remover uma tarefa do quadro
                                        std::string taskTitle;
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        
                                        std::cout << "Digite o titulo da tarefa a ser removida: ";
                                        std::getline(std::cin, taskTitle);

                                        Task* task = taskManager.getTask(board, taskTitle);
                                        if (!task) {
                                            std::cout << "\n(#) Tarefa nao encontrada.\n\n";
                                            break;
                                        }
                                        board->removeTask(task);
                                        std::cout << "\n(#) Tarefa removida!\n\n";

                                        break;
                                    }

                                    case 3: { // Mover uma tarefa para outro quadro
                                        std::string taskTitle, targetBoardName;
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        
                                        std::cout << "Digite o titulo da tarefa a ser movida: ";
                                        std::getline(std::cin, taskTitle);

                                        Task* task = taskManager.getTask(board, taskTitle);
                                        if (!task) {
                                            std::cout << "\n(#) Tarefa nao encontrada!\n\n";
                                            break;
                                        }

                                        std::cout << "Digite o nome do quadro de destino: ";
                                        std::getline(std::cin, targetBoardName);

                                        Board* targetBoard = user->getBoard(targetBoardName);
                                        if (!targetBoard) {
                                            std::cout << "\n(@) Quadro nao encontrado!\n\n";
                                            break;
                                        }

                                        taskManager.moveTask(task, board, targetBoard);
                                        std::cout << "\n(#) Tarefa movida para outro quadro!\n\n";

                                        break;
                                    }

                                    case 4: { // Listar todas as tarefas no quadro ordenadas por adição
                                        auto tasks = taskManager.getTasks(board);
                                        std::cout << "\n(#) Tarefas listadas por ordem de Adicao:\n";
                                        for (const auto& task : tasks) {
                                            std::cout << "Titulo: " << task->getTitle() << ", Descricao: " << task->getDescription() << ", Data de Vencimento: " << task->getDueDate() << "\n";
                                        }
                                        std::cout << "-------------------------------------\n\n";
                                        break;
                                    }

                                    case 5: { // Listar todas as tarefas no quadro ordenadas por titulo
                                        auto tasks = taskManager.getTasksSortedByName(board);
                                        std::cout << "\n(#) Tarefas listadas por ordem de A-Z:\n";
                                        for (const auto& task : tasks) {
                                            std::cout << "Titulo: " << task->getTitle() << ", Descricao: " << task->getDescription() << ", Data de Vencimento: " << task->getDueDate() << "\n";
                                        }
                                        std::cout << "-------------------------------------\n\n";
                                        break;
                                    }

                                    case 6: { // Listar todas as tarefas no quadro ordenadas por data de vencimento
                                        auto tasks = taskManager.getTasksSortedByDueDate(board);
                                        std::cout << "\n(#) Tarefas listadas por ordem de Data de Vencimento:\n";
                                        for (const auto& task : tasks) {
                                            std::cout << "Titulo: " << task->getTitle() << ", Descricao: " << task->getDescription() << ", Data de Vencimento: " << task->getDueDate() << "\n";
                                        }
                                        std::cout << "-------------------------------------\n\n";
                                        break;
                                    }

                                    case 7: { // Editar uma tarefa
                                        std::string taskTitle, newTitle, newDescription, newDueDate;
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                        std::cout << "Digite o titulo da tarefa a ser editada: ";
                                        std::getline(std::cin, taskTitle);

                                        Task* task = taskManager.getTask(board, taskTitle);
                                        if (!task) {
                                            std::cout << "\n(#) Tarefa nao encontrada.\n\n";
                                            break;
                                        }

                                        std::cout << "Digite o novo titulo: ";
                                        std::getline(std::cin, newTitle);

                                        std::cout << "Digite a nova descricao: ";
                                        std::getline(std::cin, newDescription);

                                        std::cout << "Digite a nova data de vencimento (formato YYYY-MM-DD): ";
                                        std::getline(std::cin, newDueDate);

                                        taskManager.editTask(task, newTitle, newDescription, newDueDate);
                                        std::cout << "\n(#) Tarefa editada!\n\n";

                                        break;
                                    }

                                    case 8: // Retornar ao menu do usuario
                                        boardLoop = false;
                                        std::cout << "Retornando ao menu do usuario...\n";
                                        break;

                                    default:
                                        std::cout << "\n(!) Opcao invalida.\n";
                                }

                                // Se o usuario quiser sair do programa
                                if (userChoice == 4) {
                                    dataStorage.saveData(); // A IMPLEMENTAR AINDA
                                    return 0;
                                }

                            }

                            break;
                        }

                        case 4: { // Listar todos os quadros
                            const std::vector<std::unique_ptr<Board>>& boards = user->getBoards();
                            if (boards.empty()) {
                                std::cout << "Nao ha quadros existentes nesse usuario.\n";
                            } else {
                                for (const auto& board : boards) {
                                    std::cout << "Nome do Quadro: " << board->getName() << "\n";
                                }
                            }
                            break;
                        }

                        case 5: // Retornar ao menu principal
                            userLoop = false;
                            break;

                        default:
                            std::cout << "\n(!) Opcao invalida.\n";
                    }
                }
                break;
            }

            case 4: // Sair
                dataStorage.saveData();
                return 0;

            default:
                std::cout << "\n(!) Opcao invalida.\n";
        }
    }

    return 0;
}
