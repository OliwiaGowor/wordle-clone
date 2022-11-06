export module ListOfUsers;
import User;
import <iostream>;
import <fstream>;
import <sstream>;
import <memory>;
import <ranges>;
import <algorithm>;
import <vector>;
import UserInteractionHelper;

/**
* Structure representing element in the list of users.
*/
export struct ListOfUsersElement
{
    std::unique_ptr<ListOfUsersElement> pNext;      /**< Value representing pointer to the next element in the list */
    std::shared_ptr<User> pUser;                    /**< Value representing pointer to the user in the list */
};

/**
* Class representing list of users.
*/
export class ListOfUsers
{
    std::shared_ptr<ListOfUsersElement> pHead;      /**< Value representing pointer to the first element in the list */
    std::shared_ptr<User> current_user;             /**< Value representing current user logged into the game */
    size_t size;                                    /**< Value representing size of the list */

public:
    /**
     * Method returns pHead class parameter.
     * @return parameter representing pointer to the first element in the list
     */
    std::shared_ptr<ListOfUsersElement> GetpHead();

    /**
    * Method sets current_user class parameter.
    * @param username parameter representing current user's username
    */
    void SetCurrentUser(std::string username)

    /**
    * Method returns current_user class parameter.
    * @return parameter representing current user logged into the game
    */
    std::shared_ptr<User> GetCurrentUser();

    /**
    * Method returns size class parameter.
    * @return parameter representing size of the list
    */
    size_t GetSize();

    /**
    * Method allows user to create new account.
    */
    void CreateUser();

    /**
    * Method adds new user to the list.
    * @param username parameter representing user's username
	* @param password parameter representing user's password
	* @param streak_free parameter representing user's streak record in FreePlay gamemode
	* @param wins_daily parameter representing number of times that player won Daily Challenge
	* @param loses_daily paramtere representing number of times that player lost Daily Challenge
	* @param tmpdate parameter representing date of user's last played Daily Challenge
    */
    void AddUser(std::string username, std::string password, int streak_free, int wins_daily, int loses_daily, Date tmpdate);

    /**
    * Method checks if user already exists.
    * @param username parameter representing username to check
    * @return true if user already exists, false if user doesn't exist
    */
    bool CheckIfUserExists(std::string username);

    /**
    * Method checks if password provided by user is correct.
    * @param password parameter representing password to check
    * @return true if password is correct, false password isn't correct
    */
    bool CheckIfRightPassword(std::string password);

    /**
    * Method reads user data form a text file.
    * @param line parameter represents line in a text file to read user date from
    * @param fileName name of the file that contains user data
    */
    void ReadUserFromFile(std::string& line, std::string fileName);

    /**
    * Method allows user to delete account.
    */
    void DeleteUser();

    /**
    * Method sorts list of users by the longest streak in FreePlay.
    * @return sorted vector of pointers to the users
    */
    std::vector<User*> SortByFree();

    /**
    * Method sorts list of users by the most wins in Daily Challenge.
    * @return sorted vector of pointers to the users
    */
    std::vector<User*> SortByDailyWins();

    /**
    * ListOfUsers class destructor.
    */
    ~ListOfUsers();
};
