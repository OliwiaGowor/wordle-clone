export module UserInteractionHelper;
import <iostream>;
import <regex>;

/**
* Class responsible for managing application interactions with user.
*/
export class UserInteractionHelper
{
public:
	/**
	* Static method checks if data given by user is a intiger.
	* @return intiger given by user
	*/
	static int CheckIfInt();

	/**
	* Static method checks if username given by user is correct.
	* @return true if username is correct, false if username isn't correct
	*/
	static bool CheckIfCorrectUsername(std::string username);

	/**
	* Static method checks if password given by user is correct.
	* @return true if password is correct, false if password isn't correct
	*/
	static bool CheckIfCorrectPassword(std::string password);
};
