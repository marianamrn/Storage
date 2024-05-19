#ifndef CONSOLE_H
#define CONSOLE_H

#include "managementSystem.h"

class CONSOLE {
private:
    managementSystem system;
public:
    CONSOLE() {}
    ~CONSOLE() {}

    bool LOGIN();
    bool LOGOUT();
    void Clear();
    void Menu();

    void PrintFootwear();
    void AddFootwear();
    void SearchFootwear();
    void SearchFootwearByCategory();
    void SearchFootwearByBrand();
    void FootwearRemains();
    void DeleteFootwear();

    void PrintBags();
    void AddBags();
    void SearchBags();
    void SearchBagsByCategory();
    void SearchBagsByBrand();
    void BagsRemains();
    void DeleteBags();

    void PrintEmployee();
    void AddEmployee();
    void SearchEnployee();
    void ChangeEnployeePosition();
    void ChackProductivity();
    void DeleteEmployee();

    void SignInEmployee();
    void PrintSystemUsers();
    void DeleteEmployeeFromSystem();
};

#endif // CONSOLE_H
#pragma once
