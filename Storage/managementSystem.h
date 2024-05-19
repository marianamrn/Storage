#ifndef MANAGEMENTSYSTEM_H
#define MANAGEMENTSYSTEM_H

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <vector>
#include "ConsoleIO.h"
#include "footwear.h"
#include "bags.h"
#include "employee.h"
#include "login.h"

sql::Connection* ConnectToDatabase();

class managementSystem {
	list<Footwear> footwear;
	list<Bags> bags;
	list<Employee> employee;
	vector<LogIn> logins;
	int currentLoggedInUser; 
	bool loggedIn;
	void InitFootwear();
	void InitBags();
	void InitEmployee();
	void InitLogins();
public:
	managementSystem() {
		InitFootwear();
		InitBags();
		InitEmployee();
		InitLogins();
	}
	~managementSystem() {}

	void addFoorwear();
	list<Footwear>::iterator searchFootwear(string name);
	void searchFootwearByCategory(string category);
	void searchFootwearByBrand(string brand);
	void footwearRemains();
	void printFootwear();
	void deleteFootwear(list<Footwear>::iterator it);
	
	void addBags();
	list<Bags>::iterator searchBags(string name);
	void searchBagsByCategory(string category);
	void searchBagsByBrand(string brand);
	void bagsRemains();
	void printBags();
	void deleteBags(list<Bags>::iterator it);

	void addEmployee();
	void printEmployee();
	list<Employee>::iterator searchEmployee(const int& id);
	list<Employee>::iterator searchEmployee(const string& firstName, const string& lastName, const string& surname);
	void changeEmployeePosition(list<Employee>::iterator it);
	void checkProductivity();
	void deleteEmployee(list<Employee>::iterator it);

	void footwearHeader();
	void footwearLine();
	void bagsHeader();
	void bagsLine();
	void employeeHeader();
	void employeeLine();

	void signInEmployee(int id);
	void printSystemUsers();
	void deleteEmployeeFromSystem(list<Employee>::iterator it);
	bool logIn(const string& login, const string& password);
	bool logOut();
};

#endif // MANAGEMENTSYSTEM_H
#pragma once