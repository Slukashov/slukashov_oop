#ifndef _FOOTBALLCLUB_HPP_
#define _FOOTBALLCLUB_HPP_

class FootballClub
{
	private:
		char* m_clubName;
		char* m_clubCity;
		int m_year;
		int m_clubRating;
	public:
		FootballClub ();
		FootballClub(char* _clubName,char* _clubCity,int _year, int _rating);
		char* GetClubName()const;
		char* GetClubCity()const;
		int GetYear()const;
		int GetClubRating()const;
};

#endif