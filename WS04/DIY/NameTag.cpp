#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include <string>
#include "NameTag.h"

namespace sdds
{
	NameTag::NameTag()
	{
		m_extNum = 0;
		m_name = nullptr;
	}

	NameTag::NameTag(const char* name)
	{

		if (this->isValid(name))
		{
			set(name);
		}
		else
		{
			*this = NameTag();
		}
	}

	NameTag::NameTag(const char* name, int extNum)
	{
		if (this->isValid(name) && this->isValid(extNum))
		{
			set(name, extNum);
		}
		else
		{
			*this = NameTag();
		}
	}

	NameTag::~NameTag()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	bool NameTag::isValid(int extNum) const
	{
		if (extNum == -1)
		{
			return true;
		}
		return extNum >= 10000 && extNum <= 99999;
	}

	bool NameTag::isValid(const char* name) const
	{
		return name != nullptr && std::strcmp(name, "\0") != 0;
	}

	void NameTag::set(const char* name)
	{
		set(name, 0);
	}


	void NameTag::set(const char* name, int extNum)
	{
		delete[] m_name;
		bool oversize = std::strlen(name) > MAX_NAMETAG;
		if (oversize) {
			char new_Name[MAX_NAMETAG + 1]{};
			for (int i = 0; i < MAX_NAMETAG; ++i)
			{
				new_Name[i] = name[i];
			}
			new_Name[MAX_NAMETAG] = '\0';
			m_name = new char[MAX_NAMETAG + 1];
			std::strcpy(m_name, new_Name);
		}
		else
		{
			m_name = new char[MAX_NAMETAG + 1];
			std::strcpy(m_name, name);
		}
		if (isValid(extNum))
		{
			m_extNum = extNum;
		}
		else
		{
			m_extNum = -1;
		}
	}

	NameTag& NameTag::read()
	{
		char name[MAX_NAMETAG + 1];
		char yn = ' ';
		int extNum;
		bool stop = true;
		std::cout << "Please enter the name: ";
		std::cin.clear();
		std::cin.getline(name, MAX_NAMETAG + 1);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(2000, '\n');

		}
		std::cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		
		while (stop)
		{

			std::cin >> yn;
			std::cin.ignore(2000, '\n');
			stop = yn != 'Y' && yn != 'N' && yn != 'n' && yn != 'y';
			if (stop)
			{
				std::cout << "Only (Y) or (N) are acceptable, try agin: ";
			}
		}
		stop = true;
		if (yn == 'Y' || yn == 'y')
		{
			std::cout << "Please enter a 5 digit phone extension: ";
			while (stop)
			{
				std::cin >> extNum;
				if (std::cin.fail()) // check for invalid character
				{
					std::cerr << "Bad integer value, try again: ";
					std::cin.clear();
					std::cin.ignore(2000, '\n');
				}
				else if (extNum < 10000 || extNum > 99999)
				{
					std::cerr << "Invalid value [10000<=value<=99999]: ";
					std::cin.ignore(2000, '\n');
				}
				else if (char(std::cin.get() != '\n'))
				{
					std::cerr << "Trailling characters. Try again: ";
					std::cin.ignore(2000, '\n');
				}
				else
				{
					stop = false;
				}

			}
			this->set(name, extNum);
		}
		else
		{
			this->set(name, -1);
		}
		return *this;
	}

	void NameTag::print(int snum) const
	{
		
		std::cout << std::setfill('-') << "+" << std::setw(snum + 1) << "+" << "\n" << std::setfill(' ') << "|" << std::setw(snum + 1) << "|" << "\n";
		std::cout << "| " << std::setw(snum - 1);
		std::cout.setf(std::ios::left);
		std::cout << m_name;
		std::cout.unsetf(std::ios::left);
		std::cout << "|\n";
		std::cout << "|" << std::setw(snum + 1) << "|" << "\n";
			
		if (m_extNum == -1)
		{
			std::cout << "|" << std::setw(snum);
			std::cout.setf(std::ios::left);
			std::cout << " Extension: N/A";
			std::cout.unsetf(std::ios::left);
			std::cout << "|\n";
			std::cout << "|" << std::setw(snum + 1) << "|" << "\n";

		}
		else
		{
			std::string s = std::to_string(m_extNum);
			const char* ext = s.c_str();
			char extension[20] = " Extension: ";
			strcat(extension, ext);
			std::cout << "|";
			std::cout.setf(std::ios::left);
			std::cout << std::setw(snum) <<
				extension;
			std::cout.unsetf(std::ios::left);
			std::cout << "|\n";
			std::cout << "|" << std::setw(snum + 1) << "|" << "\n";
		}
		std::cout << std::setfill('-') << "+" << std::setw(snum + 1) << "+" << "\n";
		
	}

	void NameTag::print() const
	{
		int len = 0;
		int snum = 22;
		int lnum = 42;

		if (isValid(m_name) && isValid(m_extNum))
		{

			len = strlen(m_name);
			if (len < 20)
			{
				print(snum);
			}

			if (len >= 20)
			{
				print(lnum);
			}
		}
		else
		{
			std::cout << "EMPTY NAMETAG!\n";
		}
	}
}
			