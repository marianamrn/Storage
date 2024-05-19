#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <string>
using namespace std;

class Goods {
protected:
	int id;
	string name;
	int quantity;
	double price;
	string description;
	string color;
public:
	Goods() : id(0), name(""), quantity(0), price(0.0), description(""), color("") {}
	Goods(int id, string name, int quantity, double price, string description, string color) : 
		id(id), name(name), quantity(quantity), price(price), description(description), color(color) {}
    ~Goods() {}
    
    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    string getName() const { return name; }
    void setName(const string& newName) { name = newName; }

    int getQuantity() const { return quantity; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }

    double getPrice() const { return price; }
    void setPrice(double newPrice) { price = newPrice; }

    string getDescription() const { return description; }
    void setDescription(const string& newDescription) { description = newDescription; }

    string getColor() const { return color; }
    void setColor(const string& newColor) { color = newColor; }
};

#endif // GOODS_H
