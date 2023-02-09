#define _CRT_SECURE_NO_WARNINGS
#include "Toys.h"
#include <iostream>
#include <cstring>
/*
File: Toys.cpp
Joshua Dinham
121572226
Feb 8 2023
BTP200 NAA
*/
using namespace std;
namespace sdds 
{
	int Toys::getSKU()
	{
		return m_sku;
	}


	void Toys::addToys(const char* tname, int sku, double price, int age)
	{
		
		bool valid = true;
		if ((sku < 10000000 || sku > 99999999) || price < 0 || tname == nullptr || age < 1)
		{
			valid = false;
		}
		
		if (valid)
		{
			strcpy(m_Tname, tname);
			this->m_sku = sku;
			this->m_price = price;
			this->m_age = age;
		}
		else
		{
			strcpy(this->m_Tname, "Invalid Toy");
			this->m_sku = -1;
			this->m_price = -1;
			this->m_age = -1;
		}
	}


	void Toys::display() const
	{
		if (!strcmp(m_Tname, "Invalid Toy"))
		{
			cout << m_Tname << endl;
		}
		else
		{
			cout.fill(' ');
			cout.width(15);
			cout << left<< m_Tname;
			cout.width(10);
			cout << right<< m_sku;
			cout.width(6);
			cout << m_age;
			cout.width(12);
			cout.precision(2);
			cout << fixed << m_price;
			
			if (m_onSale) 
			{
				
				cout << "   ";
				cout << left<< "On Sale ";
			}
			else
			{
				cout << "        ";
			}

			cout << "\n";
		}

	}

	void Toys::isSale(bool sale)
	{
		m_onSale = sale;
		if (sale)
		{
			calSale();
		}
	}

	void Toys::calSale()
	{
		double discount = m_price * .2;
		m_price -= discount;
	}

}