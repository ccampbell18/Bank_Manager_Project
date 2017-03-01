#include "Account.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<vector>
#include <iomanip>


std::vector<int> acctNums;
std::vector<std::string> firstNames;
std::vector<std::string> lastNames;
std::vector<std::string> strAdd;
std::vector<std::string> Cities;
std::vector<std::string> Zips;
std::vector<std::string> Types;

Account::Account()
{              
	acctBal = 0.00;
}

void Account::createAcct()
{

	std::cout << "\nEnter your first name: ";
	std::cin >> fName;
	std::cin.ignore();
	std::cout << "\nEnter your last name: ";
	std::cin >> lName;
	std::cin.ignore();
	std::cout << "\nEnter your address: ";
	std::getline(std::cin, address);
	std::cin.ignore();
	std::cout << "\nEnter your city: ";
	std::getline(std::cin, city);
	std::cin.ignore();
	std::cout << "\nEnter your postal code: ";
	std::cin >> pcode;
	std::cin.ignore();
	std::cout << "\nEnter account type(Checking or Savings): ";
	std::cin >> acctType;
	std::cin.ignore();
	std::cout << "\nEnter Initial Balance: ";
	std::cin >> acctBal;
	std::cin.ignore();
	
	int tidx = acctNums.size() - 1;
	if(acctNums.size() == 0)
	{
		acctNum = 100100;
	}
	else {
		acctNum = acctNums[tidx] + 1;
	}
	std::cout << "Your new accout number is: " << acctNum << std::endl;
	std::stringstream ss;
	ss << "Debug/" << acctNum << ".txt";
	std::ofstream file(ss.str().c_str());
	file << acctBal<<","<<0<<","<<0;
	file.close();

	
	
	acctNums.push_back(acctNum);
	firstNames.push_back(fName);
	lastNames.push_back(lName);
	strAdd.push_back(address);
	Cities.push_back(city);
	Zips.push_back(pcode);
	Types.push_back(acctType);

}

void Account::depositAmt()
{
	int tempAcct;
	int tidx = -1;
	std::cout << "Enter account number: ";
	std::cin >> tempAcct;

	for (int i = 0; i < acctNums.size(); i++)
	{
		if (acctNums[i] == tempAcct)
		{
			tidx = i;
		}
	}

	if (tidx == -1)
	{
		std::cout << "Account does not exist.";
	}
	else {

		std::stringstream ss;
		ss << "Debug/" << tempAcct << ".txt";
		std::fstream file(ss.str().c_str());

		float dep;
		float temp;
		std::string line;
		std::cout << "\nEnter amount to be deposited: ";
		std::cin >> dep;

		while (getline(file, line))
		{



			std::istringstream iss(line);
			std::string data;

			getline(iss, data, ',');
			temp = atoi(data.c_str());
		}
		std::cout << "New Balance: " << temp + dep << std::endl;
		file.close();

		std::fstream fileO(ss.str().c_str(), std::ios::app);
		fileO << "\n"<< temp + dep << "," << dep << "," << 0;

		
	}
}

void Account::withdrawAmt()
{
	int tempAcct;
	int tidx = -1;
	std::cout << "Enter account number: ";
	std::cin >> tempAcct;

	for (int i = 0; i < acctNums.size(); i++)
	{
		if (acctNums[i] == tempAcct)
		{
			tidx = i;
		}
	}

	if (tidx == -1)
	{
		std::cout << "Account does not exist.";
	}
	else {

		std::stringstream ss;
		ss << "Debug/" << tempAcct << ".txt";
		std::fstream file(ss.str().c_str());

		float wit;
		float temp;
		std::string line;
		std::cout << "\nEnter amount to be withdrawn: ";
		std::cin >> wit;

		while (getline(file, line))
		{



			std::istringstream iss(line);
			std::string data;

			getline(iss, data, ',');
			temp = atoi(data.c_str());
		}
		std::cout << "New Balance: " << temp - wit << std::endl;
		file.close();

		std::fstream fileO(ss.str().c_str(), std::ios::app);
		fileO << "\n" << temp - wit << "," << 0 << "," << wit;


	}
}

