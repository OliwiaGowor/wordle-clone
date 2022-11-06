export module User;
import <iostream>;
import Date;
import UserInteractionHelper;

/**
* Class responsible for User data.
*/
export class User
{
	std::string username,	/**< Value representing user's username */
		password;			/**< Value representing user's password */
	int streak_free,		/**< Value representing user's streak record in FreePlay gamemode */
		wins_daily,			/**< Value representing number of times that player won Daily Challenge */
		loses_daily;		/**< Value representing number of times that player lost Daily Challenge */
	Date last_played;		/**< Value representing date of user's last played Daily Challenge */

public:
	/**
	* Non-parameter User class constructor.
	*/
	User();

	/**
	* User class constructor.
	* @param username parameter representing user's username
	* @param password parameter representing user's password
	* @param streak_free parameter representing user's streak record in FreePlay gamemode
	* @param wins_daily parameter representing number of times that player won Daily Challenge
	* @param loses_daily paramtere representing number of times that player lost Daily Challenge
	* @param last_played parameter representing date of user's last played Daily Challenge
	*/
	User(std::string username, std::string password, int streak_free, int wins_daily, int loses_daily, Date last_played);

	/**
	 * Method returns username class parameter.
	 * @return parameter representing user's username
	 */
	std::string GetUsername();

	/**
	* Method sets username class parameter.
	@param useraname parameter representing user's username
	*/
	void SetUsername(std::string username);

	/**
	 * Method returns password class parameter.
	 * @return parameter representing user's password
	 */
	std::string GetPassword();

	/**
	* Method sets password class parameter.
	@param password parameter representing user's password
	*/
	void SetPassword(std::string password);

	/**
	* Method allows user to change their password.
	*/
	void ChangePassword();

	/**
	* Method allows user to change their username.
	*/
	void ChangeUsername();

	/**
	 * Method returns last_played class parameter.
	 * @return parameter representing date of user's last played Daily Challenge
	 */
	Date GetDate();

	/**
	* Method sets last_played class parameter.
	@param date parameter representing date of user's last played Daily Challenge
	*/
	void SetDate(Date date);

	/**
	 * Method returns streak_free class parameter.
	 * @return parameter representing user's streak record in FreePlay gamemode
	 */
	int GetStreakFree();

	/**
	* Method sets streak_free class parameter.
	@param streak parameter representing user's streak record in FreePlay gamemode
	*/
	void SetStreakFree(int streak);

	/**
	 * Method returns wins_daily class parameter.
	 * @return parameter representing number of times that player won Daily Challenge
	 */
	int GetDailyWins();

	/**
	* Method increses player's daily winsby one
	*/
	void IncreaseDailyWins();

	/**
	* Method writes player's statistics on screen.
	*/
	void DisplayStatistics();

	/**
	* Method writes user data to a text file.
	* @param file parameter represtenting output stream object
	*/
	void WriteUserToFile(std::ostream& file);

	/**
	* User class destructor.
	*/
	~User() = default;
};