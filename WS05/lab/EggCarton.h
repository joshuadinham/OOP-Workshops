#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#ifndef EGGCARTON_H

namespace sdds
{
	/*
	Joshua dinham
	121572226
	BTP200NAA
	Feb 16, 2023
	All work is completed by me;
*/
	const int regularEggWeight = 50;
	const int jumboEggWeight = 75;

	class EggCarton
	{
		int m_size;
		int m_noOfEggs;
		bool m_jumboSize;

	public:
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
		void setBroken();
		operator double() const;
		EggCarton& operator--();
		EggCarton& operator++();
		EggCarton operator++(int);
		EggCarton operator--(int);
		EggCarton& operator=(int value);
		bool operator==(const EggCarton& right) const;
		EggCarton& operator+=(EggCarton& right);
		EggCarton& operator+=(int value);
		operator int() const;
		operator bool() const;
		std::ostream& display(std::ostream& ostr = std::cout) const;
		std::ostream& display(int size, int noOfEggs, bool jumbo, std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& displayBroken(std::ostream& ostr);
	int operator+(int left, const EggCarton& right);
	std::istream& operator>>(std::istream& istr, EggCarton& right);
	std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
}
#endif // !EGGCARTON_H