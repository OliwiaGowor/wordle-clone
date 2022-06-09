module;
module User;

User::User()
{
}

User::User(std::string username, std::string password, int streak_free, int streak_daily, int wins_daily, int loses_daily, Date last_played)
{
	this->username = username;
	this->password = password;
	this->streak_free = streak_free;
	this->streak_daily = streak_daily;
	this->wins_daily = wins_daily;
	this->loses_daily = loses_daily;
	this->last_played = last_played;
}

std::string User::GetUsername()
{
	return username;
}

void User::SetUsername(std::string username)
{
	this->username = username;
}

std::string User::GetPassword()
{
	return password;
}

void User::SetPassword(std::string password)
{
	this->password = password;
}

void User::ChangePassword()
{
	std::string usr_password;
	std::cout << "Enter new password: ";
	std::cin >> usr_password;
	while (!UserInteractionHelper::CheckIfCorrectPassword(usr_password) || usr_password == this->password)
	{
		std::cout << "Wrong or the same password! Password must contain of minimum 8 characters, one big letter, one small letter, one number and one symbol." << std::endl;
		std::cout << "Enter new password: ";
		std::cin >> usr_password;
	}
	SetPassword(usr_password);
	std::cout << "Password changed succesfully!" << std::endl;
}

void User::ChangeUsername()
{
	std::string usr_username;
	std::cout << "Enter new username: ";
	std::cin >> usr_username;
	while (!UserInteractionHelper::CheckIfCorrectUsername(usr_username) || usr_username == this->username)
	{
		std::cout << "Wrong or the same username!" << std::endl;
		std::cout << "Enter new username: ";
		std::cin >> usr_username;
	}
	SetUsername(usr_username);
	std::cout << "Username changed succesfully!" << std::endl;
}

Date User::GetDate()
{
	return last_played;
}

void User::SetDate(Date date)
{
	this->last_played = date;
}

int User::GetStreakFree()
{
	return streak_free;
}

void User::SetStreakFree(int streak)
{
	this->streak_free = streak;
}

int User::GetStreakDaily()
{
	return streak_daily;
}

void User::SetStreakDaily(int streak)
{
	this->streak_daily = streak;
}

int User::GetDailyWins()
{
	return wins_daily;
}

void User::IncreaseDailyWins()
{
	this->wins_daily++;
}

void User::DisplayStatistics()
{
	std::cout << "User: " << username << std::endl;
	std::cout << "Your statistics: " << std::endl;
	std::cout << "Longest streak in free game: " << streak_free << std::endl;
	std::cout << "Longest streak in daily challenge: " << streak_daily << std::endl;
	std::cout << "Won daily challenges: " << wins_daily <<std::endl;
	std::cout << "Lost daily challenges: " << loses_daily << std::endl;

}


void User::WriteUserToFile(std::ostream& file)
{
	file << username << std::endl << password << std::endl << streak_free << std::endl << streak_daily << std::endl 
		<< wins_daily << std::endl << loses_daily << std::endl;
	last_played.WriteDateToFile(file);
}