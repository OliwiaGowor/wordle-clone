module;
#include "date.h"
module DailyChallenge;
namespace fs = std::filesystem;

DailyChallenge::DailyChallenge()
{

}

bool DailyChallenge::CheckIfTodayDate(Date date)
{
	using namespace date;
	using namespace std::chrono;
	auto today = date::year_month_day{ floor<days>(system_clock::now()) };
	unsigned int d = date.GetDay();
	unsigned int m = date.GetMonth();
	int y = date.GetYear();
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
	Date tmp_date = curr.get()->GetDate();
	CheckIfWordWasUsed(database);
	if (!CheckIfTodayDate(tmp_date))
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
		SetUsersTodayDate(curr);
	}
	else
	{
		std::cout << "You already played today! Come back tommorow." << std::endl;
	}

}

void DailyChallenge::CheckIfWordWasUsed(WordsDatabase& database)
{
	fs::path filesPath("C:\\Users\\Oliwia\\source\\repos\\My Github\\wordle-clone\\wordle-clone\\Data");
	FileManagement fm(filesPath);
	
	if (!CheckIfTodayDate(fm.ReadDailyDateFromFile()))
	{
		SetWord(database);
		fm.SaveDailyWord(word);
		while (fm.SearchUsedWords(word))
		{
			SetWord(database);
			fm.SaveDailyWord(word);
		}
	}
	word = fm.ReadDailyWordFromFile();
}

void DailyChallenge::SetUsersTodayDate(std::shared_ptr<User> user)
{
	fs::path filesPath("C:\\Users\\Oliwia\\source\\repos\\My Github\\wordle-clone\\wordle-clone\\Data");
	FileManagement fm(filesPath);
	Date tmp_date;
	tmp_date = fm.ReadDailyDateFromFile();
	user->SetDate(tmp_date);
}