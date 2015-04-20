#include "FootballClub.h"

bool IsValid(int _year,int _rating)
{
	return ((_year!=0)&&(_rating>=1&&_rating<=5));
}

FootballClub::FootballClub(char* _clubName,char* _clubCity,int _year, int _rating)
{
	if (IsValid(_year,_rating))
	{	m_clubName = _clubName;
		m_clubCity = _clubCity;
		m_year = _year;
		m_clubRating = _rating;
	}
	else throw "Invalid data";
}

FootballClub::FootballClub()
{
	m_clubName = m_clubCity = "default";
	m_year = m_clubRating = 1;
}

char* FootballClub::GetClubName() const
{
	return m_clubName;
}

char* FootballClub::GetClubCity() const
{
	return m_clubCity;
}

int FootballClub::GetYear()const
{
	return m_year;
}

int FootballClub::GetClubRating()const
{
	return m_clubRating;
}