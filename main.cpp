#include <iostream>
#include "bank_customer.h"
#include "buyer.h"

enum PrimaryPrompt{LOGIN, REGISTER, EXIT};

using namespace std;

void createSellerMenu() {
    string storeName, storeAddress, storePhone, storeEmail;
        cout << "--- Create a new Seller Account ---\n";
        cout << "Enter Store Name: ";
        cin.ignore();
        getline(cin, storeName);
        cout << "Enter Store Address: ";
        getline(cin, storeAddress);
        cout << "Enter Store Phone Number: ";
        getline(cin, storePhone);
        cout << "Enter Store Email: ";
        getline(cin, storeEmail);
        cout << "Seller account '" << storeName << "' created.\n";
}

void registerAccount(){
    string name, address, phone, email;
        cout << "--- Create a new Buyer Account ---\n";
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Home Address: ";
        getline(cin, address);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Buyer account for " << name << " created successfully!\n";
}

void showBuyerMenu() {
    int userChoice;
    bool upgradeToseller = true;
    do {
        cout << "\n--- Buyer Menu ---\n";
        cout << "1. Check Account Status\n";
        cout << "2. Upgrade Account to Seller\n";
        cout << "3. Logout\n";
        cout << "Select an option: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                cout << "Checking account status...\n";
                break;
            case 2: {
                if (upgradeToseller) {
                    cout << "Upgrading account to Seller...\n";
                    string storeName, storeAddress, storePhone, storeEmail;
                    cout << "Enter Store Name: ";
                    cin.ignore();
                    getline(cin, storeName);
                    cout << "Enter Store Address: ";
                    getline(cin, storeAddress);
                    cout << "Enter Store Phone Number: ";
                    getline(cin, storePhone);
                    cout << "Enter Store Email: ";
                    getline(cin, storeEmail);
                    cout << "Seller account created successfully!\n";
                    upgradeToseller = false;
                }else {
                    cout << "You already have a Seller account.\n";
                }
            break;
            }
            case 3:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (userChoice != 3);
}

int main() {
    //create a loop prompt
    bool isLoggedIn = false;
    PrimaryPrompt prompt = LOGIN;
    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);
        switch (prompt) {
            case LOGIN: {
                cout << "Login selected." << endl;
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (username == "user" && password == "password") {
                    cout << "Login successful!" << endl;
                    isLoggedIn = true;
                    showBuyerMenu(); 
                    isLoggedIn = false; 
                } else {
                    cout << "Invalid credentials." << endl;
                }
                break;
            }
            case REGISTER: {
                cout << "Register selected." << endl;
                    registerAccount();
                    char createSeller;
                    cout << "Do you want to create a Seller account as well? (y/n): ";
                    cin >> createSeller;
                    if (createSeller == 'y' || createSeller == 'Y') {
                        createSellerMenu();}
                    isLoggedIn = true; 
                    cout << "\nRegistration complete. Automatically logging in..." << endl;
                    showBuyerMenu();
                    isLoggedIn = false;
                break;
                }
                break;
            case EXIT:
                cout << "Exiting." << std::endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }

    //BankCustomer customer1(1, "Alice", 1000.0);
    //Buyer buyer1(1, customer1.getName(), customer1);
    return 1;
}