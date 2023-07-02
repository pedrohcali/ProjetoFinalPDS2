#include "Task.hpp"

Task::Task(const std::string& title, const std::string& description, const std::string& dueDate)
: title(title), description(description), dueDate(dueDate) {}

std::string Task::getTitle() const {
    return title;
}

void Task::setTitle(const std::string& title) {
    this->title = title;
}

std::string Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}

std::string Task::getDueDate() const {
    return dueDate;
}

void Task::setDueDate(const std::string& dueDate) {
    this->dueDate = dueDate;
}
