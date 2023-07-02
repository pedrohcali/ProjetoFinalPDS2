#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
    std::string title;
    std::string description;
    std::string dueDate;

public:
    Task(const std::string& title, const std::string& description, const std::string& dueDate);

    std::string getTitle() const;
    void setTitle(const std::string& title);

    std::string getDescription() const;
    void setDescription(const std::string& description);

    std::string getDueDate() const;
    void setDueDate(const std::string& dueDate);
};

#endif //TASK_H
