/*класс Tournament (футбольный турнир), включающий:
- название;
- фиксированное количество и набор клубов, участвующих в турнире;
- динамически растущая последовательность матчей;
- метод автоматического формирования расписания матчей (все клубы должны
сыграть друг против друга по 2 раза ­ на родном стадионе и в гостях)
- турнирная таблица ­ хранение и обновление в нужные моменты.
*/
#ifndef _TOURNAMENT_HPP_
#define _TOURNAMENT_HPP_
#include "TournamentTable.h"
#include"Match.h"

class Tournament
{
	private:
		char* m_TournamentName;
		int m_QuantityClubs;
		int m_rateClubs;
		TournamentTable *m_tornamentTable;
		Match * m_matches;
	public:
		Tournament();
		~Tournament();
		inline TournamentTable& getTournamentTable() const{ return *m_tornamentTable; }
		Tournament(char* _TournamentName,int _QuantityClubs,int _rateClubs,TournamentTable *_tornamentTable);
		void scheduleOfMatches();
		void generateAllMatch();
};

#endif