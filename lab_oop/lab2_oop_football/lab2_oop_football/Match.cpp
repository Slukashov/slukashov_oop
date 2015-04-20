#include<iostream>
#include <time.h>
#include"Match.h"


int RandomRes(int _rateHome,int _rateVisitors)
{
	int _buf = _rateHome*100+_rateVisitors*100+100;
	int _coef1 = rand()%_buf+1;
	if (_coef1 <= _rateHome*100)
		return 1;
	else 
		if (_coef1 > _buf-100)
			return 2;
		else
			return 3;
}
Match::Match()
{

}
Match::Match(FootballClub _home,FootballClub _visitors)
{
	m_home = _home;
	m_visitors = _visitors;
}
bool Valid(int _home,int _visitors)
{
	return (_home>=0&&_visitors>=0);
}
char* Match::ManualMatchResult(char* _result)const
{
	char sep1;
	int _home,_visitors;
	_home = _visitors = 0;
	int nMatched = sscanf_s(_result,"%d%c%d",&_home,&sep1,&_visitors);
	if(nMatched!=3 || sep1!=':')
		throw "Incorrect result format";
	if(!Valid(_home,_visitors))
		throw "Incorrect data";
		return _result;
}
char* Match::AutomaticMatchResult( )const
{
	int _homeGoal,_visitorsGoal;
	_homeGoal = _visitorsGoal = 0;
	 static char _result [80];
	if(RandomRes(m_home.GetClubRating(),m_visitors.GetClubRating())==1)
	{
		srand(time(NULL));
		_homeGoal = rand()%10+1;
		_visitorsGoal = rand()%_homeGoal;
	}
	else if (RandomRes(m_home.GetClubRating(), m_visitors.GetClubRating()) == 2)
	{
		srand(time(NULL));
		_homeGoal = rand() % 10 + 1;
	}
	else 
	{
		srand(time(NULL));
			_visitorsGoal = rand()%10+1;
			_homeGoal = rand()%_visitorsGoal;
	}
	sprintf(_result,"%d:%d",_homeGoal,_visitorsGoal);
	return _result;
}
std::ostream& operator <<(std::ostream& o,Match& m )
{
	o<<m.getClubNameHome()<<" - "<<m.getClubNameVistors()<<std::endl;
	return o;
}