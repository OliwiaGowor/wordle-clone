export module Gameplay;
export import ListOfUsers;
export import WordsDatabase;
export import <iostream>;
export import <vector>;
import <random>;
import <ranges>;
import <regex>;
import <algorithm>;
import <thread>;

/**
* Abstract class responsible for game's logic and gameplay.
*/
export class Gameplay
{
protected:
	std::string word;	/**< Value representing word drawn from database for player to guess. */

public:
	/**
	* Non-paramerer Gameplay class constructor.
	*/
	Gameplay() = default;

	/**
	* Method sets a word for a current round.
	* @param database parameter representing words database
	*/
	void SetWord(WordsDatabase& database);
	bool CheckIfRightWord(std::string usr_word, std::vector<std::string> words);
	std::string ParallelGridManagement(std::string usr_word);
	bool Logic(WordsDatabase& database);

	/**
	* Pure virtual method responsible for displaying starting screen.
	*/
	virtual void DisplayStartingScreen() = 0;
	
	/**
	* Pure virtual method responsible for running game's gameplay.
	*/
	virtual void Game(WordsDatabase& wordsDatabase, ListOfUsers& list_of_users) = 0;
};