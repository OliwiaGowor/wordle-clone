//#include "date.h"
export module DailyChallenge;
import Gameplay;
import ListOfUsers;
import WordsDatabase;
import Date;
import <iostream>;
import <sstream>;
import <memory>;
import <chrono>;

export class DailyChallenge : public Gameplay
{
public:
	DailyChallenge();
	bool CheckIfFirstTime(std::shared_ptr<User> ptr);
	void DisplayStartingScreen();
	void Game(WordsDatabase& database, ListOfUsers& list_of_users);
};