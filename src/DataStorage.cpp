#include "DataStorage.hpp"
#include <fstream>
#include <algorithm>

DataStorage::DataStorage(const std::string& filename, TaskManager& taskManager) 
    : filename(filename), taskManager(taskManager) {
}

DataStorage::~DataStorage() {
}

void DataStorage::saveData() {
    std::ofstream file(filename);
    for (const auto& user : users) {
        file << user->getUsername() << "\n";
    }
}

void DataStorage::loadData() {
    std::ifstream file(filename);
    std::string username;
    std::string email;
    while (std::getline(file, username) && std::getline(file, email)) {
        addUser(std::make_unique<User>(username, email, taskManager));
    }
}

std::vector<std::unique_ptr<User>>& DataStorage::getUsers() {
    return users;
}

User* DataStorage::getUser(const std::string& username) {
    auto it = std::find_if(users.begin(), users.end(), [&username](const std::unique_ptr<User>& user) {
        return user->getUsername() == username;
    });
    return it != users.end() ? it->get() : nullptr;
}

void DataStorage::addUser(std::unique_ptr<User> user) {
    users.push_back(std::move(user));
}

void DataStorage::removeUser(const std::string& username) {
    users.erase(std::remove_if(users.begin(), users.end(), [&username](const std::unique_ptr<User>& user) {
        return user->getUsername() == username;
    }), users.end());
}