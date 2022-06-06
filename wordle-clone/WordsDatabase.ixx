export module WordsDatabase;
import <iostream>;
import <random>;
import <chrono>;
import <vector>;

export class WordsDatabase
{
	std::default_random_engine randomEngine;
	std::vector<std::string> words;
public:
	WordsDatabase();
	std::vector<std::string> GetDatabase();
	std::vector<std::string>* GetAdressDatabase();
	std::string GetWord();
	bool IsValidWord(std::string to_check);
};