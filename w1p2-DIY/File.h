/***********************************************************************
// OOP244 Workshop 1 p2: File header file
//
// File  File.h
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
#ifndef SDDS_FILE_H 
#define SDDS_FILE_H
namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	bool readStuName(char s_name[]);
	bool readStuNum(int* num);
	bool readStuGPA(double* gpa);
}
#endif