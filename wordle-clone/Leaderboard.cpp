module;

module Leaderboard;

void Leaderboard::LeaderboardByDaily(ListOfUsers& list)
{
    std::cout << "Leaderboard" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Longest daily streak" << std::endl;
    std::vector<User*> sorted = list.SortByDaily();
    if (sorted.size() > 10)
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << sorted[i]->GetUsername() << ' ' << sorted[i]->GetStreakDaily() << std::endl;
        }
    }
    else
    {
        for (int i = 0; i < sorted.size(); i++)
        {
            std::cout << sorted[i]->GetUsername() << ' ' << sorted[i]->GetStreakDaily() << std::endl;
        }
    }
}

void Leaderboard::LeaderboardByFree(ListOfUsers& list)
{
    std::cout << "Leaderboard" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Longest free streak" << std::endl;
    std::vector<User*> sorted = list.SortByFree();
    if (sorted.size() > 10)
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << sorted[i]->GetUsername() << ' ' << sorted[i]->GetStreakFree() << std::endl;
        }
    }
    else
    {
        for (int i = 0; i < sorted.size(); i++)
        {
            std::cout << sorted[i]->GetUsername() << ' ' << sorted[i]->GetStreakFree() << std::endl;
        }
    }
}

void Leaderboard::LeaderboardByDailyWins(ListOfUsers& list)
{
    std::cout << "Leaderboard" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Most daily wins" << std::endl;
    std::vector<User*> sorted = list.SortByDailyWins();
    if (sorted.size() > 10)
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << sorted[i]->GetUsername() << ' ' << sorted[i]->GetDailyWins() << std::endl;
        }
    }
    else
    {
        for (int i = 0; i < sorted.size(); i++)
        {
            std::cout << sorted[i]->GetUsername() << ' ' << sorted[i]->GetDailyWins() << std::endl;
        }
    }
}