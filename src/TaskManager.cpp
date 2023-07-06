// TaskManager.cpp
#include "TaskManager.hpp"
#include <algorithm> // Para usar std::sort
#include <stdexcept> // Para usar std::invalid_argument
#include <regex> // Para determinar o formato correto da data (YYYY-MM-DD)

TaskManager::TaskManager() {
}

Task* TaskManager::createTask(const std::string& title, const std::string& description, const std::string& dueDate) {
    if (title.empty()) {
        throw std::invalid_argument("O titulo da tarefa nao pode estar vazio.");
    }

    // Verifica o formato correto da data
    std::regex datePattern("\\d{4}-\\d{2}-\\d{2}");
    if (!std::regex_match(dueDate, datePattern)) {
        throw std::invalid_argument("Data de vencimento nao esta no formato YYYY-MM-DD");
    }
    
    return new Task(title, description, dueDate);
}

// Procura uma tarefa específica dentro de um quadro
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

// Obtém todas as tarefas associadas a um quadro
std::vector<Task*> TaskManager::getTasks(Board* board) {
    if (!board) {
        return {};
    }
    return board->getTasks();
}

// Ordena as tarefas por título
std::vector<Task*> TaskManager::getTasksSortedByName(Board* board) {
    std::vector<Task*> tasks = getTasks(board);
    std::sort(tasks.begin(), tasks.end(), [](const Task* lhs, const Task* rhs) {
        return lhs->getTitle() < rhs->getTitle();
    });
    return tasks;
}

// Ordena as tarefas por data de vencimento
std::vector<Task*> TaskManager::getTasksSortedByDueDate(Board* board) {
    std::vector<Task*> tasks = getTasks(board);
    std::sort(tasks.begin(), tasks.end(), [](const Task* lhs, const Task* rhs) {
        return lhs->getDueDate() < rhs->getDueDate();
    });
    return tasks;
}

// Permite mover a tarefa de um quadro para outro
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

// Para editar os atributos de uma determinada tarefa
void TaskManager::editTask(Task* task, const std::string& newTitle, const std::string& newDescription, const std::string& newDueDate) {
    if (!task) {
        throw std::invalid_argument("Tarefa nao pode ser nula para edicao.");
    }

    if (newTitle.empty()) {
        throw std::invalid_argument("O titulo da tarefa nao pode estar vazio.");
    }
    task->setTitle(newTitle);
    task->setDescription(newDescription);
    task->setDueDate(newDueDate);
}
