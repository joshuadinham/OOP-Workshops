#define _CRT_SECURE_NO_WARNINGS
/*
Joshua Dinham
121572226
BTP200NAA
Friday February 10 2022
All Work completed by me
*/
#include "Tournament.h"
#include <iostream>
#include <cstring>
namespace sdds
{
	Tournament::Tournament()
	{
		this->setEmpty();
	}

	Tournament::Tournament(const char* name, int noOfTTeam, const SoccerTeam* soccer)
	{
		this->setTournament(name, noOfTTeam, soccer);
	}

	Tournament::~Tournament()
	{
		delete[] m_name;
		delete[] m_soccer;
	}

	void Tournament::setEmpty()
	{
		m_name = nullptr;
		m_num = 0;
		m_soccer = nullptr;
	}

	bool Tournament::isEmpty() const
	{
		bool valid = false;
		valid = m_name != nullptr && m_num > 0 && m_soccer != nullptr;
		return valid;
	}


	void Tournament::setTournament(const char* name, int noOfTeam, const SoccerTeam* soccer)
	{
		bool valid = true;
		valid = name != nullptr && noOfTeam > 0 && soccer != nullptr;
		if (valid)
		{
			valid = strcmp(name, " ") != 0 && strcmp(name, "\0");
		}
		
		if (valid)
		{
			m_name = new char[TOURNAMENT_NAME + 1];
			strcpy(m_name, name);
			m_soccer = new SoccerTeam[noOfTeam];
			m_num = noOfTeam;
			for (int i = 0; i < noOfTeam; ++i)
			{
				m_soccer[i] = soccer[i];
			}
		}
		else
		{
			*this = Tournament();
		}
	}

	Tournament& Tournament::match(const SoccerTeam* ls)
	{
		for (int i = 0; i < 1; i++) {
			if (m_soccer[i].fouls() < m_soccer[i + 1].fouls()) {
				m_soccer[i + 1].doubleFouls();
				m_soccer[i + 1].calFines();
				m_soccer[i].incrementGoals();
				if (m_soccer[i + 1].fouls() > MAX_FOUL) {
					m_soccer[i + 1].setFoul(-1);
				}
			}
		}
		return *this;
	}

	ostream& Tournament::display() const
	{
		if (this->isEmpty())
		{
			cout << "Tournament name: " << m_name << "\n" << "list of the teams\n";
			cout.fill(' ');
			cout.width(45);
			cout << "Fines";
			cout.width(10);
			cout << "Fouls";
			cout.width(11);
			cout << "Goals\n";
			for (int i = 0; i < m_num; ++i)
			{
				cout << "Team[" << i + 1 << "] :"; m_soccer[i].display();
			}
			
		}
		else
		{
			cout << "Invalid Tournament";
		}
		return cout;
	}

}