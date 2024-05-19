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
			<< "|               ÂÕ²Ä Â ÑÈÑÒÅÌÓ                   |" << endl
			<< "--------------------------------------------------" << endl;
		cout << "| Ëîã³í | => ";
		string login = ConsoleIO::GetText(cin);
		cout << "| Ïàðîëü | => ";
		string password = ConsoleIO::GetText(cin);
		loggedIn = system.logIn(login, password);
		cout << endl;
		Clear();
		if (loggedIn) {
			cout << "Âè óâ³éøëè â ñèñòåìó ÿê " << login << "!" << endl;
			return true;
		}
		else {
			cout 
				<< "---------------------------------------------------" << endl
				<< "|                  ÏÎÌÈËÊÀ                        |" << endl
				<< "---------------------------------------------------" << endl
				<< "| Íåïðàâèëüíèé ëîã³í ÷è ïàðîëü!                   |" << endl
				<< "---------------------------------------------------" << endl << endl;
		}
	} while (!loggedIn);
	return false;
}

bool CONSOLE::LOGOUT() {
	cout 
		<< "---------------------------------------------------" << endl
		<< "|                      ÂÈÕ²Ä                      |" << endl
		<< "---------------------------------------------------" << endl;
	system.logOut();
	cout << "---------------------------------------------------" << endl;
	return false;
}

