#pragma once
#ifndef SDDS_FILE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_FILE_H
#include "GPA.h"
namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	bool readStuName(char s_name[]);
	bool readStuNum(int* num);
	bool readStuGPA(double* gpa);
}
#endif