#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <vector>
#include <memory>
#include "User.hpp"
#include "TaskManager.hpp"

class DataStorage {
private:
    std::string filename;
    std::vector<std::unique_ptr<User>> users;
    TaskManager& taskManager;
public:
    DataStorage(const std::string& filename, TaskManager& taskManager);
    ~DataStorage();

    void saveData();
    void loadData();

    std::vector<std::unique_ptr<User>>& getUsers();
    User* getUser(const std::string& username);
    void addUser(std::unique_ptr<User> user);
    void removeUser(const std::string& username);
};

#endif // DATASTORAGE_H
