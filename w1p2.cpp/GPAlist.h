/***********************************************************************
// OOP244 Workshop 1 p2: GPAList header file
//
// File  GPAList.h
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name:Joshua Dinham 121572226    Date:Jan 26, 2023       Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_GPAlist_H
#define SDDS_GPAlist_H
#pragma once
#include "GPA.h"
#include "File.h"
#include "UI.h"

namespace sdds {

	//count the GPAList
	int countGPAList();

	//initialize this list with the information from the students.csv file
	bool initializeGPAList(const char filename[]);

	//print a singular GPA object
	void printGPA(GPA& gpa, int count);

	//sort GPA List by Student Num
	void sortGPAList(GPA list[], int count);

	//display users if the user enters <
	void displayGPAIncre(double maxGPA);

	//display students if the user enters >
	void displayGPADecre(double minGPA);

	//display students if the user enters ~
	void displayGPAPrecise(double gp);

	//determines which GPA function to use  based on the given character;
	void displayStudentWithGPA(char ch, double num);

	//starts program;
	bool gpaQuery(const char filename[]);

}
#endif