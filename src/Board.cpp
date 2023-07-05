#include "Board.hpp"
#include <algorithm> // Para usar std::find
#include <stdexcept> // Para usar std::invalid_argument
#include <cctype> // Para usar std::isalnum e std::isspace

Board::Board(const std::string& name)
    : tasks() {
    setName(name);
}

Board::~Board() {
    // Nada a fazer aqui, já que os Tasks são gerenciados por TaskManager
}

const std::string& Board::getName() const {
    return name;
}

void Board::setName(const std::string& name) {
    // Checar se o nome é vazio
    if (name.empty()) {
        throw std::invalid_argument("Nome do quadro nao pode ser vazio.");
    }

    // // Checar se o nome é longo demais
    // if (name.size() > 50) {
    //     throw std::invalid_argument("Nome do quadro nao pode ter mais de 50 caracteres.");
    // }

    // // Checar se o nome contém caracteres inválidos
    // for (char c : name) {
    //     if (!std::isalnum(c) && !std::isspace(c)) {
    //         throw std::invalid_argument("Nome do quadro contem caracteres invalidos.");
    //     }
    // }

    this->name = name;
}

std::vector<Task*>& Board::getTasks() {
    return tasks;
}

bool Board::addTask(Task* task) {
    // Checar se a task já existe no Board
    auto it = std::find(tasks.begin(), tasks.end(), task);
    if (it == tasks.end()) {
        tasks.push_back(task);
        return true;
    } 
    else {
        return false;
    }
}

bool Board::removeTask(Task* task) {
    // Remover a task do Board
    auto it = std::find(tasks.begin(), tasks.end(), task);
    if (it != tasks.end()) {
        tasks.erase(it);
        return true;
    } 
    else {
        return false;
    }
}
