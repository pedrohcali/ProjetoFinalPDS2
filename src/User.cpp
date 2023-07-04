#include "User.hpp"
#include "Board.hpp"
#include "Task.hpp"
#include <algorithm>
#include <stdexcept>

User::User(const std::string& username, const std::string& email, TaskManager& taskManager)
    : username(username), email(email), taskManager(taskManager) {
}

User::~User() {
}

const std::string& User::getUsername() const {
    return username;
}

void User::setUsername(const std::string& username) {
    if (username.empty()) {
        throw std::invalid_argument("O nome de usuario nao pode estar vazio.");
    }
    this->username = username;
}

const std::string& User::getEmail() const {
    return email;
}

void User::setEmail(const std::string& email) {
    if (email.empty() || email.find('@') == std::string::npos) {
        throw std::invalid_argument("O endereco de e-mail fornecido eh invalido.");
    }
    this->email = email;
}

const std::vector<std::unique_ptr<Board>>& User::getBoards() const {
    return boards;
}

void User::addBoard(std::unique_ptr<Board> board) {
    if (!board) {
        throw std::invalid_argument("Quadro nao pode ser nulo.");
    }

    for (const auto& b : boards) {
        if (b->getName() == board->getName()) {
            throw std::invalid_argument("Ja existe um quadro com o mesmo nome.");
        }
    }

    boards.push_back(std::move(board));
}

void User::removeBoard(const std::string& boardName) {
    // Implementar mecanismo para buscar o quadro pelo nome
    auto it = std::find_if(boards.begin(), boards.end(), [&boardName](const auto& board) {
        return board->getName() == boardName;
    });
    
    if (it == boards.end()) {
        throw std::invalid_argument("Quadro nao encontrado.");
    }
    
    boards.erase(it);
}

void User::moveTask(Board* fromBoard, Board* toBoard, Task* task) {
    if (!fromBoard || !toBoard || !task) {
        throw std::invalid_argument("Quadros e tarefa nao podem ser nulos.");
    }

    if (!taskManager.moveTask(task, fromBoard, toBoard)) {
        throw std::runtime_error("Falha ao mover a tarefa.");
    }
}

Board* User::getBoard(const std::string& boardName) const {
    for(auto& board : boards) {
        if(board->getName() == boardName) {
            return board.get();
        }
    }
    return nullptr;
}
