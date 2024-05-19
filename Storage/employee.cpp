#include "employee.h"
#include <iomanip>

bool Employee::saveToDatabase(sql::Connection* con) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement(
        "INSERT INTO employee (firstName, lastName, surname, bdayDay, bdayMonth, bdayYear, swDay, swMonth, swYear, post, productivity, salary, shift, position) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        pstmt->setString(1, firstName);
        pstmt->setString(2, lastName);
        pstmt->setString(3, surname);
        pstmt->setInt(4, birthDate.day);
        pstmt->setInt(5, birthDate.month);
        pstmt->setInt(6, birthDate.year);
        pstmt->setInt(7, startWorkingDate.day);
        pstmt->setInt(8, startWorkingDate.month);
        pstmt->setInt(9, startWorkingDate.year);
        pstmt->setString(10, post);
        pstmt->setInt(11, productivity);
        pstmt->setDouble(12, salary);
        pstmt->setString(13, shift);
        pstmt->setString(14, position);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
        return false;
    }
}

Employee Employee::loadFromDatabase(sql::Connection* con, const int& id) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "SELECT firstName, lastName, surname, bdayDay, bdayMonth, bdayYear, swDay, swMonth, swYear, post, productivity, salary, shift, position FROM employee WHERE id = ?");
        pstmt->setInt(1, id);
        sql::ResultSet* res = pstmt->executeQuery();
        string firstName = "";
        string lastName = "";
        string surname = "";
        Date birthDate = { 0,0,0 };
        StartWorking startWorkingDate = { 0,0,0 };
        string post = "";
        int productivity = 0;
        double salary = 0.0;
        string shift = "";
        string position = "";
        if (res->next()) {
            firstName = res->getString("firstName");
            lastName = res->getString("lastName");
            surname = res->getString("surname");
            birthDate.day = res->getInt("bdayDay");
            birthDate.month = res->getInt("bdayMonth");
            birthDate.year = res->getInt("bdayYear");
            startWorkingDate.day = res->getInt("swDay");
            startWorkingDate.month = res->getInt("swMonth");
            startWorkingDate.year = res->getInt("swYear");
            post = res->getString("post");
            productivity = res->getInt("productivity");
            salary = res->getDouble("salary");
            shift = res->getString("shift");
            position = res->getString("position");
        }
        delete res;
        delete pstmt;
        return Employee(id, firstName, lastName, surname, birthDate, startWorkingDate, post, productivity, salary, shift, position);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        return Employee();
    }
}

void Employee::Print() {
    cout
        << "| " << setw(14) << firstName << "| " << setw(14) << lastName << "| " << setw(14) << surname << "| "
        << setw(2) << birthDate.day << "-" << setw(2) << birthDate.month << "-" << setw(13) << birthDate.year << " | "
        << setw(2) << startWorkingDate.day << "-" << setw(2) << startWorkingDate.month << "-" << setw(12) << startWorkingDate.year << " | "
        << setw(14) << shift << "| " << setw(29) << post << "| " << setw(14) << position << "| " << setw(16) << salary << "| " << setw(16) << productivity << "| ";

}

ostream& operator<<(ostream& os, const Employee& obj)
{
    os 
        << "| " << setw(14) << obj.firstName << "| " << setw(14) << obj.lastName << "| " << setw(14) << obj.surname << "| "
        << setw(2) << obj.birthDate.day << "-" << setw(2) << obj.birthDate.month << "-" << setw(13) << obj.birthDate.year << " | " 
        << setw(2) << obj.startWorkingDate.day << "-" << setw(2) << obj.startWorkingDate.month << "-" << setw(12) << obj.startWorkingDate.year << " | "
        << setw(14) << obj.shift << "| " << setw(29) << obj.post << "| " << setw(14) << obj.position << "| " << setw(16) << obj.salary << "| " << setw(16) << obj.productivity << "| ";
    return os;
}

