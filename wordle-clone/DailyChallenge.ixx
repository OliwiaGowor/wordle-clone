export module DailyChallenge;
import Gameplay;
import FileManagement;
import Date;
import <sstream>;
import <memory>;
import <chrono>;
import <filesystem>; //iostream from Gameplay

/**
* Class responsible for Daily Challenge gamemode.
*/
export class DailyChallenge : public Gameplay
{
private:
	/**
	* Method responsible for checking if given date is the same as current date.
	* @param date date to check
	* @return true if dates are the same, false if dates are different
	*/
	bool CheckIfTodayDate(Date date);

	/**
	* Method displays starting screen.
	*/
	void DisplayStartingScreen();

	/**
	* Method checks if daily word was already set, if not sets new one.
	* @param database parameter representing WordsDatabase object
	*/
	void CheckIfWordWasUsed(WordsDatabase& database);

	/**
	* Method sets player's last played daily challenge date.
	* @param user parameter representing user who's date is being set
	*/
	void SetUsersTodayDate(std::shared_ptr<User> user);

public:
	/**
	* Non-parameter class constructor.
	*/
	DailyChallenge();

	/**
	* Method runs Daily Challenge gamemode.
	* @param database parameter representing WordsDatabase object
	* @param list_of_users parameter representing list of users
	*/
	void Game(WordsDatabase& database, ListOfUsers& list_of_users);
};