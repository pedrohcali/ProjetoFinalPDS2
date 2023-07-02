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

    void setName(const std::string& name);

    std::vector<Task*>& getTasks();

    bool addTask(Task* task);

    bool removeTask(Task* task);

private:
    std::string name;
    std::vector<Task*> tasks;
};

#endif // BOARD_H
