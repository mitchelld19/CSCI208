#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;
/********************************************
/* FILE NAME: Luhn Checksum
/*
/* AUTHOR: Darby Mitchell
/*
/* DESCRIPTION:  This program takes a number of any length and determines whether
/*               that number is valid using the lugn formula.
/*
/*************************************************/
int main(){

	string number;
	int sum=0, numPosition, checkDigit; /* Sum calculates the total sum of numbers,
	    /* numPosition is the position in the string, checkDigit is the check number 
		/* if it is not divisible by 10 */
	bool doubNum = true; //Flag that tells when to double numbers
	
	cout << "Please enter a number: ";
	cin >> number;
	
	numPosition = number.length()-1;
	
	for(; numPosition>=0; numPosition--)
	{
		//cout << "Position: " << numLength << ": ";
		int digit = number[numPosition] - '0'; //changing the string to an int with atoi
		
		//checks to see if digit is a number and not a char
		if(isdigit(digit))
		{
			cout << "You entered a letter, Please try again!\n";
			return 0;
		}
		else{
			//if doubNum is true, double the digit
			if(doubNum==true)
			{	
				digit = digit*2;
				
				//if the digit is above 10, add the 2 nums together
				if(digit>=10){
					digit = (digit-10)+1;
				}
				doubNum = false; //change doubNum to false
			}
			//if doubNum is false, change it back to true
			else if(doubNum==false)
			{
				doubNum = true;
			}
			sum+=digit; //add digit to sum
		}
	}
	
	//checks if sum is divisible by 10 with no remainder
			if(sum%10==0)
			{
				cout << number << " is valid.\n";
			}
			else{
				cout << number << " is not valid.\n";
			}
			
			//checks if number length is even or odd
			if((numPosition+1)%2 == 0){
				cout << "Your number length is even.\n";
			}
			else{
				cout << "Your number length is odd.\n";
			}
			
			int checkMod = sum%10; //number you get when you mod 10 
			checkDigit = 10 - checkMod;

			cout << "Total Sum: " << sum << "\n";
			cout << "Mod10: " << checkMod << "\n";
			cout << "Check Digit: " << checkDigit << "\n";
	
	return 0;
}