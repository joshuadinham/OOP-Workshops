#pragma once
/*
Joshua Dinham
121572226
BTP200NAA
Friday February 10 2022
All Work completed by me
*/
#ifndef SOCCER_H
#include <iostream>

#define MAX_SNAME 41 //max characters of the Soccer name
#define MAX_FOUL 4 //max num of fouls allowed
using namespace std;
namespace sdds 
{
	class SoccerTeam
	{
		char m_TeamName[MAX_SNAME];
		int m_noFouls; // n >= 0;
		double m_fines; // n >= 0
		int m_goals; //n >= 0;

		//sets the team name, fine and fouls of the team
		void setTeam(const SoccerTeam& team);

	public:
		//uses setter function to set team name, fines and fouls if valid
		SoccerTeam(const char* tname, double fines, int fouls);

		//default constructer
		SoccerTeam();

		//receives the name and validates and copies name to the data member mTeamName
		void setName(const char* tname);

		//receives fines and fouls and sets the values of the appropriate data
		void setFine(double fines, int foul);

		//sets the SoccerTeam team to an empty state
		void setEmpty();

		//returns true if the SoccerTeam data members are valid
		bool isEmpty() const;

		//when called will increase the fine by 20%
		void calFines();

		//returns the number of fouls
		int fouls() const;

		void setFoul(int);

		void doubleFouls();

		double fines() const;

		int goals() const;

		const char* teamName() const;

		void incrementGoals();

		

		//if the team object is valid, prints formatted SoccerTeam data member information
		std::ostream& display() const;



	};
		//instructions for overloading the << operator... displays the formatted member information
		std::ostream& operator<<(std::ostream& out, SoccerTeam& team);

}
#endif // !Soccer_H

