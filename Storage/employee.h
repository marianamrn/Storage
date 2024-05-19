#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "person.h"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

struct StartWorking {
    int year;
    int month;
    int day;
};

class Employee : public Person {
protected:
    StartWorking startWorkingDate;
    string post; // посада
    int productivity;
    double salary;
    string shift;
    string position; // робоче місце
public:
    Employee() : Person(0, "", "", "", { 0,0,0 }), startWorkingDate({0,0,0}), post(""), productivity(0), salary(0.0), shift(""), position("") {}
    Employee(int id, string firstName, string lastName, string surname, Date birthDate, 
        StartWorking startWorkingDate, string post, int productivity, double salary, string shift, string position) :
        Person(id, firstName, lastName, surname, birthDate), startWorkingDate(startWorkingDate), post(post), productivity(productivity), salary(salary), shift(shift), position(position) {}
    ~Employee() {}

    StartWorking getStartWorkingDate() const { return startWorkingDate; }
    void setStartWorkingDate(StartWorking newStartWorkingDate) { startWorkingDate = newStartWorkingDate; }

    string getPost() const { return post; }
    void setPost(string newPost) { post = newPost; }

    int getProductivity() const { return productivity; }
    void setProductivity(int newProductivity) { productivity = newProductivity; }

    double getSalary() const { return salary; }
    void setSalary(double newSalary) { salary = newSalary; }

    string getShift() const { return shift; }
    void setShift(string newShift) { shift = newShift; }

    string getPosition() const { return position; }
    void setPosition(string newPosition) { position = newPosition; }

    bool saveToDatabase(sql::Connection* con);
    static Employee loadFromDatabase(sql::Connection* con, const int& id);
    
    void Print();

    friend ostream& operator<<(ostream& os, const Employee& obj);
};

#endif // EMPLOYEE_H
#pragma once
