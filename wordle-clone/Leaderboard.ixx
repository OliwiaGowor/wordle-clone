export module Leaderboard;
import ListOfUsers;

/**
* Class representing leaderboard.
*/
export class Leaderboard
{
public:
	/**
	* Static method responsible for generating leaderboard based on Free Game results.
	* @param list parameter representing list of users
	*/
	static void LeaderboardByFree(ListOfUsers& list);

	/**
	* Static method responsible for generating leaderboard based on daily wins.
	* @param list parameter representing list of users
	*/
	static void LeaderboardByDailyWins(ListOfUsers& list);
};