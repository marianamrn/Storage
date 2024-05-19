#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <list>
#include <limits>
#include "managementSystem.h"
#include "console.h"

bool CONSOLE::LOGIN() {
	bool loggedIn = false;
	do {
		cout << "--------------------------------------------------" << endl
			<< "|               �ղ� � �������                   |" << endl
			<< "--------------------------------------------------" << endl;
		cout << "| ���� | => ";
		string login = ConsoleIO::GetText(cin);
		cout << "| ������ | => ";
		string password = ConsoleIO::GetText(cin);
		loggedIn = system.logIn(login, password);
		cout << endl;
		Clear();
		if (loggedIn) {
			cout << "�� ������ � ������� �� " << login << "!" << endl;
			return true;
		}
		else {
			cout 
				<< "---------------------------------------------------" << endl
				<< "|                  �������                        |" << endl
				<< "---------------------------------------------------" << endl
				<< "| ������������ ���� �� ������!                   |" << endl
				<< "---------------------------------------------------" << endl << endl;
		}
	} while (!loggedIn);
	return false;
}

bool CONSOLE::LOGOUT() {
	cout 
		<< "---------------------------------------------------" << endl
		<< "|                      ��ղ�                      |" << endl
		<< "---------------------------------------------------" << endl;
	system.logOut();
	cout << "---------------------------------------------------" << endl;
	return false;
}

void CONSOLE::Clear()
{
	cout
		<< "--------------------------------------------------" << endl
		<< "|        �����Ͳ�� ������ ��� ����������         |" << endl
		<< "--------------------------------------------------" << endl;
	_getch();
	std::system("CLS");
}

