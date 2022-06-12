export module FreePlay;
import Gameplay;
import ListOfUsers;
import WordsDatabase;
import Date;
import UserInteractionHelper;
import <iostream>;
import <sstream>;
import <memory>;
import <vector>;
import <thread>;

export class FreePlay : public Gameplay
{
	std::vector<std::string> used_words;

public:
	FreePlay();
	void DisplayStartingScreen();
	void Game(WordsDatabase& database, ListOfUsers& list_of_users);
	//void SetWords(WordsDatabase& database);
	bool Continue();
	bool CheckIfWordAgain();

};