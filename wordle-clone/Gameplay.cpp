module;
module Gameplay;


void Gameplay::SetWord(WordsDatabase& database)
{
	this->word = database.GetWord();
}

bool Gameplay::CheckIfRightWord(std::string usr_word, std::vector<std::string> words)
{
	bool in_database = false;
	std::ranges::transform(usr_word, usr_word.begin(), [](unsigned char ch) -> unsigned char { return std::tolower(ch); });
	std::regex reg("[a-z]{5}");
	std::smatch match;
	int numb_of_threads = 7;
	std::vector<std::thread> threads(numb_of_threads);
	if (std::regex_match(usr_word, match, reg))
	{
		for (int i = 0; i < threads.size(); i++)
		{
			threads[i] = std::thread([&in_database, words, usr_word, numb_of_threads, i]()
				{
					auto begin = words.begin() + i * words.size() / numb_of_threads;
					auto end = words.begin() + (i + 1) * words.size() / numb_of_threads;
					for (auto it = begin; it != end; it++)
					{
						if (usr_word == *it)
						{
							in_database = true;
						}
					}
				});
		}

		for (auto& t : threads)
		{
			t.join();
		}
	}

	if (std::regex_match(usr_word, match, reg) && in_database)
	{
		return true;
	}
	else
		return false;
}


//std::string Gameplay::GridManagement(std::string usr_word)
//{
//	std::string grid = "*****";
//	for (int i = 0; i < usr_word.size(); i++)
//	{
//		for (int j = 0; j < usr_word.size(); j++)
//		{
//			if (word[i] == usr_word[j] && i == j)
//			{
//				grid[j] = word[i];
//			}
//			else if (word[i] == usr_word[j])
//			{
//				grid[j] = '-';
//			}
//		}
//	}
//	return grid;
//}

std::string Gameplay::ParallelGridManagement(std::string usr_word)
{
	std::string grid = "-----";
	std::string tmp_word = this->word;
	std::vector<std::thread> threads(5);
	for (int i = 0; i < threads.size(); i++)
	{
		threads[i] = std::thread([&grid, i, tmp_word, usr_word]()
		{
			for (int j = 0; j < usr_word.size(); j++)
			{
				if (tmp_word[i] == usr_word[j] && i == j)
				{
					grid[j] = tmp_word[i];
				}
				else if (tmp_word[i] == usr_word[j] && grid[j] == '-')
				{
					grid[j] = '*';
				}
			}
		});
	}

	for (auto& t : threads)
	{
		t.join();
	}

	return grid;
}

bool Gameplay::Logic(WordsDatabase& database)
{
	int counter = 0;
	std::string user_input, grid;
	while (counter < 5)
	{
		std::cout << "Enter 5 letter word: ";
		std::cin >> user_input;
		while (!CheckIfRightWord(user_input, database.GetDatabase()))
		{
			std::cout << "Incorrect word! Please enter right word." << std::endl;
			std::cin >> user_input;
		}

		grid = ParallelGridManagement(user_input);
		std::cout << grid << std::endl;
		counter++;
		if (grid == word)
		{
			return true;
		}
	}
	return false;
}


