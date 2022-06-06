module;
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
    file.open(filesPath.string() + "\\users.txt", std::ios::in);

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


void FileManagement::SaveDailyWord()
{

}