export module User;
import <iostream>;
import Date;
import UserInteractionHelper;

export class User
{
	std::string username,
		password;
	int streak_free,
		wins_daily,
		loses_daily;
	Date last_played;

public:
	User();
	User(std::string username, std::string password, int streak_free, int wins_daily, int loses_daily, Date last_played);
	std::string GetUsername();
	void SetUsername(std::string username);
	std::string GetPassword();
	void SetPassword(std::string password);
	void ChangePassword();
	void ChangeUsername();
	Date GetDate();
	void SetDate(Date date);
	int GetStreakFree();
	void SetStreakFree(int streak);
	int GetStreakDaily();
	void SetStreakDaily(int streak);
	int GetDailyWins();
	void IncreaseDailyWins();
	void DisplayStatistics();
	void WriteUserToFile(std::ostream& file);
	~User() = default;
};