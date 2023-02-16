#define _CRT_SECURE_NO_WARNINGS
#include "Soccer.h"
#include<cstring>
/*
Joshua Dinham
121572226
BTP200NAA
Friday February 10 2022
All Work completed by me
*/
namespace sdds
{
	SoccerTeam::SoccerTeam()
	{
		this->setEmpty();
	}


	void SoccerTeam::setEmpty()
	{
		strcpy(this->m_TeamName, "\0");
		m_noFouls = -1;
		m_fines = -1;
		m_goals = 0;
	}
	void SoccerTeam::setTeam(const SoccerTeam& team)
	{
		this->setName(team.m_TeamName);
		this->setFine(team.m_fines, team.m_noFouls);
		m_goals = team.goals();

	}

	void SoccerTeam::setName(const char* tname)
	{
		strcpy(m_TeamName, tname);
	}

	void SoccerTeam::setFine(double fines, int foul)
	{
			m_fines = fines;
			m_noFouls = foul;
	}
	bool SoccerTeam::isEmpty() const
	{
		bool valid = true;
		valid = m_TeamName != nullptr;

		valid = strcmp(m_TeamName, "\0") != 0 && strcmp(m_TeamName, " ") != 0 && m_fines >= 0 && m_noFouls >= 0;

		
		return valid;
	}

	SoccerTeam::SoccerTeam(const char* tname, double fines, int fouls)
	{
		bool valid = tname != nullptr && fines >= 0 && fouls >= 0;
		if (valid)
		{
			valid = strcmp(tname, "\0") != 0 && strcmp(tname, " ") != 0;
		}

		if (valid)
		{
			this->setEmpty();
			this->setName(tname);
			this->setFine(fines, fouls);
		}
		else
		{
			this->setEmpty();
		}
		
	}
	//returns the number of fouls
	int SoccerTeam::fouls() const
	{
		
		return m_noFouls;
	}

	void SoccerTeam::setFoul(int value)
	{
		m_noFouls = value;
	}

	void SoccerTeam::doubleFouls()
	{
		m_noFouls *= 2;
	}

	double SoccerTeam::fines() const
	{
		return m_fines;
	}

	const char* SoccerTeam::teamName() const
	{
		return m_TeamName;
	}

	void SoccerTeam::incrementGoals()
	{
		m_goals++;
	}

	int SoccerTeam::goals() const
	{
		return m_goals;
	}


	ostream& operator<<(ostream& out, SoccerTeam& team)
	{
		if(team.isEmpty())
		{
			out.setf(ios::fixed);
			out.setf(ios::left);
			out.precision(2);
			out.fill(' ');
			out.width(30);
			out << team.teamName();
			out.width(6);
			out << team.fines();
			out.width(6);
			out << team.fouls();
			out.width(10);
			if (team.goals() > 10)
			{
				out << team.goals() << "w\n";
			}
			else {
				out << team.goals() << "\n";
			}
		}
		else
		{
			out << "Invalid Team\n";
		}
		return out;
		
	}

	void SoccerTeam::calFines()
	{
		double increase = m_fines * 0.2;
		m_fines += increase;
	}

	//if the team object is valid, prints formatted SoccerTeam data member information
	ostream& SoccerTeam::display() const
	{
		if (this->isEmpty())
		{
			cout.setf(ios::left);
			cout.fill(' ');
			cout.width(29);
			cout << m_TeamName;
			cout.unsetf(ios::left);
			cout.width(7);
			cout.precision(2);
			cout << fixed <<m_fines;
			cout.width(6);
			cout << m_noFouls;
			cout.width(10);
			if (m_goals > 0)
			{
				cout << m_goals << "w\n";
			}
			else {
				cout << m_goals << " \n";
			}
		}
		else
		{
			cout << "Invalid Team";
		}
		
		return cout;
	}
}