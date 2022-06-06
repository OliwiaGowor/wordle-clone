module;
module WordsDatabase;

WordsDatabase::WordsDatabase()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	this->randomEngine = std::default_random_engine(seed);
}

std::vector<std::string> WordsDatabase::GetDatabase()
{
	return words;
}

std::vector<std::string>* WordsDatabase::GetAdressDatabase()
{
	return &words;
}

std::string WordsDatabase::GetWord()
{
	return words.at(randomEngine() % words.size());
}

bool WordsDatabase::IsValidWord(std::string to_check)
{
	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == to_check)
			return true;
	}
	return false;
}