void CONSOLE::Menu() {
	SetConsoleOutputCP(1251);
	int choice;
	int type;
	if(LOGIN()){
		while (true) {
			cout
				<< "--------------------------------------------------" << endl
				<< "|              STORAGE SYSTEM                    |" << endl
				<< "--------------------------------------------------" << endl
				<< "|                  ������                        |" << endl
				<< "--------------------------------------------------" << endl
				<< "| 1 - ����������� ������ �� �����               |" << endl
				<< "| 2 - ������ ����� �����                         |" << endl
				<< "| 3 - ����� ������                               |" << endl
				<< "| 4 - ����� ������ �� ��������                |" << endl
				<< "| 5 - ����� ������ �� �������                   |" << endl
				<< "| 6 - ��������� ������� ������ �� �����        |" << endl
				<< "| 7 - �������� �����                             |" << endl
				<< "--------------------------------------------------" << endl
				<< "|                ���ֲ�����                      |" << endl
				<< "--------------------------------------------------" << endl
				<< "| 8 - ����������� ���������� ��� ����������     |" << endl
				<< "| 9 - ������ ����������                          |" << endl
				<< "| 10 - ������ ����������                         |" << endl
				<< "| 11 - ������ ������ ���� ����������           |" << endl
				<< "| 12 - ��������� ������������� ����������     |" << endl
				<< "| 13 - �������� ����������                       |" << endl
				<< "--------------------------------------------------" << endl
				<< "|             ������Ͳ ��������                  |" << endl
				<< "--------------------------------------------------" << endl
				<< "| 14 - ������������ ���������� � �������        |" << endl
				<< "| 15 - ����������� ������������ �������          |" << endl
				<< "| 16 - �������� ����������� � �������            |" << endl
				<< "| 17 - ����� � �������                           |" << endl
				<< "--------------------------------------------------" << endl
				<< "| ��� ���� | => ";

			cin >> choice;
			switch (choice) {
				case 1: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|               ��������� ����в�                |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ������ ��� ������                             |" << endl
						<< "| 1 - ������                                     |" << endl
						<< "| 2 - �����                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ��� ���� | => ";
					cin >> type;
					switch (type) {
						case 1: {
							std::system("CLS");
							PrintFootwear();
							break;
						}
						case 2: {
							std::system("CLS");
							PrintBags();
							break;
						}
						default: {
							cout << endl << setiosflags(ios::left)
								<< "---------------------------------------------------" << endl
								<< "|                  �������                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| ���� ������ ������� ������! ��������� �� ���! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 2: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|                 ��������� ������               |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ������ ��� ������                             |" << endl
						<< "| 1 - ������                                     |" << endl
						<< "| 2 - �����                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ��� ���� | => ";
					cin >> type;
					switch (type)
					{
						case 1: {
							std::system("CLS");
							AddFootwear();
							break;
						}
						case 2: {
							std::system("CLS");
							AddBags();
							break;
						}
						default: {
							cout << endl << setiosflags(ios::left)
								<< "---------------------------------------------------" << endl
								<< "|                  �������                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| ���� ������ ������� ������! ��������� �� ���! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						} 
					}
					break;
				}
				case 3: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|                  ����� ������                  |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ������ ��� ������                             |" << endl
						<< "| 1 - ������                                     |" << endl
						<< "| 2 - �����                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ��� ���� | => ";
					cin >> type;
					switch (type)
					{
						case 1: {
							std::system("CLS");
							SearchFootwear();
							break;
						}
						case 2: {
							std::system("CLS");
							SearchBags();
							break;
						}
						default: {
							cout << endl << setiosflags(ios::left)
								<< "---------------------------------------------------" << endl
								<< "|                  �������                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| ���� ������ ������� ������! ��������� �� ���! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 4: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|          ����� ������ �� ������в��            |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ������ ��� ������                             |" << endl
						<< "| 1 - ������                                     |" << endl
						<< "| 2 - �����                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ��� ���� | => ";
					cin >> type;
					switch (type)
					{
						case 1: {
							std::system("CLS");
							SearchFootwearByCategory();
							break;
						}
						case 2: {
							std::system("CLS");
							SearchBagsByCategory();
							break;
						}
						default: {
							cout << endl << setiosflags(ios::left)
								<< "---------------------------------------------------" << endl
								<< "|                  �������                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| ���� ������ ������� ������! ��������� �� ���! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 5: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|            ����� ������ �� �������             |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ������ ��� ������                             |" << endl
						<< "| 1 - ������                                     |" << endl
						<< "| 2 - �����                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ��� ���� | => ";
					cin >> type;
					switch (type)
					{
						case 1: {
							std::system("CLS");
							SearchFootwearByBrand();
							break;
						}
						case 2: {
							std::system("CLS");
							SearchBagsByBrand();
							break;
						}
						default: {
							cout << endl << setiosflags(ios::left)
								<< "---------------------------------------------------" << endl
								<< "|                  �������                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| ���� ������ ������� ������! ��������� �� ���! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 6: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|               ����²��� �����ʲ�               |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ������ ��� ������                             |" << endl
						<< "| 1 - ������                                     |" << endl
						<< "| 2 - �����                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ��� ���� | => ";
					cin >> type;
					switch (type)
					{
						case 1: {
							std::system("CLS");
							FootwearRemains();
							break;
						}
						case 2: {
							std::system("CLS");
							BagsRemains();
							break;
						}
						default: {
							cout << endl << setiosflags(ios::left)
								<< "---------------------------------------------------" << endl
								<< "|                  �������                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| ���� ������ ������� ������! ��������� �� ���! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 7: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|                ��������� ������                |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ������ ��� ������                             |" << endl
						<< "| 1 - ������                                     |" << endl
						<< "| 2 - �����                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| ��� ���� | => ";
					cin >> type;
					switch (type)
					{
						case 1: {
							std::system("CLS");
							DeleteFootwear();
							break;
						}
						case 2: {
							std::system("CLS");
							DeleteBags();
							break;
						}
						default: {
							cout << endl << setiosflags(ios::left)
								<< "---------------------------------------------------" << endl
								<< "|                  �������                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| ���� ������ ������� ������! ��������� �� ���! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 8: {
					std::system("CLS");
					PrintEmployee();
					break;
				}
				case 9: {
					std::system("CLS");
					AddEmployee();
					break;
				}
				case 10: {
					std::system("CLS");
					SearchEnployee();
					break;
				}
				case 11: {
					std::system("CLS");
					ChangeEnployeePosition();
					break;
				}
				case 12: {
					std::system("CLS");
					ChackProductivity();
					break;
				}
				case 13: {
					std::system("CLS");
					DeleteEmployee();
					break;
				}
				case 14: {
					std::system("CLS");
					SignInEmployee();
					break;
				}
				case 15: {
					std::system("CLS");
					PrintSystemUsers();
					break;
				}
				case 16: {
					std::system("CLS");
					DeleteEmployeeFromSystem();
					break;
				}
				case 17: {
					std::system("CLS");
					LOGOUT();
					cout << endl << endl;
					Clear();
					cin.ignore();
					LOGIN();
					break;
				}
				default: {
					cout << endl
						<< "---------------------------------------------------" << endl
						<< "|                  �������                        |" << endl
						<< "---------------------------------------------------" << endl
						<< "| ���� ������ ������� ������! ��������� �� ���! |" << endl
						<< "---------------------------------------------------" << endl << endl;
					break;
				}
			}
		}
	}
}


void CONSOLE::PrintFootwear() {
	std::system("CLS");
	cout << setiosflags(ios::left);
	cout
		<< "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|                                                                                  ������                                                                                 |" << endl
		<< "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|" << setw(15) << " �������" << "|" << setw(26) << " ����� ������" << "|" << setw(20) << " ��������" << "|" << setw(15) << " �����" << "|" << setw(15)
		<< " ����" << "|" << setw(15) << " �����" << "|" << setw(15) << " ʳ������" << "|" << setw(15) << " ֳ�� �� ����" << "|" << setw(25) << " �������" << "|" << endl
		<< "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	system.printFootwear();
	cout << endl << endl;
	Clear();
}

void CONSOLE::PrintBags() {
	std::system("CLS");
	cout  
		<< "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|                                                                       �����                                                                         |" << endl
		<< "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|" << setw(15) << " �������" << "|" << setw(26) << " ����� ������" << "|" << setw(16) << " ��������" << "|" << setw(15) << " �����" << "|" << setw(15)
		<< " ����" << "|" << setw(15) << " ʳ������" << "|" << setw(15) << " ֳ��" << "|" << setw(25) << " �������" << "|" << endl
		<< "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	system.printBags();
	cout << endl << endl;
	Clear();
}

void CONSOLE::AddFootwear() {
	std::system("CLS");
	cout << setiosflags(ios::left);
	cout
		<< "------------------------------------------------------------------------" << endl
		<< "|                          ��������� ������                            |" << endl
		<< "------------------------------------------------------------------------" << endl;
	system.addFoorwear();
	cout << endl << endl << endl;
	Clear();
}

void CONSOLE::AddBags() {
	std::system("CLS");
	cout << setiosflags(ios::left);
	cout
		<< "------------------------------------------------------------------------" << endl
		<< "|                          ��������� ������                            |" << endl
		<< "------------------------------------------------------------------------" << endl;
	system.addBags();
	cout << endl << endl << endl;
	Clear();
}

void CONSOLE::SearchFootwear() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                      ����� ������                       |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| ������ ����� ������ | => ";
	cin.ignore();
	string searchName = ConsoleIO::GetText(cin);
	system.searchFootwear(searchName);
	cout << endl << endl;
	Clear();
}

void CONSOLE::SearchBags() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                      ����� C����                        |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| ������ ����� ������ | => ";
	cin.ignore();
	string searchName = ConsoleIO::GetText(cin);
	system.searchBags(searchName);
	cout << endl << endl;
	Clear();
}

void CONSOLE::SearchFootwearByCategory() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|              ����� ������ �� ������в��                 |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| ������ �������� ������ | => ";
	cin.ignore();
	string category = ConsoleIO::GetText(cin);
	system.searchFootwearByCategory(category);
	cout << endl << endl;
	Clear();
}

void CONSOLE::SearchBagsByCategory() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|              ����� C���� �� ������в��                  |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| ������ �������� ������ | => ";
	cin.ignore();
	string category = ConsoleIO::GetText(cin);
	system.searchBagsByCategory(category);
	cout << endl << endl;
	Clear();
}

void CONSOLE::SearchFootwearByBrand() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                ����� ������ �� �������                  |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| ������ ����� ������ | => ";
	cin.ignore();
	string brand = ConsoleIO::GetText(cin);
	system.searchFootwearByBrand(brand);
	cout << endl << endl;
	Clear();
}

void CONSOLE::SearchBagsByBrand() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                ����� C���� �� �������                   |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| ������ ����� ������ | => ";
	cin.ignore();
	string brand = ConsoleIO::GetText(cin);
	system.searchBagsByBrand(brand);
	cout << endl << endl;
	Clear();
}

void CONSOLE::FootwearRemains() {
	cout 
		<< "-------------------------------------------------------------------------------" << endl
		<< "|                               ������� ������                                |" << endl;
	system.footwearRemains();
	cout << endl << endl;
	Clear();
}

void CONSOLE::BagsRemains() {
	cout 
		<< "-------------------------------------------------------------------------------" << endl
		<< "|                                ������� �����                                |" << endl;
	system.bagsRemains();
	cout << endl << endl;
	Clear();
}

void CONSOLE::DeleteFootwear() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                    �������� ������                      |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| ������ ����� ������ | => ";
	cin.ignore();
	string searchName = ConsoleIO::GetText(cin);
	system.deleteFootwear(system.searchFootwear(searchName));
	cout << endl << endl;
	Clear();
}

void CONSOLE::DeleteBags() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                    �������� �����                       |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| ������ ����� ������ | => ";
	cin.ignore();
	string searchName = ConsoleIO::GetText(cin);
	system.deleteBags(system.searchBags(searchName));
	cout << endl << endl;
	Clear();
}

void CONSOLE::PrintEmployee()	 {
	std::system("CLS");
	cout << setiosflags(ios::left);
	cout
		<< "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|                                                                                      ���ֲ�����                                                                                             |" << endl
		<< "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|" << setw(15) << " �������" << "|" << setw(15) << " ��'�" << "|" << setw(15) << " �� �������" << "|" << setw(21) << " ���� ����������" << "|" << setw(20) << " ������� ������" 
		<< "|" << setw(15) << " ����" <<  "|" << setw(30) << " ������" << "|" << setw(15) << " ������ ����" << "|" << setw(17) << " �������� �����" << "|"<< setw(17) << " �������������" << "|" << endl
		<< "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	system.printEmployee();
	cout << endl << endl;
	Clear();
}

void CONSOLE::AddEmployee() {
	std::system("CLS");
	cout << setiosflags(ios::left);
	cout
		<< "------------------------------------------------------------------------" << endl
		<< "|                        ��������� ���ֲ�����                          |" << endl
		<< "------------------------------------------------------------------------" << endl;
	system.addEmployee();
	cout << endl << endl;
	Clear();
}

void CONSOLE::SearchEnployee() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                    ����� ���ֲ���ʲ�                    |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| ������ ������� ���������� | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| ������ i�'� ���������� | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| ������ �� ������� ���������� | => ";
	string searchSurname = ConsoleIO::GetText(cin);
	auto foundEmployeeIterator = system.searchEmployee(searchFirstName,searchLastName,searchSurname);
	cout << endl << endl;
	Clear();
}

void CONSOLE::ChangeEnployeePosition() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                   �̲�� ������� ̲���                   |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << "| ������ ������� ���������� | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| ������ i�'� ���������� | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| ������ �� ������� ���������� | => ";
	string searchSurname = ConsoleIO::GetText(cin);
	system.changeEmployeePosition(system.searchEmployee(searchFirstName, searchLastName, searchSurname));
	cout << endl << endl;
	Clear();
}

void CONSOLE::ChackProductivity() {
	std::system("CLS");
	cout << "----------------------------------------------------------------------------------------" << endl
		 << "|                              ���������Ͳ��� ���ֲ���ʲ�                              |" << endl;
	system.checkProductivity();
	cout << endl << endl;
	Clear();
}

void CONSOLE::DeleteEmployee() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                  ��������� ���ֲ�����                   |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << "| ������ ������� ���������� | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| ������ i�'� ���������� | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| ������ �� ������� ���������� | => ";
	string searchSurname = ConsoleIO::GetText(cin);
	system.deleteEmployee(system.searchEmployee(searchFirstName, searchLastName, searchSurname));
	cout << endl << endl;
	Clear();
}

