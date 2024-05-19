#include <iomanip>
#include "footwear.h"

bool Footwear::saveToDatabase(sql::Connection* con) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO footwear (name, quantity, price, description, color, category, brand, model, size) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
        pstmt->setString(1, name);
        pstmt->setInt(2, quantity);
        pstmt->setDouble(3, price);
        pstmt->setString(4, description);
        pstmt->setString(5, color);
        pstmt->setString(6, category);
        pstmt->setString(7, brand);
        pstmt->setString(8, model);
        pstmt->setInt(9, size);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
        return false;
    }
}

Footwear Footwear::loadFromDatabase(sql::Connection* con, const int& id) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("SELECT name, quantity, price, description, color, category, brand, model, size FROM footwear WHERE id = ?");
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
        int size = 0;
        if (res->next()) {
            name = res->getString("name");
            quantity = res->getInt("quantity");
            price = res->getDouble("price");
            description = res->getString("description");
            color = res->getString("color");
            category = res->getString("category");
            brand = res->getString("brand");
            model = res->getString("model");
            size = res->getInt("size");
        }
        delete res;
        delete pstmt;
        return Footwear(id, name, quantity, price, description, color, category, brand, model, size);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        return Footwear();
    }
}

void Footwear::Print() {
    cout << setiosflags(ios::left)
        << "| " << setw(14) << model << "| " << setw(25) << name << "| " << setw(19) << category << "| " << setw(14) << brand << "| " 
        << setw(14) << color << "| " << setw(14) << size << "| " << setw(14) << quantity << "| " << setw(14) << price << "| " << setw(24) << description << "|" << endl;
}

ostream& operator<<(ostream& os, const Footwear& obj)
{
    os << "| " << setw(14) << obj.model << "| " << setw(25) << obj.name << "| " << setw(19) << obj.category << "| " << setw(14) << obj.brand << "| " 
    << setw(14) << obj.color << "| " << setw(14) << obj.size << "| " << setw(14) << obj.quantity << "| " << setw(14) << obj.price << "| " << setw(24) << obj.description << "|";
    return os;
}