void Account::showAcct()
{
	int tempAcct;
	int tidx = -1;
	std::cout << "Enter account number: ";
	std::cin >> tempAcct;

	for (int i = 0; i < acctNums.size(); i++)
	{
		if (acctNums[i] == tempAcct)
		{
			tidx = i;
		}
	}

	if (tidx == -1)
	{
		std::cout << "Account does not exist.";
	}
	else {

		std::cout << "Name: " << firstNames[tidx] << " " << lastNames[tidx];
		std::cout << "\nAddress: " << strAdd[tidx];
		std::cout << "\nCity: " << Cities[tidx];
		std::cout << "\nPostal Code: " << Zips[tidx];
		std::cout << "\n";
	}
}

void Account::editAcct()
{
	
	int tempAcct;
	int tidx = -1;
	char choice;
	std::cout << "Enter account number: ";
	std::cin >> tempAcct;

	for (int i = 0; i < acctNums.size(); i++)
	{
		if (acctNums[i] == tempAcct)
		{
			tidx = i;
		}
	}

	if (tidx == -1)
	{
		std::cout << "Account does not exist.";
	
	}
	else {

		std::cout << "Name: " << firstNames[tidx] << " " << lastNames[tidx];
		std::cout << "\nAddress: " << strAdd[tidx];
		std::cout << "\nCity: " << Cities[tidx];
		std::cout << "\nPostal Code: " << Zips[tidx];
		std::cout << "\nAccount Type: " << Types[tidx];
		std::cout << "\nDoes this look correct?(Y for yes or N for no): ";

		std::cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			int echoice = 0;
			bool exit = false;
			while (exit == false) {
				std::cout << "\n\n\t\t\tChoose What to Edit\n\n" << std::endl;
				std::cout << "1. First Name" << std::endl;
				std::cout << "2. Last Name" << std::endl;
				std::cout << "3. Street Address" << std::endl;
				std::cout << "4. City" << std::endl;
				std::cout << "5. Zip Code" << std::endl;
				std::cout << "6. Account Type" << std::endl;
				std::cout << "7. Exit" << std::endl;
				std::cout << "\nChoice : ";
				std::cin >> echoice;


				switch (echoice)
				{
				case 1:
					char choice1;
					std::cout << "Please enter new First Name: ";
					std::cin >> fName;
					std::cout << "\nChange First Name from " << firstNames[tidx] << " to " << fName << "?";
					std::cout << "\nY for Yes or N for No: ";
					std::cin >> choice1;
					if (choice1 == 'Y' || choice1 == 'y')
					{
						char choicej;
						firstNames[tidx] = fName;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicej;
						if (choicej == 'Y' || choicej == 'y')
						{
							break;
						}
						else if (choicej == 'N' || choicej == 'n')
						{
							exit = true;
							break;
						}
		
					}
					else if (choice1 == 'N' || choice1 == 'n')
					{
						char choicek;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicek;
						if (choicek == 'Y' || choicek == 'y')
						{
							break;
						}
						else if (choicek == 'N' || choicek == 'n')
						{
							exit = true;
							break;
						}
					}

					break;

				case 2:
					char choice2;
					std::cout << "Please enter new Last Name: ";
					std::cin >> lName;
					std::cout << "\nChange Last Name from " << lastNames[tidx] << " to " << lName << "?";
					std::cout << "\nY for Yes or N for No: ";
					std::cin >> choice2;
					if (choice2 == 'Y' || choice2 == 'y')
					{
						char choicej;
						lastNames[tidx] = lName;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicej;
						if (choicej == 'Y' || choicej == 'y')
						{
							break;
						}
						else if (choicej == 'N' || choicej == 'n')
						{
							exit = true;
							break;
						}

					}
					else if (choice2 == 'N' || choice2 == 'n')
					{
						char choicek;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicek;
						if (choicek == 'Y' || choicek == 'y')
						{
							break;
						}
						else if (choicek == 'N' || choicek == 'n')
						{
							exit = true;
							break;
						}
					}

					break;

				case 3:
					char choice3;
					std::cout << "Please enter new Street Address: ";
					std::cin.ignore();
					getline(std::cin, address);
					std::cout << "\nChange Street Address from " << strAdd[tidx] << " to " << address << "?";
					std::cout << "\nY for Yes or N for No: ";
					std::cin >> choice3;
					if (choice3 == 'Y' || choice3 == 'y')
					{
						char choicej;
						strAdd[tidx] = address;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicej;
						if (choicej == 'Y' || choicej == 'y')
						{
							break;
						}
						else if (choicej == 'N' || choicej == 'n')
						{
							exit = true;
							break;
						}

					}
					else if (choice3 == 'N' || choice3 == 'n')
					{
						char choicek;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicek;
						if (choicek == 'Y' || choicek == 'y')
						{
							break;
						}
						else if (choicek == 'N' || choicek == 'n')
						{
							exit = true;
							break;
						}
					}

					break;

				case 4:
					char choice4;
					std::cout << "Please enter new City: ";
					std::cin.ignore();
					getline(std::cin, city);
					std::cout << "\nChange City from " << Cities[tidx] << " to " << city << "?";
					std::cout << "\nY for Yes or N for No: ";
					std::cin >> choice4;
					if (choice4 == 'Y' || choice4 == 'y')
					{
						char choicej;
						Cities[tidx] = city;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicej;
						if (choicej == 'Y' || choicej == 'y')
						{
							break;
						}
						else if (choicej == 'N' || choicej == 'n')
						{
							exit = true;
							break;
						}

					}
					else if (choice4 == 'N' || choice4 == 'n')
					{
						char choicek;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicek;
						if (choicek == 'Y' || choicek == 'y')
						{
							break;
						}
						else if (choicek == 'N' || choicek == 'n')
						{
							exit = true;
							break;
						}
					}

					break;

				case 5:
					char choice5;
					std::cout << "Please enter new Zip Code: ";
					std::cin >> pcode;
					std::cout << "\nChange Last Name from " << Zips[tidx] << " to " << pcode << "?";
					std::cout << "\nY for Yes or N for No: ";
					std::cin >> choice5;
					if (choice5 == 'Y' || choice5 == 'y')
					{
						char choicej;
						Zips[tidx] = pcode;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicej;
						if (choicej == 'Y' || choicej == 'y')
						{
							break;
						}
						else if (choicej == 'N' || choicej == 'n')
						{
							exit = true;
							break;
						}

					}
					else if (choice5 == 'N' || choice5 == 'n')
					{
						char choicek;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicek;
						if (choicek == 'Y' || choicek == 'y')
						{
							break;
						}
						else if (choicek == 'N' || choicek == 'n')
						{
							exit = true;
							break;
						}
					}

					break;

				case 6:
					char choice6;
					std::cout << "Please enter new Account Type(Checking or Savings): ";
					std::cin >> acctType;
					std::cout << "\nChange First Name from " << Types[tidx] << " to " << acctType << "?";
					std::cout << "\nY for Yes or N for No: ";
					std::cin >> choice6;
					if (choice6 == 'Y' || choice6 == 'y')
					{
						char choicej;
						Types[tidx] = acctType;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicej;
						if (choicej == 'Y' || choicej == 'y')
						{
							break;
						}
						else if (choicej == 'N' || choicej == 'n')
						{
							exit = true;
							break;
						}

					}
					else if (choice6 == 'N' || choice6 == 'n')
					{
						char choicek;
						std::cout << "Do you want to make any more changes?";
						std::cout << "\nY for Yes or N for No: ";
						std::cin >> choicek;
						if (choicek == 'Y' || choicek == 'y')
						{
							break;
						}
						else if (choicek == 'N' || choicek == 'n')
						{
							exit = true;
							break;
						}
					}

					break;

					
					
				case 7:
					std::cout << "Thank You!!" << std::endl;
					exit = true;
					break;

				default:
					std::cout << "\nNo Option Available" << std::endl;
					break;

				}

			}
		}
	}



}

