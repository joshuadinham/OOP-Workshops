/***********************************************************************
// Workshop 1 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "GPAlist.h"
#include "UI.h"
#include "File.h"
using namespace sdds;
using namespace std;
int main() {

	/*if(gpaQuery("std.csv")) {
		std::cout << "This should have failed!" << std::endl;
	} else {
		std::cout << "failed!, this is the correct exectution" << std::endl;
	}
	if(!gpaQuery("students.csv")) {
		std::cout << "This should have worked, fix the problem!" << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;*/
	gpaQuery("students.csv");
	//cout << "Enter GPU Query..." << endl;
	prompt();
	
	

}