#pragma once
#ifndef SDDS_STUDENT_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_STUDENT_H
namespace sdds
{
	struct Student
	{
		char s_name[30];
		int s_num;
		float s_gpa;
	};
	Student stu[87];

	bool loadStudent();
	bool hasGPA(const Student* stu, float* gpa);
	void displayStudent(const Student* stu);
	void displayStudentWithGPA(float* gpa);
	
}

#endif