void Account::Populate()
{
	std::fstream file;
	std::string line;

	file.open("Debug/Master.txt");

	while (getline(file, line))
	{



		std::istringstream iss(line);
		std::string data;
		int temp;

		getline(iss, data, ',');
		temp = atoi(data.c_str());
		acctNums.push_back(temp);
		getline(iss, data, ',');
		firstNames.push_back(data);
		getline(iss, data, ',');
		lastNames.push_back(data);
		getline(iss, data, ',');
		strAdd.push_back(data);
		getline(iss, data, ',');
		Cities.push_back(data);
		getline(iss, data, ',');
		Zips.push_back(data);
		getline(iss, data, ',');
		Types.push_back(data);

	}
}

void Account::Write()
{
	std::fstream file;
	file.open("Debug/Master.txt");


		for (int i = 0; i < acctNums.size()-1; i++)
		{

			file << acctNums[i] << "," << firstNames[i] << ","
				<< lastNames[i] << "," << strAdd[i] << "," << Cities[i] << ","
				<< Zips[i] << "," << Types[i] << std::endl;
		}
		int tidx = acctNums.size() - 1;
		file << acctNums[tidx] << "," << firstNames[tidx] << ","
			<< lastNames[tidx] << "," << strAdd[tidx] << "," << Cities[tidx] << ","
			<< Zips[tidx] << "," << Types[tidx];
		file.close();


}

