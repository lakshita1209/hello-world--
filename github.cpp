#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function declarations
void signUp(unordered_map<string, string> &users, unordered_map<string, int> &balances);
bool login(const unordered_map<string, string> &users, string &loggedInUser);
void checkBalance(const unordered_map<string, int> &balances, const string &loggedInUser);

int main() {
    unordered_map<string, string> users;
    unordered_map<string, int> balances;
    int choice;
    string loggedInUser;

    while (true) {
        cout << "\nBanking System\n";
        cout << "1. Signup\n";
        cout << "2. Login\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                signUp(users, balances);
                break;
            case 2:
                if (login(users, loggedInUser)) {
                    cout << "Login successful!\n";
                } else {
                    cout << "Invalid username or password.\n";
                }
                break;
            case 3:
                if (!loggedInUser.empty()) {
                    checkBalance(balances, loggedInUser);
                } else {
                    cout << "You must be logged in to check your balance.\n";
                }
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void signUp(unordered_map<string, string> &users, unordered_map<string, int> &balances) {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    if (users.find(username) != users.end()) {
        cout << "Username already exists. Please choose another username.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    users[username] = password;
    balances[username] = 0; // Initial balance is ₹0
    cout << "Signup successful!\n";
}

bool login(const unordered_map<string, string> &users, string &loggedInUser) {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        loggedInUser = username;
        return true;
    }
    return false;
}

void checkBalance(const unordered_map<string, int> &balances, const string &loggedInUser) {
    cout << "Your current balance is: ₹" << balances.at(loggedInUser) << endl;
}