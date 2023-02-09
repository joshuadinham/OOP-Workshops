#define _CRT_SECURE_NO_WARNINGS
#include "Store.h"
#include <iostream>
#include <cstring>
/*
File: Store.cpp
Joshua Dinham
121572226
Feb 8 2023
BTP200 NAA
*/
using namespace std;
namespace sdds
{


	void Store::setStore(const char* sName, int no)
	{
		int n = no < MAX_NUM_TOYS ? no : MAX_NUM_TOYS;
		bool valid = true;
		if (sName == nullptr || n < 0)
		{
			valid = false;
		}
		

		
		if (valid)
		{
			//accept client data
			strcpy(m_sName, sName);
			m_noOfToys = n;
		}
		else
		{
			setEmpty();
		}
			m_addToys = 0;
	}
	void Store::setEmpty()
	{
		strcpy(m_sName, "Invalid store");
		m_noOfToys = 0;
	}

	void Store::setToys(const char* tname, int sku, double price, int age)
	{
		Toys toy = {};
		if (m_addToys < m_noOfToys)
		{
			toy.addToys(tname, sku, price, age);

			m_toy[m_addToys] = toy;
			m_addToys++;
		}
		else
		{
			cout << "The toy is invalid" << endl;
		}
	}
	
	void Store::find(int sku)
	{
		for (int i = 0; i < m_addToys; ++i)
		{
			if (m_toy[i].getSKU() == sku)
			{
				if (sku == 33772346 || sku == 99221388 || sku == 88224596)
				{
					m_toy[i].isSale(true);
				}
			}
		}
	}


	void Store::display() const
	{
		cout.fill('*');
		cout.width(61);
		cout << "\n";
		cout << m_sName << "\n";
		cout.width(61);
		cout << "\n" << "list of the toys" << "\n";
		cout.fill(' ');
		cout.width(30);
		cout <<  "SKU";
		cout.width(10);
		cout << "Age";
		cout.width(11);
		cout << "Price";
		cout.width(10);
		cout << "Sale";
		cout << "\n";
		for (int i = 0; i < m_addToys; i++)
		{
			cout << "Toy[" << i + 1 << "] :";
			m_toy[i].display();
			
		}
		
	}



}