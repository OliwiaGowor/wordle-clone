module;
module FreePlay;

FreePlay::FreePlay()
{
}

void FreePlay::DisplayStartingScreen()
{
	std::cout << "WORDLE" << std::endl;
	std::cout << "Free play" << std::endl;
	std::cout << "An existing letter in the right spot will appear as itself. An existing letter in the wrong spot will appear as \'-\'. A non existing letter will appear as \'*\'" << std::endl;
}

bool FreePlay::Continue()
{
	int choice;
	std::cout << "Do you want to continue?" << std::endl;
	std::cout << "[1] Yes \n" << "[2] No" << std::endl;
	choice = UserInteractionHelper::CheckIfInt();
	switch (choice)
	{
	case 1:
		return true;
		break;
	case 2:
		return false;
		break;
	default:
		std::cout << "Wrong number!" << std::endl;
		break;
	}
}

void FreePlay::Game(WordsDatabase& database, ListOfUsers& list_of_users)
{
	int streak = 0;
	DisplayStartingScreen();
	
	bool play = true;
	while (play)
	{
		SetWord(database);
		while (CheckIfWordAgain())
		{
			SetWord(database);
		}
		used_words.push_back(word);
		if (Logic(database))
		{
			streak++;
			std::cout << "Congratulations you guessed right! Your current streak: " << streak << std::endl;
			play = Continue();
		}
		else
		{
			std::cout << "You lost!" << std::endl;
			std::cout << "The word was: " << word << std::endl;
			play = Continue();
		}
	}		
	auto tmp = list_of_users.GetCurrentUser();
	User* current = tmp.get();
	if (current->GetStreakFree() < streak)
	{
		current->SetStreakFree(streak);
	}
}

//void FreePlay::SetWords(WordsDatabase& database)
//{
//	int numb_of_threads = 5;
//	std::vector<std::jthread> threads(numb_of_threads);
//
//	for (int i = 0; i < threads.size(); ++i)
//	{
//		threads[i] = std::jthread([i, &words, database]()
//			{
//				words[i] = database.GetWord();
//			});
//	}
//
//}


bool FreePlay::CheckIfWordAgain()
{
	if (used_words.size() > 20)
	{
		used_words.clear();
	}

	for (int i = 0; i < used_words.size(); i++)
	{
		if (word == used_words[i])
		{
			return true;
		}
		else
			return false;
	}
}
