#ifndef _TOURNAMENTTABLE_HPP_
#define _TOURNAMENTTABLE_HPP_

#include"FootballClub.h"
#include<iostream>


class TournamentTable
{
	private:
		FootballClub m_club;
		int m_winMatches;
		int m_drawMatches;
		int m_loseMatches;
		int m_scored;
		int m_missed;
	public:
		TournamentTable();
		TournamentTable(FootballClub _club);
		bool TournamentTable::operator<( const TournamentTable &_m)const;

		bool TournamentTable::operator>( const TournamentTable &_m)const;

		inline FootballClub getClub()const {return m_club;};//getting club Name

		inline char* getClubName()const {return m_club.GetClubName();};//getting club Name
		
		 int getPoints() const { return m_drawMatches + m_winMatches*3; };//get Points of Club
		
		inline int GetScored()const { return m_scored; };//getting scored goals
		
		inline int GetMissed()const { return m_missed; };//getting missing goals
		
		inline int WinMatch() { return m_winMatches++; };//increment win matches
		
		inline int DrawMatch() { return m_drawMatches++; };//incement draw matches
		
		inline int LoseMatch() { return m_loseMatches++; };//increment lose matches
		
		inline int GetWinMatch()const { return m_winMatches; };//getting win matches
		
		inline int GetDrawMatch()const { return m_drawMatches; };//getting draw matches
		
		inline int GetLoseMatch()const { return m_loseMatches; };//getting lose matches
	
	    inline int Difference()const {return m_scored - m_missed;};//getting difference of goals

		inline int GetCountPlayedMatches()const { return m_drawMatches+m_loseMatches+m_winMatches; };//getting count of palaying mathces

		void sortTable(TournamentTable * _t,int  _size);//sorting our Tournament Table

		void UpdateTable(TournamentTable &_t);//update  on club
};


//std::ostream& operator<< (std::ostream& o ,TournamentTable& t);

#endif