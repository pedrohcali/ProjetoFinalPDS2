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

    // Cria uma nova tarefa com o título, descrição e data de vencimento fornecidos
    Task* createTask(const std::string& title, const std::string& description = "-", const std::string& dueDate = "");

    // Obtém uma tarefa com base em seu título e no objeto Board especificado
    Task* getTask(Board* board, const std::string& taskTitle);

    // Adiciona uma tarefa ao objeto Board especificado. Retorna true se a tarefa for adicionada com sucesso, ou false caso contrário
    bool addTask(Board* board, Task* task);

    // Remove uma tarefa do objeto Board especificado. Retorna true se a tarefa for removida com sucesso, ou false caso contrário
    bool removeTask(Board* board, Task* task);

    // Obtém todas as tarefas do objeto Board especificado. Retorna um vetor de ponteiros para as tarefas.
    std::vector<Task*> getTasks(Board* board);

     // Obtém todas as tarefas do objeto Board especificado, ordenadas por nome.
    std::vector<Task*> getTasksSortedByName(Board* board);

    // Obtém todas as tarefas do objeto Board especificado, ordenadas por data de vencimento.
    std::vector<Task*> getTasksSortedByDueDate(Board* board);

    // Move uma tarefa de um objeto Board de origem para um objeto Board de destino
    bool moveTask(Task* task, Board* fromBoard, Board* toBoard);

    // Edita uma tarefa com base em um novo título, nova descrição e nova data de vencimento fornecidos.
    void editTask(Task* task, const std::string& newTitle, const std::string& newDescription, const std::string& newDueDate);
};

#endif // TASK_MANAGER_H
