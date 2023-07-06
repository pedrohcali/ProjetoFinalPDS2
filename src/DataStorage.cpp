#include "DataStorage.hpp"
#include <fstream>
#include <algorithm>
#include <stdexcept> // Para usar std::runtime_error

DataStorage::DataStorage(const std::string& filename, TaskManager& taskManager) 
    : filename(filename), taskManager(taskManager) {
    // if (filename.empty()) {
    //     throw std::invalid_argument("Nome do arquivo nao pode ser vazio.");
    // }
}

DataStorage::~DataStorage() {
}

// Itera sobre a lista de usuários e grava os dados de cada usuário e suas tarefas no arquivo
void DataStorage::saveData() {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Falha ao abrir arquivo para salvamento.");
    }

    for (const auto& user : users) {
        file << user->getUsername() << ',' << user->getEmail();
        for (const auto& board : user->getBoards()) {
            file << ',' << board->getName() << ":{";
            auto& tasks = board->getTasks();
            for (size_t i = 0; i < tasks.size(); ++i) {
                if (i != 0) {
                    file << ';';
                }
                file << tasks[i]->getTitle() << ':' << tasks[i]->getDescription() << ':' << tasks[i]->getDueDate();
            }
            file << "}";
        }
        file << '\n';
    }
}

 // Método para carregar os dados de um arquivo
void DataStorage::loadData() {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Falha ao abrir arquivo para leitura.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, email, token;
        std::getline(iss, username, ',');
        std::getline(iss, email, ',');
        auto user = std::make_unique<User>(username, email, taskManager);
        while (std::getline(iss, token, ',')) {
            std::istringstream issBoard(token);
            std::string boardName, tasksStr;
            std::getline(issBoard, boardName, ':');
            std::getline(issBoard, tasksStr, '{');
            std::getline(issBoard, tasksStr, '}');
            auto board = std::make_unique<Board>(boardName);
            std::istringstream issTasks(tasksStr);
            std::string taskStr;
            while (std::getline(issTasks, taskStr, ';')) {
                std::istringstream issTask(taskStr);
                std::string taskTitle, taskDescription, taskDueDate;
                std::getline(issTask, taskTitle, ':');
                std::getline(issTask, taskDescription, ':');
                std::getline(issTask, taskDueDate, ':');
                Task* task = taskManager.createTask(taskTitle, taskDescription, taskDueDate);
                board->addTask(task);
            }
            user->addBoard(std::move(board));
        }
        users.push_back(std::move(user));
    }
}

std::vector<std::unique_ptr<User>>& DataStorage::getUsers() {
    return users;
}

User* DataStorage::getUser(const std::string& username) {
    auto it = std::find_if(users.begin(), users.end(), [&username](const std::unique_ptr<User>& user) {
        return user->getUsername() == username;
    });
    return it != users.end() ? it->get() : nullptr;
}

// Adiciona um novo usuário ao vetor de usuários
void DataStorage::addUser(std::unique_ptr<User> user) {
    if (!user) {
        throw std::invalid_argument("Nao eh possivel adicionar um usuario nulo.");
    }

    // Verificar se o usuário já existe
    if (getUser(user->getUsername())) {
        throw std::invalid_argument("O usuario ja existe. Tente outro nickname.");
    }

    users.push_back(std::move(user));
}

// Remove o usuário com o nome de usuário fornecido do vetor de usuários
void DataStorage::removeUser(const std::string& username) {
    auto it = std::remove_if(users.begin(), users.end(), [&username](const std::unique_ptr<User>& user) {
        return user->getUsername() == username;
    });

    if (it == users.end()) {
        throw std::runtime_error("Falha ao remover usuario. Usuario nao encontrado.");
    }

    users.erase(it, users.end());
}
