export module UserInteractionHelper;
import <iostream>;
import <regex>;

export class UserInteractionHelper
{

public:
	static int CheckIfInt();
	static bool CheckIfCorrectUsername(std::string username);
	static bool CheckIfCorrectPassword(std::string password);
};
