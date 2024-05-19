#include "login.h"
#include <windows.h>
#include <iomanip>

bool LogIn::saveToDatabase(sql::Connection* con) {
    SetConsoleOutputCP(1251);
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO login (employee_id, login, password) VALUES (?, ?, ?)");
        pstmt->setInt(1, employee_id);
        pstmt->setString(2, login);
        pstmt->setString(3, password);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Помилка: " << e.what() << endl;
        return false;
    }
}

LogIn LogIn::loadFromDatabase(sql::Connection* con, const int& id) {
    SetConsoleOutputCP(1251);
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("SELECT employee_id, login, password FROM login WHERE id = ?");
        pstmt->setInt(1, id);
        sql::ResultSet* res = pstmt->executeQuery();
        int employee_id = 0;
        string login = "";
        string password = "";
        if (res->next()) {
            employee_id = res->getInt("employee_id");
            login = res->getString("login");
            password = res->getString("password");
        }
        delete res;
        delete pstmt;
        return LogIn(id, employee_id, login, password);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Помилка: " << e.what() << std::endl;
        return LogIn();
    }
}

void LogIn::Print() {
    cout << "| " << setw(14) << employee_id << "| " << setw(20) << login << " | " << setw(14) << password << "|" << endl;
}