#include "EggCarton.h"
namespace sdds
{
	/*
	Joshua dinham
	121572226
	BTP200NAA
	Feb 16, 2023
	All work is completed by me;
*/
	EggCarton::EggCarton(int size , int noOfEggs, bool jumboSize)
	{
		m_size = size;
		m_noOfEggs = noOfEggs;
		m_jumboSize = jumboSize;
		if (!*this)
		{
			setBroken();
		}
	}
	void EggCarton::setBroken() {
			m_size = -1;
			m_noOfEggs = -1;
	}

	EggCarton::operator double() const
	{
		double weight;
		if (*this)
		{
			if (m_jumboSize == true)
			{
				weight = m_noOfEggs * jumboEggWeight / 1000.0;
			}
			else
			{
				weight = m_noOfEggs * regularEggWeight / 1000.0;
			}
			return weight;
		}
		else
		{
			return -1.0;
		}
	}
	EggCarton& EggCarton::operator--()
	{
		if (*this)
		{
			m_noOfEggs--;
		}
		if (!*this)
		{
			setBroken();
		}
		return *this;
	}

	EggCarton& EggCarton::operator++()
	{
		if (*this)
		{
			m_noOfEggs++;

			if (!*this)
			{
				setBroken();
			}
		}
		return *this;
	}

	EggCarton EggCarton::operator++(int)
	{
		EggCarton egg = *this; //save the original
		++(*this); //call the prefix operator;
		return egg; //return the original;
	}

	EggCarton EggCarton::operator--(int)
	{
		EggCarton egg = *this; //save the orginal
		--(*this); //call the prefix operator;
		return egg; //return the original;
	}
	EggCarton& EggCarton::operator=(int value)
	{
		if (*this)
		{
			m_noOfEggs = value;

			if (!*this)
			{
				setBroken();
			}
		}
		return *this;
	}

	bool EggCarton::operator==(const EggCarton& right) const
	{
		return double(*this) - double(right) == 0.0;
	}

	EggCarton& EggCarton::operator+=(EggCarton& right)
	{
		if (*this && right)
		{
			int emptyL = 0; //amount of empty slots in the right object;
			emptyL = m_size - m_noOfEggs; //set # of empty slots to be the max amount of eggs minus the amount of eggs
			if (emptyL == 0)
			{
				return *this; //if there are no empty slots return the object;
			}
			else
			{
				if (right.m_noOfEggs >= emptyL)
				{
					(*this) += emptyL;
					(right) += (emptyL * -1);
				}
				else if (right.m_noOfEggs < emptyL)
				{
					(*this) += right.m_noOfEggs;
					(right) += (right.m_noOfEggs * -1);
				}
				if (!*this)
				{
					setBroken();
				}
			}
		}
		return *this;
	}

	EggCarton& EggCarton::operator+=(int value)
	{
		if (*this)
		{
			m_noOfEggs += value;

			if (!*this)
			{
				setBroken();
			}
		}
		return *this;
	}

	EggCarton::operator int() const
	{
		if (*this)
		{
			return m_noOfEggs;
		}
		else
		{
			return -1;
		}
	}

	EggCarton::operator bool() const
	{
		bool valid = true;
		valid = m_size % 6 == 0 && m_size > 0 && m_size <= 36 && m_noOfEggs >= 0 && m_noOfEggs <= m_size;
		return valid;
	}

	std::ostream& displayBroken(std::ostream& ostr = std::cout)
	{
		ostr << "Broken Egg Carton!" << std::endl;
		return ostr;
	}

	

	std::ostream& EggCarton::display(std::ostream& ostr) const
	{
		if (*this)
		{
			display(this->m_size, this->m_noOfEggs, this->m_jumboSize, ostr);
		}
		else
		{
			displayBroken(ostr);
		}
		return ostr;
	}

	std::ostream& EggCarton::display(int size, int noOfEggs, bool jumbo, std::ostream& ostr) const
	{
		int cartonWidth = size == 6 ? 3 : 6;
		for (int i = 0; i < size; i++) {
			ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
			((i + 1) % cartonWidth == 0) && ostr << ']' << std::endl;
		}
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const EggCarton& right)
	{
		right.display(ostr);
		return ostr;
	}

	int operator+(int left, const EggCarton& right)
	{
		int sum = 0;
		if (right)
		{
			sum = left + int(right);
			return sum;
		}
		return int(left);
	}

	std::istream& EggCarton::read(std::istream& istr)
	{
		char jumbo;
		char j = 'j';// character to hold the jumbo
		istr.get(jumbo); //gets the first character until a comma
		istr.ignore(); // ignores the next character
		if(jumbo == j)
		{
			m_jumboSize = true;

		}
		else
		{
			m_jumboSize = false;
		}

		istr >> m_size; //gets the first number until comma;
		istr.ignore(); //ignores next character
		istr >> m_noOfEggs;
		istr.ignore();
		istr.clear();

		if (!*this)
		{
			setBroken();
		}

		return istr;
	}

	std::istream& operator>>(std::istream& istr, EggCarton& right)
	{
		right.read(istr);
		return istr;
	}
}



