#include <iostream>
#include <string>
using namespace std;

const int SIZE_ARR = 26;

struct Hashtable {
    string username, password;
} dataAkun[SIZE_ARR];

int hashfunction(string password) {
    return tolower(password[0]) - 'a';
}

void printall() {
    for (int i = 0; i < SIZE_ARR; i++) {
        cout << i << "(" << dataAkun[i].username << " - " << dataAkun[i].password << ")" << endl;
    }
}

void menu() {
    while (true) {
        int input_user;
        cout << "Menu" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl << endl;

        cout << "Pilih: ";
        cin >> input_user;
        cout << endl;

        if (input_user == 1) {
            string username, password;

            cout << "Masukkan Username: ";
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;

            int index = hashfunction(password);

            if (!dataAkun[index].username.empty() && !dataAkun[index].password.empty()) {
                cout << "Data akun sudah tersedia!" << endl;
            } else {
                dataAkun[index].username = username;
                dataAkun[index].password = password;
                cout << "Akun berhasil terdaftar!" << endl;
            }
        } else if (input_user == 2) {
            string username, password;

            cout << "Masukkan Username: ";
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;

            int index = hashfunction(password);

            if (dataAkun[index].username == username && dataAkun[index].password == password) {
                cout << "Login berhasil!" << endl;
            } else {
                cout << "Login gagal. Username atau password salah." << endl;
            }
        } else if (input_user == 3) {
            printall();
            break;
        }
    }
}

int main() {
    menu();
    return 0;
}
