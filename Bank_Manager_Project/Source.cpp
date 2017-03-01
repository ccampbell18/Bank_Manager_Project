

#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include<sstream>
#include "Account.h"


void mainMenu();

int main()
{
	Account userAcct;
	userAcct.Populate();
	
	mainMenu();
	
	return 0;
}

void mainMenu()
{
	int choice = 0;
	Account userAcct;

	std::cout << "\n\n\t\t\t==> Charles National Bank <==\n\n" << std::endl;
	std::cout << "1. Create an Account" << std::endl;
	std::cout << "2. Make a Deposit" << std::endl;
	std::cout << "3. Make a Withdrawl" << std::endl;
	std::cout << "4. View Account Information" << std::endl;
	std::cout << "5. Edit Account Information" << std::endl;
	std::cout << "6. View Transactions" << std::endl;
	std::cout << "7. View Current Balance" << std::endl;
	std::cout << "8. Exit" << std::endl;
	std::cout << "\nChoice : ";
	std::cin >> choice;


	switch (choice)
	{
	case 1:
		userAcct.createAcct();
		mainMenu();
		break;

	case 2:
		userAcct.depositAmt();
		mainMenu();
		break;

	case 3:
		userAcct.withdrawAmt();
		mainMenu();
		break;

	case 4:
		userAcct.showAcct();
		mainMenu();
		break;
	
	case 5:
		userAcct.editAcct();
		mainMenu();
		break;

	case 6:
		userAcct.viewTrans();
		mainMenu();
		break;

	case 7:
		userAcct.viewBal();
		mainMenu();
		break;

	case 8:
		userAcct.Write();
		std::cout << "Goodbye!" << std::endl;
		break;

	default:
		std::cout << "\nNo Option Available" << std::endl;
		mainMenu();
		break;

	}
}
	
