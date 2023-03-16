/*
	Joshua dinham
	121572226
	BTP200NAA
	Feb 23, 2023
	All work is completed by me;
*/
#include "Bus.h"
namespace sdds
{

	Bus::operator bool() const
	{
		bool valid = true;
		valid = m_numOfSeats > 0 && 40 >= m_numOfSeats && m_numOfPsngrs <= m_numOfSeats && m_numOfPsngrs >= 0;
		return valid;
	}

	Bus::operator int() const
	{
		if (*this)
		{
			
			return m_numOfPsngrs;
		}
		else
		{
			return -1;
		}
	}


	void Bus::setBroken()
	{
		m_numOfSeats = 0;
		m_numOfPsngrs = 0;
	}

	Bus::operator double() const
	{
		if (this)
		{
			return busTicket * m_numOfPsngrs;
		}
		else
		{
			return -1.0;
		}
	}

	std::istream& Bus::read(std::istream& in)
	{

		in >> m_numOfSeats;
		in.ignore();
		in >> m_numOfPsngrs;
		in.ignore();
		in.clear();

		if (!*this)
		{
			setBroken();
		}

		return in;
	}

	Bus::Bus(int seats, int psngrs)
	{
		m_numOfSeats = seats;
		m_numOfPsngrs = psngrs;
		bool valid = true;
		valid = m_numOfPsngrs >= 0 && m_numOfSeats >= m_numOfPsngrs && m_numOfSeats >= 10 && 40 >= m_numOfSeats && m_numOfSeats % 2 == 0;
		if (!valid)
		{
			setBroken();
		}
	}

	std::istream& operator>>(std::istream& in, Bus& right)
	{
		right.read(in);
		return in;
	}

	std::ostream& operator<<(std::ostream& out, const Bus& right)
	{
		right.display(out);
		return out;
	}

	int operator+(int left, const Bus& right)
	{
		int sum = 0;
		if (right)
		{
			sum = left + int(right);
			return sum;
		}
		return int(left);
	}

	void Bus::drawBus(int seats, int noOfPassengers, std::ostream& out) const {
		int i, p;
		out.fill('_');
		out.width((seats / 2) * 3 + 4);
		out << "_";
		out << std::endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, out << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
		out << "|_\\_" << std::endl;
		out << "| ";
		out.fill(' ');
		out.width(((seats / 2) * 3 - 14) / 2);
		out << " " << "Seneca College";
		out.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		out << " " << "    )" << std::endl;
		out << "`---OO";
		out.fill('-');
		out.width((seats / 2) * 3 - 5);
		out << "-" << "O---'" << std::endl;
	}

	std::ostream& displayBroken(std::ostream& out)
	{
		out << "Out of service!" << std::endl;
		return out;
	}

	std::ostream& Bus::display(std::ostream& out) const
	{
		if (*this)
		{
			drawBus(this->m_numOfSeats, this->m_numOfPsngrs, out);
			out.precision(2);
			out << "Total Fare Price: " <<std::fixed<< double(*this) << std::endl;
		}
		else
		{
			displayBroken(out);
		}
		return out;
	}

	bool Bus::operator--()
	{
		bool valid = true;
		valid = m_numOfPsngrs > 0;
		if (*this && valid)
		{
			m_numOfPsngrs--;

		}
		return valid;
		
	}

	bool Bus::operator--(int)
	{
		
		bool valid = --(*this); 
		return valid;
	}
	bool Bus::operator++()
	{
		bool valid = true;
		valid = m_numOfPsngrs < m_numOfSeats;
		if (*this && valid)
		{
			m_numOfPsngrs++;

		}
		return valid;
	}


	bool Bus::operator++(int)
	{
		bool valid = ++(*this);
		return valid;
	}

	Bus& Bus::operator=(int value)
	{
		if (*this)
		{
			m_numOfPsngrs = value;

			if (!*this)
			{
				setBroken();
			}
		}
		return *this;
	}
	
	Bus& Bus::operator+=(int value)
	{
		if (*this)
		{
			m_numOfPsngrs += value;

			if (!*this)
			{
				setBroken();
			}
		}
		return *this;
	}
	Bus& Bus::operator+=(Bus& right)
	{
		if (*this && right)
		{
			int emptyL = 0; //amount of empty slots in the left object;
			emptyL = m_numOfSeats - m_numOfPsngrs; //set # of empty slots to be the max amount of seats - number of passengers
			if (emptyL == 0)
			{
				return *this; //if there are no empty slots return the object;
			}
			else
			{
				if (right.m_numOfPsngrs >= emptyL)
				{
					(*this) += emptyL;
					(right) += (emptyL * -1);
				}
				else if (right.m_numOfPsngrs < emptyL)
				{
					(*this) += right.m_numOfPsngrs;
					(right) += (right.m_numOfPsngrs * -1);
				}
				if (!*this)
				{
					setBroken();
				}
			}
		}
		return *this;
	}
	bool Bus::operator==(const Bus& right) const
	{
		bool valid = true;
		valid = bool(*this) && bool(right);
		if (valid)
		{
			valid = int(*this) == int(right);
		}
		return valid;
	}
}
