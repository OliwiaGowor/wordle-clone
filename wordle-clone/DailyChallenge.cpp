module;
#include "date.h"
module DailyChallenge;

DailyChallenge::DailyChallenge()
{

}

bool DailyChallenge::CheckIfFirstTime(std::shared_ptr<User> ptr)
{
	using namespace date;
	using namespace std::chrono;
	User* t = ptr.get();
	Date tmp_date = t->GetDate();
	auto today = date::year_month_day{ floor<days>(system_clock::now()) };
	unsigned int d = tmp_date.GetDay();
	unsigned int m = tmp_date.GetMonth();
	int y = tmp_date.GetYear();
	auto player_date = date::year_month_day{ date::year{y} , date::month{m} , date::day{d} };
	if (today == player_date)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DailyChallenge::DisplayStartingScreen()
{
	std::cout << "WORDLE" << std::endl;
	std::cout << "Your daily challenge" << std::endl;
	std::cout << "An existing letter in the right spot will appear as itself. An existing letter in the wrong spot will appear as \'-\'. A non existing letter will appear as \'*\'" << std::endl;
}

void DailyChallenge::Game(WordsDatabase& database, ListOfUsers& list_of_users)
{
	auto curr = list_of_users.GetCurrentUser();
	SetWord(database);
	if (!CheckIfFirstTime(curr))
	{
		DisplayStartingScreen();
		if (Logic(database))
		{
			std::cout << "Congratulations, you completed your daily challenge!" << std::endl << std::endl;
			curr.get()->IncreaseDailyWins();
		}
		else
		{
			std::cout << "You lost, better luck tommorow!" << std::endl << std::endl;
			std::cout << "The word was :" << word << std::endl;
		}
	}
	else
	{
		std::cout << "You already played today! Come back tommorow." << std::endl;
	}

}

