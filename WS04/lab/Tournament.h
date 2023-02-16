#pragma once
/*
Joshua Dinham
121572226
BTP200NAA
Friday February 10 2022
All Work completed by me
*/
#ifndef TOURNAMENT_H
#include "Soccer.h"
#define TOURNAMENT_NAME 41
using namespace std;
namespace sdds
{
	class Tournament
	{
		char* m_name; //dynamically allocated cString;
		int m_num; //size of the dynamically allocated array of SoccerTeam teams n>0;
		SoccerTeam* m_soccer = nullptr; //pointer to dynamiccally allocated array of soccer teams;

	public:
		//will validate arguments and assign values to the tournament instance
		void setTournament(const char* name, int noOfTeam, const SoccerTeam* soccer);

		//sets the tournament to an empty state
		void setEmpty();

		//returns true if the tournament name, amount of teams or the SoccerTeam team is null;
		bool isEmpty() const;

		//loops through the soccer teams and matches them together to determine a winner;
		Tournament& match(const SoccerTeam* ls);

		//prints the Tournament object
		ostream& display() const;

		Tournament();

		Tournament(const char* name, int noOfteam, const SoccerTeam* soccer);

		~Tournament();

	};
}
#endif // !TOURNAMENT_H

