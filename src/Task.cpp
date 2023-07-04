#include "Task.hpp"
#include <regex>
#include <stdexcept>

Task::Task(const std::string& title, const std::string& description, const std::string& dueDate)
: title(title), description(description), dueDate(dueDate) {}

std::string Task::getTitle() const {
    return title;
}

void Task::setTitle(const std::string& title) {
    if (title.empty()) {
        throw std::invalid_argument("Titulo nao pode ser vazio");
    }
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
    std::regex datePattern("\\d{4}-\\d{2}-\\d{2}");
    if (!std::regex_match(dueDate, datePattern)) {
        throw std::invalid_argument("Data de vencimento nao esta no formato YYYY-MM-DD");
    }
    this->dueDate = dueDate;
}