void Account::viewTrans()
{
	int tempAcct;
	int tidx = -1;
	std::cout << "Enter account number: ";
	std::cin >> tempAcct;

	for (int i = 0; i < acctNums.size(); i++)
	{
		if (acctNums[i] == tempAcct)
		{
			tidx = i;
		}
	}

	if (tidx == -1)
	{
		std::cout << "Account does not exist.";
	}
	else {

		std::stringstream ss;
		ss << "Debug/" << tempAcct << ".txt";
		std::fstream file(ss.str().c_str());

		std::vector<std::string> dep;
		std::vector<std::string> wit;
		std::vector<std::string> bal;
		std::string line;
		

		while (getline(file, line))
		{
			std::istringstream iss(line);
			std::string data;

			getline(iss, data, ',');
			bal.push_back(data);
			getline(iss, data, ',');
			dep.push_back(data);
			getline(iss, data, ',');
			wit.push_back(data);

		}

		std::cout << "Running Balance" << std::setw(20) << "Deposits" << std::setw(20) << "Withdrawls" << std::endl;
		std::cout << std::setw(55) << std::setfill('-') << "" << std::endl;

		for(int i = 0;i<bal.size();i++)
		{
			std::cout << std::setfill(' ') << std::setw(8) << bal[i] << std::setw(25) << dep[i] << std::setw(21) << wit[i]  << std::endl;
		}
		std::cout << std::setw(55) << std::setfill('-') << "" << std::endl;
		std::cout << std::setfill(' ') << "Your Current Balance is: " << bal[bal.size() - 1] << std::endl;
	}

}

void Account::viewBal()
{
	int tempAcct;
	int tidx = -1;
	std::cout << "Enter account number: ";
	std::cin >> tempAcct;

	for (int i = 0; i < acctNums.size(); i++)
	{
		if (acctNums[i] == tempAcct)
		{
			tidx = i;
		}
	}

	if (tidx == -1)
	{
		std::cout << "Account does not exist.";
	}
	else {

		std::stringstream ss;
		ss << "Debug/" << tempAcct << ".txt";
		std::fstream file(ss.str().c_str());

		std::string bal;
		std::string line;

		while (getline(file, line))
		{



			std::istringstream iss(line);
			std::string data;

			getline(iss, data, ',');
			bal = data;
		}
		std::cout << "Your Current Balance is: " << bal << std::endl;
		file.close();

	}

}