export module Leaderboard;
import ListOfUsers;

export class Leaderboard
{

public:
	static void LeaderboardByFree(ListOfUsers& list);
	static void LeaderboardByDailyWins(ListOfUsers& list);
};