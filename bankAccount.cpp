#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int SIZE = 10; //How many structs you want to make for bankAccounts

/************************************************
/* STRUCTURE NAME: Account
/*
/* DATA ELEMENTS WITH DESCRIPTION: acctID - Account ID of the Account
/*                                 firstName - First Name of the Account Owner
/*                                 lastName - Last Name of the Account Owner
/*                                 balance - The balance that is in the Account
/************************************************/
struct Account{
	int acctID;
	char firstName[51];
	char lastName[51];
	double balance;
};

Account bankAccount[SIZE];	

void getAccountData();
void writeAccountBinary();
void readAccountsByRecord();
void showAccounts();
void showRelativeRecord();


/*********************************************
/* FILE NAME: bankAccount.cpp
/*
/* AUTHOR: Beth Mitchell
/* 
/* DESCRIPTION: Gathers User information and puts it into a struct.
/*              The struct is then written into a file in binary, 
/*              Read back file by file, and the user is then asked
/*              which relative record they want returned back.
/*******************************************************************/
int main(){
	
	getAccountData(); //get User data for account
	writeAccountBinary(); //write account to file in binary	
	readAccountsByRecord(); //read in accounts by record
	showAccounts();	//display account on screen
	showRelativeRecord(); //display user's chosen relative record
	return 0;
}

/****************************************************
/* FUNCTION NAME: getAccountData
/*
/* DESCRIPTION: gets User information and puts it into a struct called bankAccount
/* 
/* PARAMETERS: None
/* 
/* RETURN VALUES: None
/********************************************************/
void getAccountData()
{	
	for (int i = 0; i < SIZE; i++){
		cout << "Enter Account ID: ";
		cin >> bankAccount[i].acctID;
		if(!bankAccount[i].acctID)
		{
			cout << "You did not enter a valid Account Number!\n";
			exit(1);
		}
		cout << "Enter first name: ";
		cin >> bankAccount[i].firstName;
		cout << "Enter last name: ";
		cin >> bankAccount[i].lastName;
		cout << "Enter your balance: ";
		cin >> bankAccount[i].balance;
		if(!bankAccount[i].balance)
			{
				cout << "You did not enter a valid Balance!\n";
				exit(1);
			}
		cout << endl;
	}
}

/****************************************************
/* FUNCTION NAME: writeAccountBinary
/*
/* DESCRIPTION: Takes the struct bankAccount and writes it to the file
/*              accounts.dat in binary
/* 
/* PARAMETERS: None
/* 
/* RETURN VALUES: None
/********************************************************/
void writeAccountBinary()
{
	ofstream outFile;
	
	outFile.open("accounts.dat", ios::binary);//open file for writing
	
	if(!outFile)
	{
		cout << "Could not open file.";
		exit(1);
	}
		
	outFile.write(reinterpret_cast<char *>(&bankAccount), sizeof(bankAccount)); //write bankAccount to file
	outFile.close();
}

/****************************************************
/* FUNCTION NAME: readAccountsByRecord
/*
/* DESCRIPTION: Opens accounts.dat and reads in file record by record
/*              until EOF is hit
/* 
/* PARAMETERS: None
/* 
/* RETURN VALUES: None
/********************************************************/
void readAccountsByRecord()
{
	ifstream inFile;
	inFile.open("accounts.dat", ios::binary);//open file for reading
	
	if(!inFile)
	{
		cout << "Could not open file.";
		exit(1);
	}
	
	Account printBankAccount; // new structure for data read in from file 
	
	inFile.read(reinterpret_cast<char *>(&printBankAccount), sizeof(printBankAccount)); //read in file to printBankAccount
	
	//While EOF is not met, continue reading into printBankAccount
	while(!inFile.eof())
	{		
		inFile.read(reinterpret_cast<char *>(&printBankAccount), sizeof(printBankAccount));
	}
	
	
	inFile.close();
}

/****************************************************
/* FUNCTION NAME: showAccounts
/*
/* DESCRIPTION: Displays the Accounts in bankAccounts on the screen
/* 
/* PARAMETERS: None
/* 
/* RETURN VALUES: None
/********************************************************/
void showAccounts()
{
	const char separator    = ' ';
	const int recordNumWidth = 25;
    const int acctNumWidth = 20;
    const int nameWidth = 20;
	const int balanceWidth = 10;
	
	cout << left << setw(recordNumWidth) << setfill(separator) << "Relative Record Number";
    cout << left << setw(acctNumWidth) << setfill(separator) << "Account Number";
    cout << left << setw(nameWidth) << setfill(separator) << "Last Name";
    cout << left << setw(nameWidth) << setfill(separator) << "First Name";
    cout << left << setw(balanceWidth) << setfill(separator) << "Balance";
    cout << endl;
	
    for (int i = 0; i < SIZE; i++)
    {		
		cout << left << setw(recordNumWidth) << setfill(separator) << i+1;
		cout << left << setw(acctNumWidth) << setfill(separator) << bankAccount[i].acctID;
		cout << left << setw(nameWidth) << setfill(separator) << bankAccount[i].firstName;
		cout << left << setw(nameWidth) << setfill(separator) << bankAccount[i].lastName;
		cout << left << "$" << setw(balanceWidth) << setfill(separator) << bankAccount[i].balance;
		cout << endl;
	}
	
	cout << endl << "Accounts Displayed Successfully!\n";
}

/****************************************************
/* FUNCTION NAME: showRelativeRecord
/*
/* DESCRIPTION: Allows the user to choose which record they want and then 
/*              prints it to the screen
/* 
/* PARAMETERS: None
/* 
/* RETURN VALUES: None
/********************************************************/
void showRelativeRecord()
{
	Account bankAccountRecord;
	ifstream inFile;
	inFile.open("accounts.dat", ios::binary);//open file for reading
	
	if(!inFile)
	{
		cout << "Could not open file.";
		exit(1);
	}
	
	int relativeRecordNum;
	int seekNumber;
	
	cout << "Please enter the number for the relative record you want: ";
	cin >> relativeRecordNum;
	
	if(relativeRecordNum>SIZE || !relativeRecordNum)
	{
		cout << "Your record was not found.\n";
		exit(1);
	}
	
	
	seekNumber = sizeof(bankAccountRecord)*(relativeRecordNum-1);//translate record request into size of binary
	inFile.seekg(seekNumber, ios::beg);	//search through bankAccountRecord to find record
	
	inFile.read(reinterpret_cast<char *>(&bankAccountRecord), sizeof(bankAccountRecord));//read in bankAccountRecord
	cout << "The record you selected was: " << bankAccountRecord.acctID << ", " << bankAccountRecord.firstName << ", " 
	     << bankAccountRecord.lastName << ", " << bankAccountRecord.balance << endl;
		 
	inFile.close();
}