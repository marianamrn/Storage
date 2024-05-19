#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

class Person {
protected:
    int id;
    string firstName;
    string lastName;
    string surname;
    Date birthDate;
public:
    Person() : id(0), firstName(""), lastName(""), surname(""), birthDate({ 0, 0, 0 }) {}
    Person(int id, string firstName, string lastName, string surname, Date birthDate) :
        id(id), firstName(firstName), lastName(lastName), surname(surname), birthDate(birthDate) {}
    ~Person() {}

    int getID() const { return id; }
    void setID(int newId) { id = newId; }

    string getFirstName() const { return firstName; }
    void setFirstName(string newFirstName) { firstName = newFirstName; }

    string getLastName() const { return lastName; }
    void setLastName(string newLastName) { lastName = newLastName; }

    string getSurname() const { return surname; }
    void setSurname(string newSurname) { surname = newSurname; }

    Date getBirthDate() const { return birthDate; }
    void setBirthDate(Date newBirthDate) { birthDate = newBirthDate; }
};

#endif // PERSON_H
#pragma once
