export module FileManagement;
import <iostream>;
import <vector>;
import <fstream>;
import <sstream>;
import <filesystem>;
import <chrono>;
import WordsDatabase;
//import DailyChallenge;
import ListOfUsers;

namespace fs = std::filesystem;

export class FileManagement
{
	fs::path filesPath;

public:
	FileManagement();
	FileManagement(fs::path path);
	void LoadUsers(ListOfUsers& list);
	void SaveUsers(std::shared_ptr<ListOfUsersElement> list);
	void LoadDatabase(WordsDatabase& wordsDatabase);
	void SaveDailyWord(std::string word);
	bool SearchUsedWords(std::string word);
	Date ReadDailyDateFromFile();
	//dodac sprawdzanie czy istnieje sciezka
};