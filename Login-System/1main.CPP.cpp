#pragma once
#include <string>
#include <map>

class AuthSystem {
    std::map<std::string, std::string> users;
    const std::string dbFile = "data/users.txt";
    
public:
    void registerUser();
    bool loginUser();
    void loadUsers();
    void saveUsers();
};