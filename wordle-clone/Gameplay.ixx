export module Gameplay;
export import ListOfUsers;
export import WordsDatabase;
export import <iostream>;
import <vector>;
import <random>;
import <ranges>;
import <regex>;
import <algorithm>;
import <thread>;

export class Gameplay
{
protected:
	std::string word;

public:
	Gameplay() = default;
	void SetWord(WordsDatabase& database);
	std::string GetWord();
	bool CheckIfRightWord(std::string usr_word, std::vector<std::string> words);
	//std::string GridManagement(std::string usr_word);
	std::string ParallelGridManagement(std::string usr_word);
	bool Logic(WordsDatabase& database);
	virtual void DisplayStartingScreen() = 0;
	virtual void Game(WordsDatabase& wordsDatabase, ListOfUsers& list_of_users) = 0;
};