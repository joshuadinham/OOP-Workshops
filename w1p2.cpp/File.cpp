/***********************************************************************
// Workshop 1 p2: tester program
//
// File  File.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"
using namespace std;
namespace sdds
{
    FILE* fptr;
     //opens the data file and returns true is successful
    bool openFile(const char filename[]){
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    void closeFile()
    {
        if (fptr) fclose(fptr);
    }

    // reads the student's name from the global fptr File pointer
    // returns true if successful
    bool readStuName(char s_name[])
    {
        bool found = false;
        found = fscanf(fptr, "%[^,]", s_name);
        return found;
    }

    //reads the student's ID# from the global fptr File pointer
    bool readStuNum(int* num)
    {
        return fscanf(fptr, ",%d,", num) == 1;
    }

    bool readStuGPA(double* gpa)
    {
        return fscanf(fptr, "%lf\n", gpa) == 1;
    }
}