void CONSOLE::Clear()
{
	cout
		<< "--------------------------------------------------" << endl
		<< "|        ÍÀÒÈÑÍ²ÒÜ ÏÐÎÁ²Ë ÙÎÁ ÏÐÎÄÎÂÆÈÒÈ         |" << endl
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
				<< "|                  ÒÎÂÀÐÈ                        |" << endl
				<< "--------------------------------------------------" << endl
				<< "| 1 - Ïåðåãëÿíóòè òîâàðè íà ñêëàä³               |" << endl
				<< "| 2 - Äîäàòè íîâèé òîâàð                         |" << endl
				<< "| 3 - Ïîøóê òîâàðó                               |" << endl
				<< "| 4 - Ïîøóê òîâàð³â çà êàòåãîð³ºþ                |" << endl
				<< "| 5 - Ïîøóê òîâàð³â çà áðåíäîì                   |" << endl
				<< "| 6 - Ïåðåâ³ðèòè çàëèøêè òîâàðó íà ñêëàä³        |" << endl
				<< "| 7 - Âèäàëèòè òîâàð                             |" << endl
				<< "--------------------------------------------------" << endl
				<< "|                ÏÐÀÖ²ÂÍÈÊÈ                      |" << endl
				<< "--------------------------------------------------" << endl
				<< "| 8 - Ïåðåãëÿíóòè ³íôîðìàö³þ ïðî ïðàö³âíèê³â     |" << endl
				<< "| 9 - Äîäàòè ïðàö³âíèêà                          |" << endl
				<< "| 10 - Çíàéòè ïðàö³âíèêà                         |" << endl
				<< "| 11 - Çì³íèòè ðîáî÷å ì³ñöå ïðàö³âíèêà           |" << endl
				<< "| 12 - Ïåðåâ³ðèòè ïðîäóêòèâí³ñòü ïðàö³âíèê³â     |" << endl
				<< "| 13 - Âèäàëèòè ïðàö³âíèêà                       |" << endl
				<< "--------------------------------------------------" << endl
				<< "|             ÑÈÑÒÅÌÍ² ÏÐÀÌÅÒÐÈ                  |" << endl
				<< "--------------------------------------------------" << endl
				<< "| 14 - Çàðåºñòðóâàòè ïðàö³âíèêà â ñèñòåìó        |" << endl
				<< "| 15 - Ïåðåãëÿíóòè êîðèñòóâà÷³â ñèñòåìè          |" << endl
				<< "| 16 - Âèäàëèòè êîðèñòóâà÷à ç ñèñòåìè            |" << endl
				<< "| 17 - Âèéòè ç ñèñòåìè                           |" << endl
				<< "--------------------------------------------------" << endl
				<< "| Âàø âèá³ð | => ";

			cin >> choice;
			switch (choice) {
				case 1: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|               ÂÈÂÅÄÅÍÍß ÒÎÂÀÐ²Â                |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Îáåð³òü òèï òîâàðó                             |" << endl
						<< "| 1 - Âçóòòÿ                                     |" << endl
						<< "| 2 - Ñóìêè                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Âàø âèá³ð | => ";
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
								<< "|                  ÏÎÌÈËÊÀ                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| Íåìàº òàêîãî âàð³àíòó âèáîðó! Ñïðîáóéòå ùå ðàç! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 2: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|                 ÄÎÄÀÂÀÍÍß ÒÎÂÀÐÓ               |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Îáåð³òü òèï òîâàðó                             |" << endl
						<< "| 1 - Âçóòòÿ                                     |" << endl
						<< "| 2 - Ñóìêè                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Âàø âèá³ð | => ";
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
								<< "|                  ÏÎÌÈËÊÀ                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| Íåìàº òàêîãî âàð³àíòó âèáîðó! Ñïðîáóéòå ùå ðàç! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						} 
					}
					break;
				}
				case 3: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|                  ÏÎØÓÊ ÒÎÂÀÐÓ                  |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Îáåð³òü òèï òîâàðó                             |" << endl
						<< "| 1 - Âçóòòÿ                                     |" << endl
						<< "| 2 - Ñóìêè                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Âàø âèá³ð | => ";
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
								<< "|                  ÏÎÌÈËÊÀ                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| Íåìàº òàêîãî âàð³àíòó âèáîðó! Ñïðîáóéòå ùå ðàç! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 4: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|          ÏÎØÓÊ ÒÎÂÀÐÓ ÇÀ ÊÀÒÅÃÎÐ²ªÞ            |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Îáåð³òü òèï òîâàðó                             |" << endl
						<< "| 1 - Âçóòòÿ                                     |" << endl
						<< "| 2 - Ñóìêè                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Âàø âèá³ð | => ";
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
								<< "|                  ÏÎÌÈËÊÀ                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| Íåìàº òàêîãî âàð³àíòó âèáîðó! Ñïðîáóéòå ùå ðàç! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 5: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|            ÏÎØÓÊ ÒÎÂÀÐÓ ÇÀ ÁÐÅÍÄÎÌ             |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Îáåð³òü òèï òîâàðó                             |" << endl
						<< "| 1 - Âçóòòÿ                                     |" << endl
						<< "| 2 - Ñóìêè                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Âàø âèá³ð | => ";
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
								<< "|                  ÏÎÌÈËÊÀ                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| Íåìàº òàêîãî âàð³àíòó âèáîðó! Ñïðîáóéòå ùå ðàç! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 6: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|               ÏÅÐÅÂ²ÐÊÀ ÇÀËÈØÊ²Â               |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Îáåð³òü òèï òîâàðó                             |" << endl
						<< "| 1 - Âçóòòÿ                                     |" << endl
						<< "| 2 - Ñóìêè                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Âàø âèá³ð | => ";
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
								<< "|                  ÏÎÌÈËÊÀ                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| Íåìàº òàêîãî âàð³àíòó âèáîðó! Ñïðîáóéòå ùå ðàç! |" << endl
								<< "---------------------------------------------------" << endl << endl;
							break;
						}
					}
					break;
				}
				case 7: {
					cout << endl << setiosflags(ios::left)
						<< "--------------------------------------------------" << endl
						<< "|                ÂÈÄÀËÅÍÍß ÒÎÂÀÐÓ                |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Îáåð³òü òèï òîâàðó                             |" << endl
						<< "| 1 - Âçóòòÿ                                     |" << endl
						<< "| 2 - Ñóìêè                                      |" << endl
						<< "--------------------------------------------------" << endl
						<< "| Âàø âèá³ð | => ";
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
								<< "|                  ÏÎÌÈËÊÀ                        |" << endl
								<< "---------------------------------------------------" << endl
								<< "| Íåìàº òàêîãî âàð³àíòó âèáîðó! Ñïðîáóéòå ùå ðàç! |" << endl
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
						<< "|                  ÏÎÌÈËÊÀ                        |" << endl
						<< "---------------------------------------------------" << endl
						<< "| Íåìàº òàêîãî âàð³àíòó âèáîðó! Ñïðîáóéòå ùå ðàç! |" << endl
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
		<< "|                                                                                  ÂÇÓÒÒß                                                                                 |" << endl
		<< "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|" << setw(15) << " Àðòèêóë" << "|" << setw(26) << " Íàçâà òîâàðó" << "|" << setw(20) << " Êàòåãîð³ÿ" << "|" << setw(15) << " Áðåíä" << "|" << setw(15)
		<< " Êîë³ð" << "|" << setw(15) << " Ðîçì³ð" << "|" << setw(15) << " Ê³ëüê³ñòü" << "|" << setw(15) << " Ö³íà çà ïàðó" << "|" << setw(25) << " Ïðèì³òêà" << "|" << endl
		<< "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	system.printFootwear();
	cout << endl << endl;
	Clear();
}

