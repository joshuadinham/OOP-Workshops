/***********************************************************************
// OOP244 Workshop 1 p2: GPA header file
//
// File  GPA.h
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
#ifndef SDDS_GPA_H
#define SDDS_GPA_H
#define GPAMAX 87
namespace sdds
{
	struct GPA {
		char name[116];
		double gpa;
		int stno;
	};
}
#endif !SDDS_GPA_H

