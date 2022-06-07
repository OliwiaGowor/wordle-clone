module;
#include "date.h"
module FileManagement;
namespace fs = std::filesystem;

FileManagement::FileManagement()
{

}

FileManagement::FileManagement(fs::path path)
{
 this -> filesPath = path;
}

void FileManagement::LoadUsers(ListOfUsers& list) //dodac sprawdzanie czy istnieja sciezki i pliki
{
    std::ifstream file;
    std::string line;
    file.open(filesPath.string() + "\\users.txt", std::ios::in);

    if (file.is_open())
    {
        list.ReadUserFromFile(line, filesPath.string() + "\\users.txt");
        file.close();
    }
    else
        std::cout << "Error occured while loading users! Restart application." << std::endl;
}

void FileManagement::SaveUsers(std::shared_ptr<ListOfUsersElement> list)
{
    ListOfUsersElement* t = list.get();
    std::ofstream file;
    std::string line;
    file.open(filesPath.string() + "\\users.txt", std::ios::out);

    if (file)
    {
        while (t)
        {
            (t->pUser)->WriteUserToFile(file);
            t = t->pNext.get();
        }
    }
    else
    {
        std::cout << "Error occured while saving users!" << std::endl;
    }
}

void FileManagement::LoadDatabase(WordsDatabase& wordsDatabase)
{
    fs::path databasePath(filesPath.string() + "\\word_base.txt");
    std::ifstream file(databasePath.string());
    std::string line;
    auto* ptr = wordsDatabase.GetAdressDatabase();

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            (*ptr).push_back(line);
        }
    }
    else
        std::cout << "Error occured while loading database! Restart application." << std::endl;
}

bool FileManagement::SearchUsedWords(std::string word)
{
    fs::path used_words_path(filesPath.string() + "\\words_used.txt");
    std::ifstream file(used_words_path.string());
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            if (line == word)
            {
                return true;
            }
        }
    }
    else
        return false;
}

void FileManagement::SaveDailyWord(std::string word)
{
    using namespace date;
    using namespace std::chrono;
    std::ofstream file;
    std::string line;
    auto today = date::year_month_day{ floor<days>(system_clock::now()) };
    file.open(filesPath.string() + "\\daily_word.txt", std::ios::out);
   
    if (file.is_open())
    {
        file << today << std::endl << word;
    }
    else
    	std::cout << "Error occured while opening file! Restart application." << std::endl;
}

Date FileManagement::ReadDailyDateFromFile()
{
    fs::path dailyPath(filesPath.string() + "\\daily_word.txt");
    std::ifstream file(dailyPath.string());
    std::string line;
    int day, month, year;
    if (file.is_open())
    {
        std::stringstream ss(line);
        ss >> day >> month >> year;
    }
    else
        std::cout << "Something went wrong!" << std::endl;
    Date tmp_date(day, month, year);
    return tmp_date;
}