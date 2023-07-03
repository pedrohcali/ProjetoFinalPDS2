// TaskManager.hpp
#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>
#include "Task.hpp"
#include "Board.hpp"

class TaskManager {
public:
    TaskManager();

    Task* createTask(const std::string& title, const std::string& description, const std::string& dueDate);
    Task* getTask(Board* board, const std::string& taskTitle);
    bool addTask(Board* board, Task* task);
    bool removeTask(Board* board, Task* task);
    std::vector<Task*> getTasks(Board* board);
    std::vector<Task*> getTasksSortedByName(Board* board);
    std::vector<Task*> getTasksSortedByDueDate(Board* board);
    bool moveTask(Task* task, Board* fromBoard, Board* toBoard);
    void editTask(Task* task, const std::string& newTitle, const std::string& newDescription, const std::string& newDueDate);
};

#endif // TASK_MANAGER_H

