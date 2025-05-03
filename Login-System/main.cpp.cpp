#include <iostream>
#include "auth.h"

int main() {
    AuthSystem auth;
    auth.loadUsers();  // Load existing users
    
    while(true) {
        std::cout << "1. Register\n2. Login\n3. Exit\n";
        int choice;
        std::cin >> choice;
        
        if(choice == 3) break;
        
        switch(choice) {
            case 1: auth.registerUser(); break;
            case 2: auth.loginUser(); break;
            default: std::cout << "Invalid choice!\n";
        }
    }
    return 0;
}