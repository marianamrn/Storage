#include <iomanip>
#include "bags.h"

bool Bags::saveToDatabase(sql::Connection* con) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO bags (name, quantity, price, description, color, category, brand, model) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
        pstmt->setString(1, name);
        pstmt->setInt(2, quantity);
        pstmt->setDouble(3, price);
        pstmt->setString(4, description);
        pstmt->setString(5, color);
        pstmt->setString(6, category);
        pstmt->setString(7, brand);
        pstmt->setString(8, model);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
        return false;
    }
}

Bags Bags::loadFromDatabase(sql::Connection* con, const int& id) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("SELECT name, quantity, price, description, color, category, brand, model FROM bags WHERE id = ?");
        pstmt->setInt(1, id);
        sql::ResultSet* res = pstmt->executeQuery();
        string name = "";
        int quantity = 0;
        double price = 0.0;
        string description = "";
        string color = "";
        string category = "";
        string brand = "";
        string model = "";
        if (res->next()) {
            name = res->getString("name");
            quantity = res->getInt("quantity");
            price = res->getDouble("price");
            description = res->getString("description");
            color = res->getString("color");
            category = res->getString("category");
            brand = res->getString("brand");
            model = res->getString("model");
        }
        delete res;
        delete pstmt;
        return Bags(id, name, quantity, price, description, color, category, brand, model);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        return Bags();
    }
}

void Bags::Print() {
    cout << "| " << setw(14) << model << "| " << setw(25) << name << "| " << setw(15) << category << "| " << setw(14) << brand << "| " 
        << setw(14) << color << "| " << setw(14) << quantity << "| " << setw(14) << price << "| " << setw(24) << description << "|" << endl;
}

ostream& operator<<(ostream& os, const Bags& obj)
{
    os << "| " << setw(14) << obj.model << "| " << setw(25) << obj.name << "| " << setw(15) << obj.category << "| " << setw(14) << obj.brand << "| "
    << setw(14) << obj.color << "| " << setw(14) << obj.quantity << "| " << setw(14) << obj.price << "| " << setw(24) << obj.description << "|";
    return os;
}