void CONSOLE::PrintBags() {
	std::system("CLS");
	cout  
		<< "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|                                                                       ÑÓÌÊÈ                                                                         |" << endl
		<< "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|" << setw(15) << " Àðòèêóë" << "|" << setw(26) << " Íàçâà òîâàðó" << "|" << setw(16) << " Êàòåãîð³ÿ" << "|" << setw(15) << " Áðåíä" << "|" << setw(15)
		<< " Êîë³ð" << "|" << setw(15) << " Ê³ëüê³ñòü" << "|" << setw(15) << " Ö³íà" << "|" << setw(25) << " Ïðèì³òêà" << "|" << endl
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
		<< "|                          ÄÎÄÀÂÀÍÍß ÒÎÂÀÐÓ                            |" << endl
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
		<< "|                          ÄÎÄÀÂÀÍÍß ÒÎÂÀÐÓ                            |" << endl
		<< "------------------------------------------------------------------------" << endl;
	system.addBags();
	cout << endl << endl << endl;
	Clear();
}

void CONSOLE::SearchFootwear() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                      ÏÎØÓÊ ÂÇÓÒÒß                       |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| Ââåä³òü íàçâó òîâàðó | => ";
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
		<< "|                      ÏÎØÓÊ CÓÌÎÊ                        |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| Ââåä³òü íàçâó òîâàðó | => ";
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
		<< "|              ÏÎØÓÊ ÂÇÓÒÒß ÇÀ ÊÀÒÅÃÎÐ²ªÞ                 |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| Ââåä³òü êàòåãîð³þ òîâàðó | => ";
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
		<< "|              ÏÎØÓÊ CÓÌÎÊ ÇÀ ÊÀÒÅÃÎÐ²ªÞ                  |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| Ââåä³òü êàòåãîð³þ òîâàðó | => ";
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
		<< "|                ÏÎØÓÊ ÂÇÓÒÒß ÇÀ ÁÐÅÍÄÎÌ                  |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| Ââåä³òü íàçâó áðåíäó | => ";
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
		<< "|                ÏÎØÓÊ CÓÌÎÊ ÇÀ ÁÐÅÍÄÎÌ                   |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| Ââåä³òü íàçâó áðåíäó | => ";
	cin.ignore();
	string brand = ConsoleIO::GetText(cin);
	system.searchBagsByBrand(brand);
	cout << endl << endl;
	Clear();
}

void CONSOLE::FootwearRemains() {
	cout 
		<< "-------------------------------------------------------------------------------" << endl
		<< "|                               ÇÀËÈØÊÈ ÂÇÓÒÒß                                |" << endl;
	system.footwearRemains();
	cout << endl << endl;
	Clear();
}

void CONSOLE::BagsRemains() {
	cout 
		<< "-------------------------------------------------------------------------------" << endl
		<< "|                                ÇÀËÈØÊÈ ÑÓÌÎÊ                                |" << endl;
	system.bagsRemains();
	cout << endl << endl;
	Clear();
}

void CONSOLE::DeleteFootwear() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                    ÂÈÄÀËÅÍß ÂÇÓÒÒß                      |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| Ââåä³òü íàçâó òîâàðó | => ";
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
		<< "|                    ÂÈÄÀËÅÍß ÑÓÌÎÊ                       |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| Ââåä³òü íàçâó òîâàðó | => ";
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
		<< "|                                                                                      ÏÐÀÖ²ÂÍÈÊÈ                                                                                             |" << endl
		<< "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< "|" << setw(15) << " Ïð³çâèùå" << "|" << setw(15) << " ²ì'ÿ" << "|" << setw(15) << " Ïî áàòüêîâ³" << "|" << setw(21) << " Äàòà íàðîäæåííÿ" << "|" << setw(20) << " Ïî÷àòîê ðîáîòè" 
		<< "|" << setw(15) << " Çì³íà" <<  "|" << setw(30) << " Ïîñàäà" << "|" << setw(15) << " Ðîáî÷å ì³ñöå" << "|" << setw(17) << " Çàðîá³òíà ïëàòà" << "|"<< setw(17) << " Ïðîäóêòèâí³ñòü" << "|" << endl
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
		<< "|                        ÄÎÄÀÂÀÍÍß ÏÐÀÖ²ÂÍÈÊÀ                          |" << endl
		<< "------------------------------------------------------------------------" << endl;
	system.addEmployee();
	cout << endl << endl;
	Clear();
}

