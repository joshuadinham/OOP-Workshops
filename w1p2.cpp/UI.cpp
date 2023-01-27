/***********************************************************************
// Workshop 1 p2:UI 
//
// File  UI.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name:Joshua Dinham  121572226 Date Jan 26, 2023        Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "UI.h"
using namespace std;
namespace sdds {

	bool validateQuery(char ch[])
	{
		return !(ch[0] == '<' || ch[0] == '>' || ch[0] == '~' || ch[0] == '!');
	}

	void invalidQueryMsg()
	{
		cout << "Syntax error: ? [Op][value]<ENTER>" << endl <<
			"Op: [> , < , ~, !]" << endl <<
			"value : GPA value" << endl << endl;
	}

	bool exitProgram(const char ch[])
	{
		return (ch[0] == '!');
	}

	double convertStrDbl(const char ch[])
	{
		const int size = 4;
		bool isDigit = true;
		char convert[size];
		int i = 0;

		//convert the string given into a number only by removing only the first character;
		for (int i = 1, j = 0; i < 4; ++i)
		{
			convert[j++] = ch[i];
		}

		//check if the converted string is a digit or not
		for (i = 0; isDigit && i < 3; i++)
		{
			isDigit = (convert[i] == '0' || convert[i] == '1' || convert[i] == '2'
				|| convert[i] == '3' || convert[i] == '4' || convert[i] == '5' || convert[i] == '6'
				|| convert[i] == '7' || convert[i] == '8' || convert[i] == '9' || convert[i] == '.');
		}

		if (!isDigit)
		{
			//return 0 and print error message if there are any characters in the string that are not accepted after conversion;
			cout << convert << " is not a digit!" << endl;
			return 0;
		}
		else
		{
			//convert the new string into double and return;
			return atof(convert);
		}

	}

	bool yes(const char ch[])
	{
		return (ch[0] == 'y' || ch[0] == 'Y');
	}

	void prompt()
	{
		char query[5];
		bool flag = false;
		bool repeat = false;
		double gpa = 0.0;
		cout << "Enter GPA query..." << endl;
		while (!flag)
		{
			cout << "? ";
			cin >> query;
			repeat = validateQuery(query);
			while (repeat)
			{
				invalidQueryMsg();
				repeat = false;
			}
			if (exitProgram(query))
			{
				char ch[4];
				cout << "Exit the program? (Y)es/(N)o: ";
				cin >> ch;
				flag = yes(ch);

			}
			else
			{
				gpa = convertStrDbl(query);
				displayStudentWithGPA(query[0], gpa);
			}


		}

	}
}
