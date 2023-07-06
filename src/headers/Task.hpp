#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
    std::string title;
    std::string description;
    std::string dueDate;

public:
    // Lança std::invalid_argument se o titulo estiver vazio
    Task(const std::string& title, const std::string& description, const std::string& dueDate);

    // Retorna o titulo da tarefa.
    std::string getTitle() const;

    // Define o titulo da tarefa. Lança std::invalid_argument se o titulo estiver vazio.
    void setTitle(const std::string& title);

    // Retorna a descricao da tarefa.
    std::string getDescription() const;

    // Define a descricao da tarefa.
    void setDescription(const std::string& description);

    // Retorna a data limite da tarefa.
    std::string getDueDate() const;

    // Define a data limite da tarefa. 
    void setDueDate(const std::string& dueDate);
};

#endif //TASK_H
