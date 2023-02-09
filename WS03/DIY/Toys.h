#pragma once
#ifndef TOYS_H
#define TOYS_H
#define MAX_TNAME 31
/*
File: Toys.h
Joshua Dinham
121572226
Feb 8 2023
BTP200 NAA
*/
namespace sdds {

	class Toys
	{
		char m_Tname[MAX_TNAME];
		int m_sku;
		double m_price;
		int m_age;
		bool m_onSale = false;

	public:
	
		//retrieves the sku for current toy
		int getSKU();
		
		//if Valid, This method will set the received values to the appropriate data members, else set to empty state
		void addToys(const char* tname, int sku, double price, int age);

		//Assigns bool value to Toys m_onSale value;
		void isSale(bool Sale);

		//decreases the toys price by 20%
		void calSale();

		//displays the toys information
		void display() const;
	};



}
#endif // !TOYS_H
