#include <windows.h>
#include <numeric>
#include "managementSystem.h"

/* CONNECTION TO DATABASE */
const string server = "tcp://127.0.0.1:3308";
const string username = "root";
const string password = "";

sql::Connection* ConnectToDatabase() {
	sql::Driver* driver;
	sql::Connection* con = nullptr;
	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema("storage");
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << endl;
	}
	return con;
}

/* INITS */
void managementSystem::InitFootwear() {
	try {
		footwear.clear(); 
		sql::Connection* con = ConnectToDatabase();
		if (con) {
			sql::PreparedStatement* pstmt = con->prepareStatement("SELECT id FROM footwear");
			sql::ResultSet* res = pstmt->executeQuery();
			while (res->next()) {
				int id = res->getInt("id");
				footwear.push_back(Footwear::loadFromDatabase(con, id));
			}
			delete res;
			delete pstmt;
			delete con;
		}
		else {
			std::cerr << "Failed to connect to the database." << std::endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void managementSystem::InitBags() {
	try {
		bags.clear();
		sql::Connection* con = ConnectToDatabase();
		if (con) {
			sql::PreparedStatement* pstmt = con->prepareStatement("SELECT id FROM bags");
			sql::ResultSet* res = pstmt->executeQuery();
			while (res->next()) {
				int id = res->getInt("id");
				bags.push_back(Bags::loadFromDatabase(con, id));
			}
			delete res;
			delete pstmt;
			delete con;
		}
		else {
			std::cerr << "Failed to connect to the database." << std::endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void managementSystem::InitEmployee() {
	try {
		employee.clear();
		sql::Connection* con = ConnectToDatabase();
		if (con) {
			sql::PreparedStatement* pstmt = con->prepareStatement("SELECT id FROM employee");
			sql::ResultSet* res = pstmt->executeQuery();
			while (res->next()) {
				int id = res->getInt("id");
				employee.push_back(Employee::loadFromDatabase(con, id));
			}
			delete res;
			delete pstmt;
			delete con;
		}
		else {
			std::cerr << "Failed to connect to the database." << std::endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void managementSystem::InitLogins() {
	SetConsoleOutputCP(1251);
	try {
		logins.clear();
		sql::Connection* con = ConnectToDatabase();
		if (con) {
			sql::PreparedStatement* pstmt = con->prepareStatement("SELECT id FROM login");
			sql::ResultSet* res = pstmt->executeQuery();
			while (res->next()) {
				int id = res->getInt("id");
				logins.push_back(LogIn::loadFromDatabase(con, id));
			}
			delete res;
			delete pstmt;
			delete con;
		}
		else {
			std::cerr << "Не вдалося підключитися до бази даних." << std::endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Помилка: " << e.what() << std::endl;
	}
}


/* FOOTWEAR */
void managementSystem::addFoorwear() {
	SetConsoleOutputCP(1251);
	Footwear object;
	int int_value;
	double double_value;
	string string_value;
	string model;

	cout << "| Введіть артикул | => ";
	cin.ignore();
	model = ConsoleIO::GetText(cin);
	sql::Connection* con = ConnectToDatabase();

	sql::PreparedStatement* pstmt = con->prepareStatement("SELECT quantity FROM footwear WHERE model = ?");
	pstmt->setString(1, model);
	sql::ResultSet* res = pstmt->executeQuery();

	if (res->next()) {
		int existingQuantity = res->getInt("quantity");
		int additionalQuantity;
		cout << "| Кількість товарів | => ";
		additionalQuantity = ConsoleIO::GetValue(cin);
		sql::PreparedStatement* updateStmt = con->prepareStatement("UPDATE footwear SET quantity = ? WHERE model = ?");
		updateStmt->setInt(1, existingQuantity + additionalQuantity);
		updateStmt->setString(2, model);
		updateStmt->executeUpdate(); 
		cout << endl
			<< "------------------------------------------------------------------------" << endl
			<< "|                             ПОВІДОМЛЕННЯ                             |" << endl
			<< "------------------------------------------------------------------------" << endl
			<< "| Товар додано!                                                        |" << endl
			<< "------------------------------------------------------------------------" << endl;
		delete updateStmt;
	}
	else {
		object.setModel(model);
		cout << "| Назва товару | => ";
		string_value = ConsoleIO::GetText(cin);

		object.setName(string_value);
		cout << "| Категорія | => ";
		string_value = ConsoleIO::GetText(cin);
		object.setCategory(string_value);

		cout << "| Бренд | => ";
		string_value = ConsoleIO::GetText(cin);
		object.setBrand(string_value);

		cout << "| Колір | => ";
		string_value = ConsoleIO::GetText(cin);
		object.setColor(string_value);
		
		cout << "| Розмір | => ";
		int_value = ConsoleIO::GetValue(cin);
		object.setSize(int_value);
		
		cout << "| Кількість | => ";
		int_value = ConsoleIO::GetValue(cin);
		object.setQuantity(int_value);
		
		cout << "| Ціна | => ";
		double_value = ConsoleIO::GetValue(cin);
		object.setPrice(double_value);

		cout << "| Примітка | => ";
		string_value = ConsoleIO::GetText(cin);
		object.setDescription(string_value);

		object.saveToDatabase(ConnectToDatabase());
		cout
			<< "------------------------------------------------------------------------" << endl
			<< "|                             ПОВІДОМЛЕННЯ                             |" << endl
			<< "------------------------------------------------------------------------" << endl
			<< "| Товар додано!                                                        |" << endl
			<< "------------------------------------------------------------------------" << endl;
	}
	delete res;
	delete pstmt;
	delete con;
}

list<Footwear>::iterator managementSystem::searchFootwear(string name) {
	cout << endl;
	managementSystem::footwearLine();
	cout << "|                                                                         РЕЗУЛЬТАТИ ПОШУКУ                                                                               |" << endl;
	managementSystem::footwearHeader();
	for (auto it = footwear.begin(); it != footwear.end(); ++it) {
		if (it->getName() == name) {
			it->Print();
			managementSystem::footwearLine();
			return it;
		}
	}
	cout << "|                                                                          CПИСОК ПОРОЖНІЙ                                                                                |" << endl;
	managementSystem::footwearLine();
	cout << endl
		<< "-----------------------------------------------------------" << endl
		<< "|                       ПОМИЛКА                           |" << endl
		<< "-----------------------------------------------------------" << endl
		<< "| Товару " << setw(5) << name << " на складі не виявлено!              |" << endl
		<< "-----------------------------------------------------------" << endl;
	return footwear.end();
}

void managementSystem::searchFootwearByCategory(string category) {
	SetConsoleOutputCP(1251);
	InitFootwear();
	bool found = false;
	if (!footwear.empty()) {
		cout << endl;
		managementSystem::footwearLine();
		cout << "|                                                                         РЕЗУЛЬТАТИ ПОШУКУ                                                                               |" << endl;
		managementSystem::footwearHeader();
		for (auto i = footwear.begin(); i != footwear.end(); i++) {
			if (i->getCategory() == category) {
				i->Print();
				managementSystem::footwearLine();
				found = true;
			}
		}
	}
	if (!found) {
		cout << "|                                                                          CПИСОК ПОРОЖНІЙ                                                                                |" << endl;
		managementSystem::footwearLine();
		cout << endl
			<< "-----------------------------------------------------------" << endl
			<< "|                       ПОМИЛКА                           |" << endl
			<< "-----------------------------------------------------------" << endl
			<< "| Товарів категорії " << setw(5) << category << " на складі не виявлено!          |" << endl
			<< "-----------------------------------------------------------" << endl;
	}
}

void managementSystem::searchFootwearByBrand(string brand) {
	SetConsoleOutputCP(1251);
	InitFootwear();
	bool found = false;
	if (!footwear.empty()) {
		cout << endl;
		managementSystem::footwearLine();
		cout << "|                                                                         РЕЗУЛЬТАТИ ПОШУКУ                                                                               |" << endl;
		managementSystem::footwearHeader();
		for (auto i = footwear.begin(); i != footwear.end(); i++) {
			if (i->getBrand() == brand) {
				i->Print();
				managementSystem::footwearLine();
				found = true;
			}
		}
	}
	if (!found) {
		cout << "|                                                                          CПИСОК ПОРОЖНІЙ                                                                                |" << endl;
		managementSystem::footwearLine();
		cout << endl
			<< "-----------------------------------------------------------" << endl
			<< "|                       ПОМИЛКА                           |" << endl
			<< "-----------------------------------------------------------" << endl
			<< "| Товарів бренду " << setw(5) << brand << " на складі не виявлено!             |" << endl
			<< "-----------------------------------------------------------" << endl;
	}
}

void managementSystem::footwearRemains() {
	InitFootwear();
	if (!footwear.empty()) {
		footwear.sort([](const Footwear& a, const Footwear& b) {
			return a.getQuantity() > b.getQuantity();
			});

		cout 
			<< "-------------------------------------------------------------------------------" << endl
			<< "|" << setw(13) << " Аотикул" << "|" << setw(26) << " Назва" << "|" << setw(13) << " Кількість" << "|" << setw(22) << " Примітка" << "|" << endl
			<< "-------------------------------------------------------------------------------" << endl;
		for (const auto& item : footwear) {
			string description = (item.getQuantity() < 10) ? "RUNNING OUT" : item.getDescription();
			cout
				<< "| " << setw(12) << item.getModel() << "| " << setw(25) << item.getName() << "| " << setw(12) << item.getQuantity() << "| " << setw(21) << description << "| " << endl
				<< "-------------------------------------------------------------------------------" << endl;
		}
	}
	else {
		cout << endl
			<< "-----------------------------------------------------------" << endl
			<< "|                       ПОМИЛКА                           |" << endl
			<< "-----------------------------------------------------------" << endl
			<< "| Поки жодних товарів не виявлено!                        |" << endl
			<< "-----------------------------------------------------------" << endl;
	}
	
}

void managementSystem::printFootwear() {
	SetConsoleOutputCP(1251);
	InitFootwear();
	if (footwear.empty()) {
		cout << "Поки немає товарів!" << endl;
	}
	else {
		for (auto elem : footwear) {
			cout << elem << endl;
			managementSystem::footwearLine();

		}
	}
}

void managementSystem::deleteFootwear(list<Footwear>::iterator it) {
	string name = it->getName();
	try {
		sql::Connection* con = ConnectToDatabase();
		if (con) {
			sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM footwear WHERE name = ?");
			pstmt->setString(1, name);
			pstmt->executeUpdate();
			delete pstmt;
			delete con;
		}
		else {
			cerr << "Помилка підключення до бази даних!" << endl;
			return;
		}
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Помилка: " << e.what() << endl;
		return;
	}

	it = footwear.erase(it);
	cout << endl
		<< "-----------------------------------------------------------" << endl
		<< "|                      РЕЗУЛЬТАТ                          |" << endl
		<< "-----------------------------------------------------------" << endl
		<< "| Товар " << setw(5) << name << " видалено!                           |" << endl
		<< "-----------------------------------------------------------" << endl;
}


/* BAGS */
void managementSystem::addBags() {
	SetConsoleOutputCP(1251);
	Bags object;
	int int_value;
	double double_value;
	string string_value;
	string model;

	cout << "| Введіть артикул | => ";
	cin.ignore();
	model = ConsoleIO::GetText(cin);
	sql::Connection* con = ConnectToDatabase();

	sql::PreparedStatement* pstmt = con->prepareStatement("SELECT quantity FROM bags WHERE model = ?");
	pstmt->setString(1, model);
	sql::ResultSet* res = pstmt->executeQuery();

	if (res->next()) {
		int existingQuantity = res->getInt("quantity");
		int additionalQuantity;
		cout << "| Кількість товарів | => ";
		additionalQuantity = ConsoleIO::GetValue(cin);
		sql::PreparedStatement* updateStmt = con->prepareStatement("UPDATE bags SET quantity = ? WHERE model = ?");
		updateStmt->setInt(1, existingQuantity + additionalQuantity);
		updateStmt->setString(2, model);
		updateStmt->executeUpdate();
		cout << endl
			<< "------------------------------------------------------------------------" << endl
			<< "|                             ПОВІДОМЛЕННЯ                             |" << endl
			<< "------------------------------------------------------------------------" << endl
			<< "| Товар додано!                                                        |" << endl
			<< "------------------------------------------------------------------------" << endl;
		delete updateStmt;
	}
	else {
		object.setModel(model);
		cout << "| Назва товару | => ";
		string_value = ConsoleIO::GetText(cin);

		object.setName(string_value);
		cout << "| Категорія | => ";
		string_value = ConsoleIO::GetText(cin);
		object.setCategory(string_value);

		cout << "| Бренд | => ";
		string_value = ConsoleIO::GetText(cin);
		object.setBrand(string_value);

		cout << "| Колір | => ";
		string_value = ConsoleIO::GetText(cin);
		object.setColor(string_value);

		cout << "| Кількість | => ";
		int_value = ConsoleIO::GetValue(cin);
		object.setQuantity(int_value);

		cout << "| Ціна | => ";
		double_value = ConsoleIO::GetValue(cin);
		object.setPrice(double_value);

		cout << "| Примітка | => ";
		string_value = ConsoleIO::GetText(cin);
		object.setDescription(string_value);

		object.saveToDatabase(ConnectToDatabase());
		cout << endl
			<< "------------------------------------------------------------------------" << endl
			<< "|                             ПОВІДОМЛЕННЯ                             |" << endl
			<< "------------------------------------------------------------------------" << endl
			<< "| Товар додано!                                                        |" << endl
			<< "------------------------------------------------------------------------" << endl;
	}
	delete res;
	delete pstmt;
	delete con;
}

list<Bags>::iterator managementSystem::searchBags(string name) {
	cout << endl;
	managementSystem::bagsLine();
	cout << "|                                                               РЕЗУЛЬТАТИ ПОШУКУ                                                                     |" << endl;
	managementSystem::bagsHeader();
	for (auto it = bags.begin(); it != bags.end(); ++it) {
		if (it->getName() == name) {
			it->Print();
			managementSystem::bagsLine();
			return it;
		}
	}
	cout << "|                                                                 CПИСОК ПОРОЖНІЙ                                                                     |" << endl;
	managementSystem::bagsLine();
	cout << endl
		<< "-----------------------------------------------------------" << endl
		<< "|                       ПОМИЛКА                           |" << endl
		<< "-----------------------------------------------------------" << endl
		<< "| Товару " << setw(5) << name << " на складі не виявлено!   |" << endl
		<< "-----------------------------------------------------------" << endl;
	return bags.end();
}

void managementSystem::searchBagsByCategory(string category) {
	SetConsoleOutputCP(1251);
	bool found = false;
	if (!bags.empty()) {
		cout << endl;
		managementSystem::bagsLine();
		cout << "|                                                                 РЕЗУЛЬТАТИ ПОШУКУ                                                                   |" << endl;
		managementSystem::bagsHeader();
		for (auto i = bags.begin(); i != bags.end(); i++) {
			if (i->getCategory() == category) {
				i->Print();
				managementSystem::bagsLine();
				found = true;
			}
		}
	}
	if (!found) {
		cout << "|                                                                  CПИСОК ПОРОЖНІЙ                                                                    |" << endl;
		managementSystem::bagsLine();
		cout << endl
			<< "-----------------------------------------------------------" << endl
			<< "|                       ПОМИЛКА                           |" << endl
			<< "-----------------------------------------------------------" << endl
			<< "| Товарів категорії " << setw(5) << category << " на складі не виявлено!         |" << endl
			<< "-----------------------------------------------------------" << endl;
	}
}

void managementSystem::searchBagsByBrand(string brand) {
	SetConsoleOutputCP(1251);
	bool found = false;
	if (!bags.empty()) {
		cout << endl;
		managementSystem::bagsLine();
		cout << "|                                                                РЕЗУЛЬТАТИ ПОШУКУ                                                                    |" << endl;
		managementSystem::bagsHeader();
		for (auto i = bags.begin(); i != bags.end(); i++) {
			if (i->getBrand() == brand) {
				i->Print();
				managementSystem::bagsLine();
				found = true;
			}
		}
	}
	if (!found) {
		cout << "|                                                                  CПИСОК ПОРОЖНІЙ                                                                    |" << endl;
		managementSystem::bagsLine();
		cout << endl
			<< "-----------------------------------------------------------" << endl
			<< "|                       ПОМИЛКА                           |" << endl
			<< "-----------------------------------------------------------" << endl
			<< "| Товарів брунду " << setw(5) << brand << " на складі не виявлено!|" << endl
			<< "-----------------------------------------------------------" << endl;
	}
}

void managementSystem::bagsRemains() {
	InitBags();
	if (!bags.empty()) {
		bags.sort([](const Bags& a, const Bags& b) {
			return a.getQuantity() > b.getQuantity();
			});

		cout 
			<< "-------------------------------------------------------------------------------" << endl
			<< "|" << setw(13) << " Аотикул" << "|" << setw(26) << " Назва" << "|" << setw(13) << " Кількість" << "|" << setw(22) << " Примітка" << "|" << endl
			<< "-------------------------------------------------------------------------------" << endl;
		for (const auto& item : bags) {
			string description = (item.getQuantity() < 10) ? "RUNNING OUT" : item.getDescription();
			cout 
				<< "| " << setw(12) << item.getModel() << "| " << setw(25) << item.getName() << "| " << setw(12) << item.getQuantity() << "| " << setw(21) << description << "| " << endl
				<< "-------------------------------------------------------------------------------" << endl;
		}
	}
	else {
		cout << endl
			<< "-----------------------------------------------------------" << endl
			<< "|                       ПОМИЛКА                           |" << endl
			<< "-----------------------------------------------------------" << endl
			<< "| Поки жодних товарів не виявлено!                        |" << endl
			<< "-----------------------------------------------------------" << endl;
	}

}

void managementSystem::printBags() {
	InitBags();
	if (bags.empty()) {
		cout << "Поки немає товарів!" << endl;
	}
	else {
		for (auto elem : bags) {
			cout << elem << endl;
			managementSystem::bagsLine();
		}
	}
}

void managementSystem::deleteBags(list<Bags>::iterator it) {
	string name = it->getName();
	try {
		sql::Connection* con = ConnectToDatabase();
		if (con) {
			sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM bags WHERE name = ?");
			pstmt->setString(1, name);
			pstmt->executeUpdate();
			delete pstmt;
			delete con;
		}
		else {
			cerr << "Помилка підключення до бази даних!" << endl;
			return;
		}
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Помилка: " << e.what() << endl;
		return;
	}

	it = bags.erase(it);
	cout << endl
		<< "-----------------------------------------------------------" << endl
		<< "|                      РЕЗУЛЬТАТ                          |" << endl
		<< "-----------------------------------------------------------" << endl
		<< "| Товар " << setw(5) << name << " видалено!                        |" << endl
		<< "-----------------------------------------------------------" << endl;
}


/* EMPLOYEE */
void managementSystem::addEmployee() {
	Employee object;
	int int_value;
	double double_value;
	string string_value;
	Date date_value;
	StartWorking sw_value;

	cin.ignore();
	cout << setw(10) << "| Прізвище | => ";
	string_value = ConsoleIO::GetText(cin);
	object.setFirstName(string_value);

	cout << setw(10) << "| Ім'я | => ";
	string_value = ConsoleIO::GetText(cin);
	object.setLastName(string_value);

	cout << setw(10) << "| По батькові | = > ";
	string_value = ConsoleIO::GetText(cin);
	object.setSurname(string_value);

	cout << "Дата народження:" << endl;
	cout << setw(10) << "| День |=> ";
	date_value.day = ConsoleIO::GetValue(cin);
	cout << setw(10) << "| Місяць | => ";
	date_value.month = ConsoleIO::GetValue(cin);
	cout << setw(10) << "| Рік | => ";
	date_value.year = ConsoleIO::GetValue(cin);
	object.setBirthDate(date_value);

	cout << "Дата початку роботи:" << endl;
	cout << setw(10) << "| День | => ";
	sw_value.day = ConsoleIO::GetValue(cin);
	cout << setw(10) << "| Місяць | => ";
	sw_value.month = ConsoleIO::GetValue(cin);
	cout << setw(10) << "| Рік | => ";
	sw_value.year = ConsoleIO::GetValue(cin);
	object.setStartWorkingDate(sw_value);

	cout << setw(10) << "| Зміна | => ";
	string_value = ConsoleIO::GetText(cin);
	object.setShift(string_value);

	cout << setw(10) << "| Посада | => ";
	string_value = ConsoleIO::GetText(cin);
	object.setPost(string_value);
	
	cout << setw(10) << "| Робоче місце | => ";
	string_value = ConsoleIO::GetText(cin);
	object.setPosition(string_value);

	cout << setw(10) << "| Заробітна плата | => ";
	double_value = ConsoleIO::GetValue(cin);
	object.setSalary(double_value);

	cout << setw(10) << "| Продуктивність | => ";
	int_value = ConsoleIO::GetValue(cin);
	object.setProductivity(int_value);

	object.saveToDatabase(ConnectToDatabase());
	cout << endl
		<< "------------------------------------------------------------------------" << endl
		<< "|                             ПОВІДОМЛЕННЯ                             |" << endl
		<< "------------------------------------------------------------------------" << endl
		<< "| Працівника додано!                                                   |" << endl
		<< "------------------------------------------------------------------------" << endl;
}

void managementSystem::printEmployee() {
	InitEmployee();
	if (employee.empty()) {
		cout << "Поки немає товарів!" << endl;
	}
	else {
		for (auto elem : employee) {
			cout << elem << endl;
			managementSystem::employeeLine();
		}
	}
}

list<Employee>::iterator managementSystem::searchEmployee(const int& id) {
	for (auto it = employee.begin(); it != employee.end(); ++it) {
		if (it->getID() == id) {
			return it;
		}
	}
	cout << endl
		<< "-----------------------------------------------------------" << endl
		<< "|                       ПОМИЛКА                           |" << endl
		<< "-----------------------------------------------------------" << endl
		<< "| Працівника з ID " << id << " не виявлено!               |" << endl
		<< "-----------------------------------------------------------" << endl;
	return employee.end();
}

list<Employee>::iterator managementSystem::searchEmployee(const string& firstName, const string& lastName, const string& surname) {
	cout << endl;
	managementSystem::employeeLine();
	cout << "|                                                                                   РЕЗУЛЬТАТИ ПОШУКУ                                                                                         |" << endl;
	managementSystem::employeeHeader();
	for (auto it = employee.begin(); it != employee.end(); ++it) {
		if (it->getFirstName() == firstName && it->getLastName() == lastName && it->getSurname() == surname) {
			it->Print();
			cout << endl;
			managementSystem::employeeLine();
			return it; 
		}
	}
	cout << "|                                                                                    CПИСОК ПОРОЖНІЙ                                                                                          |" << endl;
	managementSystem::employeeLine();
	cout << endl
		<< "-----------------------------------------------------------" << endl
		<< "|                       ПОМИЛКА                           |" << endl
		<< "-----------------------------------------------------------" << endl
		<< "| Працівника " << firstName << " " << lastName << " " << surname << " не виявлено!          |" << endl
		<< "-----------------------------------------------------------" << endl;
	return employee.end(); 
}

void managementSystem::changeEmployeePosition(list<Employee>::iterator it) {
	cout << endl << "| Введіть нове робоче місце праціника | => ";
	string newPosition = ConsoleIO::GetText(cin);
	it->setPosition(newPosition);

	try {
		sql::Connection* con = ConnectToDatabase();
		if (con) {
			sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE employee SET position = ? WHERE id = ?");
			pstmt->setString(1, newPosition);
			pstmt->setInt(2, it->getID());
			pstmt->executeUpdate();
			delete pstmt;
			delete con;
		}
		else {
			cerr << "Помилка підключення до бази даних!" << endl;
		}
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Помилка: " << e.what() << endl;
	}
	cout << "Робоче міце працівника змінено!"<<endl;
}

void managementSystem::checkProductivity() {
	if (employee.empty()) {
		cout << "Список працівників порожній." << endl;
		return;
	}

	double averageProductivity = accumulate(employee.begin(), employee.end(), 0.0,
		[](double sum, const Employee& emp) {
			return sum + emp.getProductivity();
		}) / employee.size();
		
		cout << setiosflags(ios::left);
		cout
			<< "----------------------------------------------------------------------------------------" << endl
			<< "|" << setw(15) << " Прізвище" << "|" << setw(15) << " Ім'я" << "|" << setw(15) << " По батькові" << "|" << setw(16) << " Продуктивність" << "|" << setw(21) << " Примітка" << "|" << endl
			<< "----------------------------------------------------------------------------------------" << endl;

		for (const auto& item : employee) {
			cout << setiosflags(ios::left)
				<< "| " << setw(14) << item.getFirstName() << "| " << setw(14) << item.getLastName() << "| " << setw(14) << item.getSurname() << "| " << setw(15) << item.getProductivity();
			if (item.getProductivity() > averageProductivity) {
				cout << "| " << setw(20) << " Вище середнього" << "|" << endl;
				cout << "----------------------------------------------------------------------------------------" << endl;
			}
			else if (item.getProductivity() < averageProductivity) {
				cout << "| " << setw(20) << " Нижче середнього" << "|" << endl;
				cout << "----------------------------------------------------------------------------------------" << endl;
			}
			else {
				cout << "| " << setw(20) << " Норма" << "|" << endl;
				cout << "----------------------------------------------------------------------------------------" << endl;
			}
		}
}

void managementSystem::deleteEmployee(list<Employee>::iterator it) {
	string firstName = it->getFirstName();
	string lastName = it->getLastName();
	string surname = it->getSurname();
	try {
		sql::Connection* con = ConnectToDatabase();
		if (con) {
			sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM employee WHERE firstName = ? AND lastName = ? AND surname = ?");
			pstmt->setString(1, firstName);
			pstmt->setString(2, lastName);
			pstmt->setString(3, surname);
			pstmt->executeUpdate();
			delete pstmt;
			delete con;
		}
		else {
			cerr << "Помилка підключення до бази даних!" << endl;
			return;
		}
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Помилка: " << e.what() << endl;
		return;
	}

	it = employee.erase(it);
	cout << endl
		<< "-----------------------------------------------------------" << endl
		<< "|                      РЕЗУЛЬТАТ                          |" << endl
		<< "-----------------------------------------------------------" << endl
		<< "| Працівника " << firstName << " " << lastName << " " << surname << " видалено!             |" << endl
		<< "-----------------------------------------------------------" << endl;
}


/* LOGIN */
void managementSystem::signInEmployee(int id) {
	for (auto& login : logins) {
		if (login.getEmployeeId() == id) {
			cout << "Користувач з таким ID вже зареєстрований в системі." << endl;
			return;
		}
	}
	LogIn object;
	string string_value;

	object.setEmployeeId(id);
	cin.ignore();
	cout << setw(10) << "| Логін | => ";
	string_value = ConsoleIO::GetText(cin);
	object.setLogin(string_value);
	cout << setw(10) << "| Пароль | => ";
	string_value = ConsoleIO::GetText(cin);
	object.setPassword(string_value);

	object.saveToDatabase(ConnectToDatabase());
	cout << "Користувача зареєстровано!" << endl;
}

void managementSystem::printSystemUsers() {
	InitLogins();
	if (logins.empty()) {
		cout << "| У системі не виявено користувачів !              |" << endl
			 << "----------------------------------------------------" << endl;
	}
	else {
		for (auto lg : logins) {
			lg.Print();
			cout <<"--------------------------------------------------------" << endl;
		}
	}
}

void managementSystem::deleteEmployeeFromSystem(list<Employee>::iterator it) {
	int employee_id = it->getID();
	try {
		sql::Connection* con = ConnectToDatabase();
		if (con) {
			sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM login WHERE employee_id = ?");
			pstmt->setInt(1, employee_id);
			pstmt->executeUpdate();
			delete pstmt;
			delete con;
		}
		else {
			cerr << "Помилка підключення до бази даних!" << endl;
			return;
		}
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Помилка: " << e.what() << endl;
		return;
	}

	auto itEmployee = std::find_if(logins.begin(), logins.end(), [employee_id](LogIn& login) {
		return login.getEmployeeId() == employee_id;
		});

	if (itEmployee != logins.end()) {
		logins.erase(itEmployee);
	}

	cout << endl
		<< "-----------------------------------------------------------" << endl
		<< "|                      РЕЗУЛЬТАТ                          |" << endl
		<< "-----------------------------------------------------------" << endl
		<< "| Користувача видалено з системи!                         |" << endl
		<< "-----------------------------------------------------------" << endl;
}

bool managementSystem::logIn(const string& login, const string& password) {
	InitLogins();
	if (logins.empty()) {
		LogIn object;
		object.setLogin("admin");
		object.setPassword("password");
		object.saveToDatabase(ConnectToDatabase());
	}
	bool userFound = false;
	for (auto& user : logins) {
		if (user.getLogin() == login && user.getPassword() == password) {
			userFound = true;
			return true;
			break;
		}
	}

	if (userFound) {
		for (auto user : logins) {
			if (user.getLogin() == login) {
				currentLoggedInUser = user.getEmployeeId();
			}
		}
		for (auto empl : employee) {
			if (empl.getID() == currentLoggedInUser) {
				string user = empl.getFirstName() + " " + empl.getLastName();
				cout << "| Вітаємо в системі " << user << "        |" << endl;
			}
		}
	}

	else {
		cout << endl 
			<< "---------------------------------------------------" << endl
			<< "|                  ПОМИЛКА                        |" << endl
			<< "---------------------------------------------------" << endl
			<< "| Неправильний логін чи пароль!                   |" << endl
			<< "---------------------------------------------------" << endl << endl;
		return false;
	}
}

bool managementSystem::logOut() {
	currentLoggedInUser = 0;
	cout << "| Вихід із системи пройшов успішно!               |" << endl;
	return false;
}

/* HEADERS */
void managementSystem::footwearHeader() {
	cout << setiosflags(ios::left)
		<< "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|" << setw(15) << " Артикул" << "|" << setw(26) << " Назва товару" << "|" << setw(20) << " Категорія" << "|" << setw(15) << " Бренд" << "|" << setw(15)
		<< " Колір" << "|" << setw(15) << " Розмір" << "|" << setw(15) << " Кількість" << "|" << setw(15) << " Ціна за пару" << "|" << setw(25) << " Примітка" << "|" << endl
		<< "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void managementSystem::footwearLine() {
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void managementSystem::bagsHeader() {
	cout << setiosflags(ios::left);
	cout
		<< "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|" << setw(15) << " Артикул" << "|" << setw(26) << " Назва товару" << "|" << setw(16) << " Категорія" << "|" << setw(15) << " Бренд" << "|" << setw(15)
		<< " Колір" << "|" << setw(15) << " Кількість" << "|" << setw(15) << " Ціна" << "|" << setw(25) << " Примітка" << "|" << endl
		<< "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void managementSystem::bagsLine() {
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void managementSystem::employeeHeader() {
	cout << setiosflags(ios::left);
	cout
		<< "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|" << setw(15) << " Прізвище" << "|" << setw(15) << " Ім'я" << "|" << setw(15) << " По батькові" << "|" << setw(21) << " Дата народження" << "|" << setw(20) << " Початок роботи"
		<< "|" << setw(15) << " Зміна" << "|" << setw(30) << " Посада" << "|" << setw(15) << " Робоче місце" << "|" << setw(17) << " Заробітна плата" << "|" << setw(17) << " Продуктивність" << "|" << endl
		<< "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void managementSystem::employeeLine() {
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
