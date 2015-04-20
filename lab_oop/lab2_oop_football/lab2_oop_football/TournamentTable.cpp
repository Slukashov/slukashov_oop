#include<iostream>
#include<algorithm>
#include"TournamentTable.h"



TournamentTable::TournamentTable()
{
	m_drawMatches = m_loseMatches = m_missed = m_scored = m_winMatches = 0;
}

TournamentTable::TournamentTable(FootballClub _club)
{
	m_club = _club;
	m_drawMatches = m_loseMatches = m_missed = m_scored = m_winMatches = 0;
}

bool TournamentTable::operator<( const TournamentTable &_m)const
{
	if(getPoints() < _m.getPoints())
		return true;
	else if(getPoints() ==_m.getPoints()&& Difference()<_m.Difference())	
		return true;
	else 
	{ int i  = strcmp(m_club.GetClubName(),_m.getClubName());
		if(Difference()==_m.Difference()&&i<0)
	{
		return true;
	}
	}
		return false;
}

bool TournamentTable::operator>(const TournamentTable &_m)const
{
	return _m < *this;
}

void TournamentTable::sortTable(TournamentTable* _t,int  _size)
{
	std::sort(_t, _t + _size);	
}

void TournamentTable::UpdateTable(TournamentTable & _t)
{

}

//std::ostream& operator <<(std::ostream& o,TournamentTable& t )
//{
//	   o<<t.getClubName()<<"|"
//		<<t.GetCountPlayedMatches()<<"|"
//		<<t.getPoints()<<"|"
//		<<t.GetWinMatch()<<"|"
//		<<t.GetDrawMatch()<<"|"
//		<<t.GetLoseMatch()<<"|"
//		<<t.GetScored()<<"|"
//		<<t.GetMissed()<<"|"
//		<<t.Difference()<<"|"
//		<<std::endl;
//	return o;
//}
