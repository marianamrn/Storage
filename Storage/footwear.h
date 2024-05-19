#ifndef FOOTWEAR_H
#define FOOTWEAR_H

#include <iostream>
#include <string>
#include "goods.h"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

class Footwear : public Goods {
protected:
    string category;
    string brand;
    string model;
    int size;
public:
    Footwear() : Goods(), category(""), brand(""), model(""), size(0) {}
    Footwear(int id, string name, int quantity, double price, string description, string color, string category, string brand, string model, int size) :
        Goods(id, name, quantity, price, description, color), category(category), brand(brand), model(model), size(size) {}
    ~Footwear() {}

    string getCategory() const { return category; }
    void setCategory(string newCategory) { category = newCategory; }

    string getBrand() const { return brand; }
    void setBrand(string newBrand) { brand = newBrand; }

    string getModel() const { return model; }
    void setModel(string newModel) { model = newModel; }

    int getSize() const { return size; }
    void setSize(int newSize) { size = newSize; }
    
    bool saveToDatabase(sql::Connection* con);
    static Footwear loadFromDatabase(sql::Connection* con, const int& id);

    friend ostream& operator<<(ostream& os, const Footwear& obj);
    void Print();
};

#endif // FOOTWEAR_H
#pragma once
