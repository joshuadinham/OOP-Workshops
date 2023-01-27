/***********************************************************************
// OOP244 Workshop 1 p2: UI header file
//
// File  UI.h
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name Joshua Dinham 121572226           Date Jan 26, 2016           Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#pragma once
#ifndef SDDS_UI_H
#define SDDS_UI_H
#include "GPAlist.h"
namespace sdds {
	//Check if the first character in the string the user gives is NOT a <>~! 
	bool validateQuery(char ch[]);

	//prompt the user with an error message telling them the correct string
	void invalidQueryMsg();

	//If the user enters a string with only ! or ! followed by a number = exit program
	bool exitProgram(const char ch[]);

	// If user enters a string with the proper characters <>~
		//Dynamically create new string with the 'proper character' removed, leaving only the number;
	double convertStrDbl(const char ch[]);

	//Takes user input yes or no upon exit program
	bool yes(const char ch[]);

	//Prompt user for GPA query
	void prompt();
}
#endif