void CONSOLE::SignInEmployee() {
	std::system("CLS");
	cout << setiosflags(ios::left);
	cout
		<< "------------------------------------------------------------------------" << endl
		<< "|                 �Ū��������� ���ֲ����� � �������                    |" << endl
		<< "------------------------------------------------------------------------" << endl;
	cout << "| ������ ������� ���������� | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| ������ i�'� ���������� | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| ������ �� ������� ���������� | => ";
	string searchSurname = ConsoleIO::GetText(cin);
	system.signInEmployee(system.searchEmployee(searchFirstName, searchLastName, searchSurname)->getID());
	cout << endl << endl;
	Clear();
}

void CONSOLE::PrintSystemUsers() {
	std::system("CLS");
	cout << setiosflags(ios::left);
	cout
		<< "--------------------------------------------------------" << endl
		<< "|                 ���������ײ �������                  |" << endl
		<< "--------------------------------------------------------" << endl
		<< "|" << setw(15) << " ID ����������" << "|" << setw(22) << " ����" << "|" << setw(15) << " ������" << "|" << endl
		<< "--------------------------------------------------------" << endl;
	system.printSystemUsers();
	cout << endl << endl;
	Clear();
}

void CONSOLE::DeleteEmployeeFromSystem() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|              ��������� ���ֲ����� � �������             |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << "| ������ ������� ���������� | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| ������ i�'� ���������� | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| ������ �� ������� ���������� | => ";
	string searchSurname = ConsoleIO::GetText(cin);
	system.deleteEmployeeFromSystem(system.searchEmployee(searchFirstName, searchLastName, searchSurname));
	cout << endl << endl;
	Clear();
}