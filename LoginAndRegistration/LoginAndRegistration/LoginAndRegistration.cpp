#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;
bool IsLogged() {
    string username, password, un, ps;
    cout << "Введите логин: ";
    cin >> username;
    cout << "Введите пароль: ";
    cin >> password;
    fstream read;
    read.open("a.txt", ios::in);
    read >> un;
    read >> ps;
    if ((username == un) && (password == ps)) {
        return true;
    }
    else {
        return false;
    }
}
bool IsValidLogin(string login) {
    regex reg("^[a-z0-9_][a-z0-9_\.-]*[a-z0-9_]@([a-z0-9_]+[a-z0-9_-]\.)+[a-z0-9]{2,}$", regex_constants::icase);
    return regex_search(login, reg);
}
int main()
{
    setlocale(LC_ALL, "");
    cout << "Выберите операцию: " << endl;
    cout << "1) Регистрация" << endl;
    cout << "2) Авторизация" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        string username, password;
        cout << "Введите логин: ";
        cin >> username;
        if (IsValidLogin(username)) {
            cout << "Неправильный логин";
            return 0;
        }
        cout << "Введите пароль: ";
        cin >> password;
        fstream file;
        file.open("a.txt", ios::out);
        file << username << endl << password;
        file.close();
        main();
    }
    else if (choice == 2) {
        bool status = IsLogged();
        if (!status) {
            cout << "Неправильный логин";
            return 0;
        }
        else {
            cout << "Вы успешно вошли";
            return 1;
        }
    }
    setlocale(LC_ALL, "");
}