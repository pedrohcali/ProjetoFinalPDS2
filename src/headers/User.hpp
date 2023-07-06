#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "TaskManager.hpp"
#include <memory>

class Board; // Incluindo antes para usar na classe

class User {
public:
    User(const std::string& username, const std::string& email, TaskManager& taskManager);
    ~User();

    const std::string& getUsername() const;
    void setUsername(const std::string& username);

    const std::string& getEmail() const;
    void setEmail(const std::string& email);

    const std::vector<std::unique_ptr<Board>>& getBoards() const;
    void addBoard(std::unique_ptr<Board> board);
    void removeBoard(const std::string& boardName);
    
    void moveTask(Board* fromBoard, Board* toBoard, Task* task);

    Board* getBoard(const std::string& boardName) const;

private:
    std::string username;
    std::string email;
    std::vector<std::unique_ptr<Board>> boards;
    TaskManager& taskManager;
};

#endif // USER_H
