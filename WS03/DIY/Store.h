#pragma once
#ifndef STORE_H
#define STORE_H
#define MAX_NUM_TOYS 10
#define MAX_SNAME 31
#include "Toys.h"
/*
File: Store.h
Joshua Dinham
121572226
Feb 8 2023
BTP200 NAA
*/
namespace sdds
{
	class Store
	{
		char m_sName[MAX_SNAME + 1]{};
		int m_addToys;
		int m_noOfToys;
		Toys m_toy[MAX_NUM_TOYS + 1]{};
	public:

		//sets the store name and the number of toys to be added.
		void setStore(const char* sName, int no);

		//adds toys one at a time to the m_Toys array and will icnrementt number of toys added each time
		void setToys(const char* tname, int sku, double price, int age);

		//displays the store information
		void display() const;

		//If store is invalid - sets store to an empty state
		void setEmpty();

		//iterates through list of torys and finds the toy with given SKU
		void find(int sku);

	};
}
#endif // !STORE_H


