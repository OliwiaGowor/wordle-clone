//#include "date.h"
export module DailyChallenge;
import Gameplay;
import FileManagement;
//import ListOfUsers;
//import WordsDatabase;
import Date;
//import <iostream>;
import <sstream>;
import <memory>;
import <chrono>;
import <filesystem>;

export class DailyChallenge : public Gameplay
{
public:
	DailyChallenge();
	bool CheckIfTodayDate(Date date);
	void DisplayStartingScreen();
	void Game(WordsDatabase& database, ListOfUsers& list_of_users);
	void SetDailyWord(WordsDatabase& database);
	void CheckIfWordWasUsed(WordsDatabase& database);
	void SetTodayDate(User* user);
};