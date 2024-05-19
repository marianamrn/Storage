#ifndef BAGS_H
#define BAGS_H

#include <iostream>
#include <string>
#include "goods.h"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

class Bags : public Goods {
protected:
    string category;
    string brand;
    string model;
public:
    Bags() : Goods(), category(""), brand(""), model("") {}
    Bags(int id, string name, int quantity, double price, string description, string color, string category, string brand, string model) :
        Goods(id, name, quantity, price, description, color), category(category), brand(brand), model(model) {}
    ~Bags() {}

    string getCategory() const { return category; }
    void setCategory(string newCategory) { category = newCategory; }

    string getBrand() const { return brand; }
    void setBrand(string newBrand) { brand = newBrand; }

    string getModel() const { return model; }
    void setModel(string newModel) { model = newModel; }

    bool saveToDatabase(sql::Connection* con);
    static Bags loadFromDatabase(sql::Connection* con, const int& id);

    void Print();
    friend ostream& operator<<(ostream& os, const Bags& obj);
};

#endif // BAGS_H
#pragma once