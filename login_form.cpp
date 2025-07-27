#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string userName, Email, Password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUP();
    void forgot();
} obj;

int main() {
    char choice;
    while (true) {
        cout << "\n 1 - Login ";
        cout << "\n 2 - Sign up";
        cout << "\n 3 - Forgot Password";
        cout << "\n 4 - Exit";
        cout << "\n Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the buffer before getline()

        switch (choice) {
            case '1':
                obj.login();
                break;
            case '2':
                obj.signUP();
                break;
            case '3':
                obj.forgot();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Choice...!" << endl;
                break;
        }
    }
}

// -------------------- SIGN UP -----------------------
void temp::signUP() {
    cout << "\n Enter Your User Name: ";
    getline(cin, userName);
    cout << "\n Enter Your Email Address: ";
    getline(cin, Email);
    cout << "\n Enter Your Password: ";
    getline(cin, Password);

    file.open("loginData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << userName << "*" << Email << "*" << Password << "\n";
        file.close();
        cout << "Account Created Successfully!\n";
    } else {
        cout << "Error opening file for writing.\n";
    }
}

// -------------------- LOGIN -----------------------
void temp::login() {
    cout << "\n----------------LOGIN--------------------\n";
    cout << "Enter Your User Name: ";
    getline(cin, searchName);
    cout << "Enter Your Password: ";
    getline(cin, searchPass);

    bool found = false;
    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, userName, '*') &&
               getline(file, Email, '*') &&
               getline(file, Password)) {
            if (userName == searchName) {
                found = true;
                if (Password == searchPass) {
                    cout << "\nLogin Successful...!\n";
                    cout << "UserName: " << userName << endl;
                    cout << "Email: " << Email << endl;
                } else {
                    cout << "Incorrect Password!!!\n";
                }
                break;
            }
        }
        file.close();
        if (!found) {
            cout << "Account Not Found...!\n";
        }
    } else {
        cout << "Error opening file for reading.\n";
    }
}

// -------------------- FORGOT PASSWORD -----------------------
void temp::forgot() {
    cout << "\nEnter Your User Name: ";
    getline(cin, searchName);
    cout << "Enter Your Email Address: ";
    getline(cin, searchEmail);

    bool found = false;
    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, userName, '*') &&
               getline(file, Email, '*') &&
               getline(file, Password)) {
            if (userName == searchName && Email == searchEmail) {
                found = true;
                cout << "\nAccount Found...!\n";
                cout << "Your Password is: " << Password << endl;
                break;
            }
        }
        file.close();
        if (!found) {
            cout << "Record Not Found...!\n";
        }
    } else {
        cout << "Error opening file for reading.\n";
    }
}
