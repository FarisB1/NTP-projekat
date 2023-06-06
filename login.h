#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <functional>
using namespace std;
void registerUser() {
    string fullName, username, password;

    cout << "Unesite ime i prezime: ";
    cin.ignore();
    getline(cin, fullName);

    cout << "Unesite username: ";
    cin >> username;

    cout << "Unesite password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << "," << password << "," << fullName << endl;
        cout << "Registracija uspjesna!" << endl;
        file.close();
    } else {
        cerr << "Problem sa otvaranjem fajla." << endl;
    }
}

bool userExists(const string& username, const string& password) {
    ifstream file("users.txt");
    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            stringstream ss(line);
            string storedUsername, storedPassword;

            getline(ss, storedUsername, ',');
            getline(ss, storedPassword, ',');

            if (storedUsername == username && storedPassword == password) {
                file.close();
                return true;
            }
        }

        file.close();
    } else {
        cerr << "Problem sa otvaranjem fajla." << endl;
    }

    return false;
}


bool login() {
    string username, password;

    cout << "Unesite username: ";
    cin >> username;

    cout << "Unesite password: ";
    cin >> password;

    if (userExists(username, password)) {
        cout << "Uspjesan login!" << endl;
        return true;
    } else {
        cout << "Pogresan username ili password." << endl;
		return false;
		}
}

void prviMeni()
{
	int choice;
		while (true) {
        cout << "Dobrodosli!" << endl;
        cout << "1. Registracija" << endl;
        cout << "2. Login" << endl;
        cout << "3. Izlaz" << endl;
        cout << "Unos: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (login()) {
                	Sleep(900);
					system("cls");
					return;
				}
                break;
            case 3:
            	exit(0);
				break;
            default:
                cout << "Pogresan unos." << endl;
                break;
        }
    }

}

