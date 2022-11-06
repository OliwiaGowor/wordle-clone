export module FileManagement;
import <iostream>;
import <vector>;
import <fstream>;
import <sstream>;
import <filesystem>;
import <chrono>;
import WordsDatabase;
import ListOfUsers;

namespace fs = std::filesystem;
/**
* Class responsible for managing working with files.
*/
export class FileManagement
{
	fs::path filesPath; /**< Value representing path to necessary files.*/

public:
	/**
	* Non-parameter FileManagement class constructor.
	*/
	FileManagement();

	/**
	* FileManagement class constructor.
	* @param path file path
	*/
	FileManagement(fs::path path);

	/**
	* Method creates directory needed for storing program data.
	*/
	void CreateDir();

	/**
	* Method checks if directory needed for storing program data already exists.
	* @return true if directory exists, false if directory doesn't exist
	*/
	bool CheckIfDirExists();

	/**
	* Method loads user data from a text file to program.
	* @param list list of users
	*/
	void LoadUsers(ListOfUsers& list);

	/**
	* Method saves user data to a text file.
	* @param list pointer to a first element of listof users
	*/
	void SaveUsers(std::shared_ptr<ListOfUsersElement> list);

	/**
	* Method loads word database from a text file to program.
	* @param wordsDatabase parameter representing words database
	*/
	void LoadDatabase(WordsDatabase& wordsDatabase);

	/**
	* Martod saves drawn daily word to a text file.
	* @param word word to save to a file
	*/
	void SaveDailyWord(std::string word);

	/**
	* Method chcecks in text file with daily words, if drawn daily word was already used in game.
	* @param word word to check
	* @return true if word was used, false if word wasn't used
	*/
	bool SearchUsedWords(std::string word);

	/**
	* Method gets date when daily word was used from a text file.
	* @return date read from text file
	*/
	Date ReadDailyDateFromFile();

	/**
	* Method reads daily word from a text file.
	* @return read word as a string
	*/
	std::string ReadDailyWordFromFile();
};