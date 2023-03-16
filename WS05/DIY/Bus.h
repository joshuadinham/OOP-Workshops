#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#ifndef SDDS_BUS_H
/*
Joshua Dinham
121572226
BTP200NAA
Feb 23, 2023
All work is done by me
*/
namespace sdds
{
	const double busTicket = 125.34;
	
	class Bus
	{
		int m_numOfSeats;
		int m_numOfPsngrs;
		void drawBus(int seats, int noOfPassengers, std::ostream & = std::cout) const;

	public:
		Bus(int = 20, int = 0);
		operator bool() const;
		operator int() const;
		operator double() const;
		void setBroken();
		std::istream& read(std::istream& in); //practice
		std::ostream& display(std::ostream& out) const; //practice
		bool operator--();
		bool operator++();
		bool operator++(int);
		bool operator--(int);
		Bus& operator=(int);
		Bus& operator+=(int);
		Bus& operator+=(Bus&);
		bool operator==(const Bus&) const;

	};
	int operator+(int, const Bus&);
	std::ostream& displayBroken(std::ostream& = std::cout);
	std::istream& operator>>(std::istream&, Bus&);
	std::ostream& operator<<(std::ostream&, const Bus&);
}
#endif // !SDDS_BUS_H