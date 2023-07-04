#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include "User.hpp"
#include "TaskManager.hpp"

class DataStorage {
private:
    std::string filename;
    std::vector<std::unique_ptr<User>> users;
    TaskManager& taskManager;
public:
    // Pode lançar std::invalid_argument se filename for vazio.
    DataStorage(const std::string& filename, TaskManager& taskManager);

    ~DataStorage();

    // Pode lançar std::runtime_error se o arquivo não puder ser aberto para escrita.
    void saveData();

    // Pode lançar std::runtime_error se o arquivo não puder ser aberto para leitura ou se o formato do arquivo for inválido.
    void loadData();

    std::vector<std::unique_ptr<User>>& getUsers();

    User* getUser(const std::string& username);

    // Pode lançar std::invalid_argument se user for nulo.
    void addUser(std::unique_ptr<User> user);

    // Pode lançar std::runtime_error se o usuário não for encontrado.
    void removeUser(const std::string& username);
};

#endif // DATASTORAGE_H
