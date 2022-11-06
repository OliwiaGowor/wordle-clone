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

/**
* Class responsible for application menu.
*/
export class Menu
{
private:
	int choice;						/**< Value representing users choice. */
	FileManagement mainArgs;		/**< Value representing FileManagement object */
	DailyChallenge daily;			/**< Value representing DailyChallenge object */
	ListOfUsers list_of_users;		/**< Value representing list of users */
	WordsDatabase wordsDatabase;	/**< Value representing WordsDatabase object */
	FreePlay free_play;				/**< Value representing FreePlay object */

	/**
	* Method manages proccess of logging into the game by a player.
	* @return true if player logged in correctly, false if player didn't log in
	*/
	bool Login();

public:
	/**
	* Menu class constructor.
	* @param args
	*/
	Menu(FileManagement& args);

	/**
	* Method displays starting screen and allows user to log into game.
	* @return true if user properly logged in, false if user did not logged in
	*/
	bool StartingScreen();
	
	/**
	* Method is responsible for running the program.
	*/
	void RunProgram();

	/**
	* Method writes main menu on screen and is responsible for managing user's interaction with it. 
	*/
	void MainMenu();

	/**
	* Method writes settings menu on screen and is responsible for managing user's interaction with it.
	*/
	void SettingsMenu();

	/**
	* Method writes leaderboard menu on screen and is responsible for managing user's interaction with it.
	*/
	void MenuLeaderboard();

};
