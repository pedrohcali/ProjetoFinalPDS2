#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "Task.hpp"

class Board {
public:
    Board(const std::string& name);

    ~Board();

    const std::string& getName() const;

    std::vector<Task*>& getTasks();

    void setName(const std::string& name); // Lança std::invalid_argument se o nome for inválido
    bool addTask(Task* task); // Lança std::invalid_argument se a tarefa já existir no quadro
    bool removeTask(Task* task); // Lança std::invalid_argument se a tarefa não for encontrada no quadro

private:
    std::string name;
    std::vector<Task*> tasks;
};

#endif // BOARD_H
