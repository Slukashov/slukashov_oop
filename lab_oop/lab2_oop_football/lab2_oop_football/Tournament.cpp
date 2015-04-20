#include"Tournament.h"
#include<iostream>
#include<string>

bool ValidQuantity(int _QuantityClubs)
{
	return _QuantityClubs&1;
}

Tournament::Tournament()
{
	m_TournamentName = " ";
	m_QuantityClubs = m_rateClubs = 0;
}

Tournament::~Tournament()
{
  delete [] m_matches;
  delete [] m_tornamentTable;
	
}

Tournament::Tournament(char* _TournamentName,int _QuantityClubs,int _rateClubs,TournamentTable *_tornamentTable)
{
	m_TournamentName = _TournamentName;
	if(! ValidQuantity(_QuantityClubs))
	m_QuantityClubs = _QuantityClubs;
	else throw "wrong Quantity Clubs";
	m_rateClubs = _rateClubs;
	m_tornamentTable = new TournamentTable[m_QuantityClubs];
	for (int i = 0 ;i<m_QuantityClubs;i++)
		m_tornamentTable[i] = _tornamentTable[i];
	m_matches = new Match[m_QuantityClubs*(m_QuantityClubs-1)/2];

}
//generating schedule
void Tournament::scheduleOfMatches()
{	
	int x = 0;
	//First circle
	for (int i = 0; i < m_QuantityClubs / 2; i++)
	{	
		m_matches[x] = Match(m_tornamentTable[i].getClub(),m_tornamentTable[m_QuantityClubs - i - 1].getClub());
		x++;
	}
	for (int i = 1; i< m_QuantityClubs-1; i++)
	{
		TournamentTable team =m_tornamentTable[1];

			for (int j = 1; j< m_QuantityClubs; j++)
		{
			m_tornamentTable[j] = m_tornamentTable[j + 1];
		}
			m_tornamentTable[m_QuantityClubs-1] = team;

			for (int j = 0; j < m_QuantityClubs / 2; j++)
		{
				m_matches[x] = Match(m_tornamentTable[j].getClub(),m_tornamentTable[m_QuantityClubs - j - 1].getClub());
				x++;
		}
	}
	//back to deafault state
		TournamentTable team =m_tornamentTable[1];
			for (int j = 1; j< m_QuantityClubs; j++)
		{
			m_tornamentTable[j] = m_tornamentTable[j + 1];
		}
			m_tornamentTable[m_QuantityClubs-1] = team;

//Second circle

	for (int i = 0; i < m_QuantityClubs / 2; i++)
	{
		m_matches[x] = Match(m_tornamentTable[m_QuantityClubs - i - 1].getClub(),m_tornamentTable[i].getClub());
		x++;
	}  
	for (int i = 1; i< m_QuantityClubs-1; i++)
	{
		TournamentTable team =m_tornamentTable[1];
			for (int j = 1; j< m_QuantityClubs; j++)
		{
			m_tornamentTable[j] = m_tornamentTable[j + 1];
		}
			m_tornamentTable[m_QuantityClubs-1] = team;
			for (int j = 0; j < m_QuantityClubs / 2; j++)
		{
				m_matches[x] = Match(m_tornamentTable[m_QuantityClubs-j-1].getClub(),m_tornamentTable[j].getClub());
				x++;
		}
	}
	for (int i =0 ; i <x;i ++)
	std::cout<<m_matches[i]<<std::endl;

}

void Tournament::generateAllMatch()
{
	 char* x = " ";
	for (int i = 0;i<m_QuantityClubs*(m_QuantityClubs-1);i++)
	{
		x = m_matches[i].AutomaticMatchResult();
		std::cout << m_matches[i].getClubNameHome()<<" " << x << " "<< m_matches[i].getClubNameVistors()<<std::endl;
	}
}