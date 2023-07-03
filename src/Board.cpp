#include "Board.hpp"
#include <algorithm> // Para usar std::find

Board::Board(const std::string& name)
    : name(name), tasks() {
}

Board::~Board() {
    // Nada a fazer aqui, já que os Tasks são gerenciados por TaskManager
}

const std::string& Board::getName() const {
    return name;
}

void Board::setName(const std::string& name) {
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
    return false;
}

bool Board::removeTask(Task* task) {
    // Remover a task do Board
    auto it = std::find(tasks.begin(), tasks.end(), task);
    if (it != tasks.end()) {
        tasks.erase(it);
        return true;
    }
    return false;
}