void CONSOLE::SearchEnployee() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                    ÏÎØÓÊ ÏÐÀÖ²ÂÍÈÊ²Â                    |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << setiosflags(ios::left);
	cout << "| Ââåä³òü ïð³çâèùå ïðàö³âíèêà | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü iì'ÿ ïðàö³âíèêà | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü ïî áàòüêîâ³ ïðàö³âíèêà | => ";
	string searchSurname = ConsoleIO::GetText(cin);
	auto foundEmployeeIterator = system.searchEmployee(searchFirstName,searchLastName,searchSurname);
	cout << endl << endl;
	Clear();
}

void CONSOLE::ChangeEnployeePosition() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                   ÇÌ²ÍÀ ÐÎÁÎ×ÃÎ Ì²ÑÖß                   |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << "| Ââåä³òü ïð³çâèùå ïðàö³âíèêà | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü iì'ÿ ïðàö³âíèêà | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü ïî áàòüêîâ³ ïðàö³âíèêà | => ";
	string searchSurname = ConsoleIO::GetText(cin);
	system.changeEmployeePosition(system.searchEmployee(searchFirstName, searchLastName, searchSurname));
	cout << endl << endl;
	Clear();
}

void CONSOLE::ChackProductivity() {
	std::system("CLS");
	cout << "----------------------------------------------------------------------------------------" << endl
		 << "|                              ÏÐÎÄÓÊÒÈÂÍ²ÑÒÜ ÏÐÀÖ²ÂÍÈÊ²Â                              |" << endl;
	system.checkProductivity();
	cout << endl << endl;
	Clear();
}

void CONSOLE::DeleteEmployee() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|                  ÂÈÄÀËÅÍÍß ÏÐÀÖ²ÂÍÈÊÀ                   |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << "| Ââåä³òü ïð³çâèùå ïðàö³âíèêà | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü iì'ÿ ïðàö³âíèêà | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü ïî áàòüêîâ³ ïðàö³âíèêà | => ";
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
		<< "|                 ÐÅªÑÒÐÓÂÀÍÍß ÏÐÀÖ²ÂÍÈÊÀ Â ÑÈÑÒÅÌÓ                    |" << endl
		<< "------------------------------------------------------------------------" << endl;
	cout << "| Ââåä³òü ïð³çâèùå ïðàö³âíèêà | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü iì'ÿ ïðàö³âíèêà | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü ïî áàòüêîâ³ ïðàö³âíèêà | => ";
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
		<< "|                 ÊÎÐÈÑÒÓÂÀ×² ÑÈÑÒÅÌÈ                  |" << endl
		<< "--------------------------------------------------------" << endl
		<< "|" << setw(15) << " ID ïðàö³âíèêà" << "|" << setw(22) << " Ëîã³í" << "|" << setw(15) << " Ïàðîëü" << "|" << endl
		<< "--------------------------------------------------------" << endl;
	system.printSystemUsers();
	cout << endl << endl;
	Clear();
}

void CONSOLE::DeleteEmployeeFromSystem() {
	std::system("CLS");
	cout
		<< "-----------------------------------------------------------" << endl
		<< "|              ÂÈÄÀËÅÍÍß ÏÐÀÖ²ÂÍÈÊÀ Ç ÑÈÑÒÅÌÈ             |" << endl
		<< "-----------------------------------------------------------" << endl;
	cout << "| Ââåä³òü ïð³çâèùå ïðàö³âíèêà | => ";
	cin.ignore();
	string searchFirstName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü iì'ÿ ïðàö³âíèêà | => ";
	string searchLastName = ConsoleIO::GetText(cin);
	cout << "| Ââåä³òü ïî áàòüêîâ³ ïðàö³âíèêà | => ";
	string searchSurname = ConsoleIO::GetText(cin);
	system.deleteEmployeeFromSystem(system.searchEmployee(searchFirstName, searchLastName, searchSurname));
	cout << endl << endl;
	Clear();
}