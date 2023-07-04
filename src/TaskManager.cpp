// TaskManager.cpp
#include "TaskManager.hpp"
#include <algorithm>
#include <stdexcept>

TaskManager::TaskManager() {
}

Task* TaskManager::createTask(const std::string& title, const std::string& description, const std::string& dueDate) {
    if (title.empty()) {
        throw std::invalid_argument("O título da tarefa não pode estar vazio.");
    }
    return new Task(title, description, dueDate);
}

Task* TaskManager::getTask(Board* board, const std::string& taskTitle) {
    if (!board) {
        return nullptr;
    }
    std::vector<Task*> tasks = getTasks(board);
    for (Task* task : tasks) {
        if (task->getTitle() == taskTitle) {
            return task;
        }
    }
    return nullptr;
}


bool TaskManager::addTask(Board* board, Task* task) {
    if (!board || !task) {
        return false;
    }
    return board->addTask(task);
}

bool TaskManager::removeTask(Board* board, Task* task) {
    if (!board || !task) {
        return false;
    }
    return board->removeTask(task);
}

std::vector<Task*> TaskManager::getTasks(Board* board) {
    if (!board) {
        return {};
    }
    return board->getTasks();
}

std::vector<Task*> TaskManager::getTasksSortedByName(Board* board) {
    std::vector<Task*> tasks = getTasks(board);
    std::sort(tasks.begin(), tasks.end(), [](const Task* lhs, const Task* rhs) {
        return lhs->getTitle() < rhs->getTitle();
    });
    return tasks;
}

std::vector<Task*> TaskManager::getTasksSortedByDueDate(Board* board) {
    std::vector<Task*> tasks = getTasks(board);
    std::sort(tasks.begin(), tasks.end(), [](const Task* lhs, const Task* rhs) {
        return lhs->getDueDate() < rhs->getDueDate();
    });
    return tasks;
}

bool TaskManager::moveTask(Task* task, Board* fromBoard, Board* toBoard) {
    if (!task || !fromBoard || !toBoard) {
        return false;
    }
    if (fromBoard->removeTask(task)) {
        toBoard->addTask(task);
        return true;
    }
    return false;
}

void TaskManager::editTask(Task* task, const std::string& newTitle, const std::string& newDescription, const std::string& newDueDate) {
    if (!task) {
        throw std::invalid_argument("Tarefa não pode ser nula para edição.");
    }

    if (newTitle.empty()) {
        throw std::invalid_argument("O título da tarefa não pode estar vazio.");
    }
    task->setTitle(newTitle);
    task->setDescription(newDescription);
    task->setDueDate(newDueDate);
}
