#include<iostream>
#include <clocale>
#include "TournamentTable.h"
#include"Tournament.h"

std::ostream& operator <<(std::ostream& o, TournamentTable& t)
{
	o << t.getClubName() << "|"
		<< t.GetCountPlayedMatches() << "|"
		<< t.getPoints() << "|"
		<< t.GetWinMatch() << "|"
		<< t.GetDrawMatch() << "|"
		<< t.GetLoseMatch() << "|"
		<< t.GetScored() << "|"
		<< t.GetMissed() << "|"
		<< t.Difference() << "|"
		<< std::endl;
	return o;
}

int main()
{
	int _Quantity = 4;
	FootballClub _f[4];
	_f[0] = FootballClub("mu","manchester",1,1);
	_f[1] = FootballClub("real","madrid",1,5);
	_f[2] = FootballClub("barcelona","barcelona",1,1);
	_f[3] = FootballClub("chelsea","london",1,1);
	TournamentTable t[4];
	
	for(int i = 0 ; i < _Quantity;i++)
	t[i] = TournamentTable(_f[i]);
	for (int i = 0; i<_Quantity; i++)
		std::cout << t[i];
	Tournament _t("smth", _Quantity, 1, t);
	_t.scheduleOfMatches();
	_t.generateAllMatch();
	
	return 0;
}

