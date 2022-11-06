export module FreePlay;
import Gameplay;
import Date;
import UserInteractionHelper; //WordsDatabase, ListOfUsers from Gameplay
import <sstream>;
import <memory>;
import <thread>; //vector, iostream from Gameplay

/**
* Class responsible for Free Play gamemode.
*/
export class FreePlay : public Gameplay
{
private:
	std::vector<std::string> used_words; /**< Vector of words previously used in one round.*/

	/**
	* Method displays starting screen.
	*/
	void DisplayStartingScreen();

	/**
	* Method asks player if they wany to continue guessing words.
	* @return true if player chooses to continue, flase if player chooses to stop guessing
	*/
	bool Continue();

	/**
	* Method chcecks if the drawn word was already recently guessed by player in current round.
	* @return true if word was repeated, false if word wasn't repeated
	*/
	bool CheckIfWordAgain();

public:
	/**
	* Non-parameter FreePlay class constructor.
	*/
	FreePlay();
	
	/**
	* Method runs Free Play gamemode.
	* @param database parameter representing WordsDatabase object
	* @param list_of_users parameter representing list of users
	*/
	void Game(WordsDatabase& database, ListOfUsers& list_of_users);
};