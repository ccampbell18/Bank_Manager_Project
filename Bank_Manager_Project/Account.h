#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>

class Account {

private:
	std::string fName;
	std::string lName;
	std::string address;
	std::string city;
	std::string pcode;
	std::string acctType;
	float acctBal;
	int acctNum;
	

public:
	Account();
	void createAcct();
	void depositAmt();
	void withdrawAmt();
	void showAcct();
	void editAcct();
	void Populate();
	void Write();
	void viewTrans();
	void viewBal();


};

#endif