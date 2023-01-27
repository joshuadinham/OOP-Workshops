/***********************************************************************
// Workshop 1 p2
//
// File  GPAlist.cpp
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
#include "GPAlist.h"
using namespace std;
#define GPALIST 87
namespace sdds {
	GPA gpaList[GPALIST];
	int countGPAList()
	{
		int size;
		size = (sizeof(gpaList)) / (sizeof(gpaList[0]));
		return size;
	}

	bool initializeGPAList(const char filename[])
	{
		GPA gpa;
		bool ok = true;
		int i = 0; // num of files read
		if (openFile(filename))
		{
			while (ok && i < GPAMAX)
			{
				ok = readStuName(gpa.name) &&
					readStuNum(&gpa.stno) &&
					readStuGPA(&gpa.gpa);
				if (ok) {

					gpaList[i++] = gpa;
				}
			}

			closeFile();
		}


		return !ok;
	}

	void sortGPAList(GPA list[], int count)
	{
		int j = 0;
		int i = 0;
		GPA temp = list[i];

		bool flag = false;
		for (i = 0; i < count && !flag; ++i) {
			for (j = i + 1; j < count; ++j)
			{
				if (list[i].stno > list[j].stno) {

					temp = list[i];
					list[i] = list[j];
					list[j] = temp;
				}

			}
		}
	}

	void displayGPAIncre(double maxGPA)
	{
		int size = countGPAList();
		bool flag = false;
		GPA gpa;
		int j = 0;

		for (int h = 1; h < size && !flag; h++)
		{
			if (gpaList[h].gpa < maxGPA)
			{
				gpa = gpaList[h];
				printGPA(gpa, ++j);

			}
		}
	}

	void displayGPADecre(double minGPA)
	{
		int size = countGPAList();
		bool flag = false;
		GPA gpa;
		int j = 0;

		for (int h = 1; h < size && !flag; h++)
		{
			if (gpaList[h].gpa > minGPA)
			{
				gpa = gpaList[h];
				printGPA(gpa, ++j);

			}
		}
	}

	void displayGPAPrecise(double gp)
	{
		int size = countGPAList();
		bool flag = false;
		GPA gpa;
		int j = 0;

		for (int h = 1; h < size && !flag; h++)
		{
			if (gpaList[h].gpa == gp)
			{
				gpa = gpaList[h];
				printGPA(gpa, ++j);

			}
		}
	}

	void displayStudentWithGPA(char ch, double num)
	{
		if (ch == '<')
		{
			displayGPAIncre(num);
		}
		else if (ch == '>')
		{
			displayGPADecre(num);
		}
		else if (ch == '~')
		{
			displayGPAPrecise(num);
		}

	}

	bool gpaQuery(const char filename[])
	{

		if (initializeGPAList(filename))
		{
			sortGPAList(gpaList, countGPAList());
			prompt();
			return true;
		}
		else
		{
			return false;
		}
	}
}