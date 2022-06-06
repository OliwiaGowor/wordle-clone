export module Menu;
import FileManagement;
import UserInteractionHelper;
import DailyChallenge;
import ListOfUsers;
import WordsDatabase;
import User;
import FreePlay;
import Leaderboard;
import <memory>;

export class Menu
{
	int choice;
	FileManagement mainArgs;
	DailyChallenge daily;
	ListOfUsers list_of_users;
	WordsDatabase wordsDatabase;
	FreePlay free_play;

public:
	Menu(FileManagement& args);
	bool StartingScreen();
	void Login();
	void RunProgram();
	void MainMenu();
	void SettingsMenu();
	void MenuLeaderboard();

};
