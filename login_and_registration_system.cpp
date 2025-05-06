#include <iostream>
#include <fstream>
#include <string>
#include <limits> // For input validation

using namespace std;

const string USER_FILE = "users.txt";

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void registerUser() {
    string username, password;

    cout << "\n--- Register ---" << endl;
    
    // Input validation for username
    while (true) {
        cout << "Enter username (no spaces): ";
        cin >> username;
        
        // Check if username already exists
        ifstream checkFile(USER_FILE);
        string existingUser, existingPass;
        bool exists = false;
        while (checkFile >> existingUser >> existingPass) {
            if (existingUser == username) {
                exists = true;
                break;
            }
        }
        checkFile.close();
        
        if (exists) {
            cout << "Username already exists. Please choose another.\n";
        } else {
            break;
        }
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file(USER_FILE, ios::app); // Append mode
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cerr << "Error: Unable to open user database.\n";
    }
}

void loginUser() {
    string username, password, u, p;
    bool found = false;

    cout << "\n--- Login ---" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(USER_FILE);
    if (file.is_open()) {
        while (file >> u >> p) {
            if (u == username && p == password) {
                found = true;
                break;
            }
        }
        file.close();

        if (found) {
            cout << "Login successful! Welcome, " << username << "!\n";
        } else {
            cout << "Invalid credentials.\n";
        }
    } else {
        cerr << "Error: Unable to open user database.\n";
    }
}

int main() {
    int choice;

    cout << "=== Login and Registration System ===" << endl;

    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
        
        // Input validation for menu choice
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number (1-3): ";
            clearInputBuffer();
        }

        switch (choice) {
            case 1: 
                registerUser(); 
                break;
            case 2: 
                loginUser(); 
                break;
            case 3: 
                cout << "Exiting program. Goodbye!\n";
                exit(0);
            default: 
                cout << "Invalid option. Please try again.\n";
                clearInputBuffer();
        }
    }

    return 0;
}