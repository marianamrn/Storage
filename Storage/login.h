#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

class LogIn {
protected:
    int id;
    int employee_id;
    string login;
    string password;
public:
    LogIn() {};
    LogIn(int id, int employee_id, string login, string password) : id(id), employee_id(employee_id), login(login), password(password) {}
    ~LogIn() {}

    int getId() { return id; }

    int getEmployeeId() { return employee_id;  }
    void setEmployeeId(int newEmployeeId) { employee_id = newEmployeeId; }

    string getLogin() { return login;  }
    void setLogin(string newLogin) { login = newLogin; }

    string getPassword() { return password; }
    void setPassword(string newPassword) { password = newPassword; }

    bool saveToDatabase(sql::Connection* con);
    static LogIn loadFromDatabase(sql::Connection* con, const int& id);

    void Print();
};

#endif // LOGIN_H
#pragma once
