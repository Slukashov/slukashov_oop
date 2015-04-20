#ifndef _MATCH_HPP_
#define _MATCH_HPP_
#include "FootballClub.h"

class Match
{
	private:
	FootballClub m_home;
	FootballClub m_visitors;
	public:
		Match::Match();
		Match(FootballClub _home,FootballClub _visitors);
		inline char* getClubNameHome()const {return m_home.GetClubName();};//getting club Name Home
		inline char* getClubNameVistors()const {return m_visitors.GetClubName();};//getting club Name Visitors
		char* ManualMatchResult(char* _result)const;
		char* AutomaticMatchResult()const;
};
std::ostream& operator <<(std::ostream& o,Match& m );


#endif