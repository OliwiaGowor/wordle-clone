export module WordsDatabase;
import <iostream>;
import <random>;
import <chrono>;
import <vector>;

/**
* Class responsible for managing words database.
*/
export class WordsDatabase
{
	std::default_random_engine randomEngine; /**< Random number engine */
	std::vector<std::string> words; /**< Vector of words in database */

public:
	/**
	* Non-parameter WordsDatabase constructor.
	*/
	WordsDatabase();

	/**
	* Method returns vector of words, that are in the database.
	* @return vector of words, that are in the database
	*/
	std::vector<std::string> GetDatabase();

	/**
	* Method returns pointer to a vector of words, that are in the database.
	* @return pointer to a vector of words
	*/
	std::vector<std::string>* GetAdressDatabase();

	/**
	* Method draws random word from a database.
	* @return drawn word
	*/
	std::string GetWord();

	/**
	* Method checks if word given by user is valid and is in the database.
	* @return true if word is valid, false if word isn't valid
	*/
	bool IsValidWord(std::string to_check);
};