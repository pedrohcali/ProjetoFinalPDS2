#include "User.hpp"
#include "Board.hpp"
#include "Task.hpp"
#include <algorithm>

User::User(const std::string& username, const std::string& email, TaskManager& taskManager)
    : username(username), email(email), taskManager(taskManager) {
}

User::~User() {
}

const std::string& User::getUsername() const {
    return username;
}

void User::setUsername(const std::string& username) {
    this->username = username;
}

const std::string& User::getEmail() const {
    return email;
}

void User::setEmail(const std::string& email) {
    this->email = email;
}

const std::vector<std::unique_ptr<Board>>& User::getBoards() const {
    return boards;
}

void User::addBoard(std::unique_ptr<Board> board) {
    boards.push_back(std::move(board));
}

void User::removeBoard(const std::string& boardName) {
    // Implementar mecanismo para buscar o quadro pelo nome
    auto it = std::find_if(boards.begin(), boards.end(), [&boardName](const auto& board) {
        return board->getName() == boardName;
    });
    
    if (it != boards.end()) {
        boards.erase(it);
    }
}

void User::moveTask(Board* fromBoard, Board* toBoard, Task* task) {
    if(taskManager.moveTask(task, fromBoard, toBoard)) {
        // Nada. Deu certo a movida. Talvez implementar validação de erros.
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
