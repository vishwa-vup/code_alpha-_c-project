#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    User() {}

    bool usernameExists(const string &user)
    {
        ifstream file("users.txt");

        string u, p;

        while (file >> u >> p)
        {
            if (u == user)
                return true;
        }

        return false;
    }

    void registerUser()
    {
        cout << "\n========== USER REGISTRATION ==========\n";

        cout << "Enter Username: ";
        cin >> username;

        if (usernameExists(username))
        {
            cout << "\nUsername already exists.\n";
            return;
        }

        string confirmPassword;

        cout << "Enter Password: ";
        cin >> password;

        cout << "Confirm Password: ";
        cin >> confirmPassword;

        if (password != confirmPassword)
        {
            cout << "\nPasswords do not match.\n";
            return;
        }

        ofstream file("users.txt", ios::app);

        file << username << " " << password << endl;

        file.close();

        cout << "\nRegistration Successful!\n";
    }

    void loginUser()
    {
        cout << "\n============= LOGIN =============\n";

        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        ifstream file("users.txt");

        string u, p;
        bool found = false;

        while (file >> u >> p)
        {
            if (u == username && p == password)
            {
                found = true;
                break;
            }
        }

        file.close();

        if (found)
        {
            cout << "\nLogin Successful!\n";
            cout << "Welcome, " << username << "!\n";
        }
        else
        {
            cout << "\nInvalid Username or Password.\n";
        }
    }
};

class LoginSystem
{
private:
    User user;

public:
    void menu()
    {
        int choice;

        do
        {
            cout << "\n=========================================\n";
            cout << " LOGIN & REGISTRATION SYSTEM\n";
            cout << "=========================================\n";
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "3. Exit\n";
            cout << "-----------------------------------------\n";
            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                user.registerUser();
                break;

            case 2:
                user.loginUser();
                break;

            case 3:
                cout << "\nThank you for using the system.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
            }

        } while (choice != 3);
    }
};

int main()
{
    LoginSystem system;

    system.menu();

    return 0;
}