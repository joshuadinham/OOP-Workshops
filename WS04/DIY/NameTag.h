#pragma once
#ifndef NAMETAG_H
#include <iostream>
#define MAX_NAMETAG 40
/*
Joshua Dinham
121572226
BTP200 NAA
Feb 16 2023
*/
namespace sdds
{
	class NameTag
	{
		char* m_name = nullptr;
		int m_extNum = 0;

	public:
		NameTag& read();
		void print() const;
		void print(int) const;

		NameTag();
		NameTag(const char* name);
		NameTag(const char* name, int extNum);
		~NameTag();
		bool isValid(int) const;
		bool isValid(const char* name) const;
		void set(const char* name, int extNum);
		void set(const char* name);

	};

}
#endif // !NAMETAG_H

