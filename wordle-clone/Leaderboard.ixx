export module Leaderboard;
import ListOfUsers;

export class Leaderboard
{

public:
	static void LeaderboardByDaily(ListOfUsers& list_of_users);
	static void LeaderboardByFree(ListOfUsers& list);
	static void LeaderboardByDailyWins(ListOfUsers& list);
};