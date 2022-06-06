module;

module Menu;

Menu::Menu(FileManagement& args)
{
    this->mainArgs = args;
}

void Menu::RunProgram()
{
    mainArgs.LoadUsers(list_of_users);
    mainArgs.LoadDatabase(wordsDatabase);

    if (!StartingScreen())
    {
        MainMenu();
    }

    mainArgs.SaveUsers(list_of_users.GetpHead());
    list_of_users.~ListOfUsers();
}

bool Menu::StartingScreen()
{
    bool exit = false;
    this->choice = 1;
    while (choice)
    {
        std::cout << "WORDLE" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "WELCOME" << std::endl;
        std::cout << "Please log in or create new account to play." << std::endl;

        std::cout << "[1]- Log in" << std::endl;
        std::cout << "[2]- Create new account" << std::endl;
        std::cout << "[0]- Quit" << std::endl << std::endl;

        this->choice = UserInteractionHelper::CheckIfInt();

        switch (choice)
        {
        case 1:
            Login();
            return exit;
            break;
        case 2:
            list_of_users.CreateUser();
            return exit;
            break;
        case 0:
            exit = true;
            return exit;
            break;
        default:
            std::cout << "Incorrect number!" << std::endl << std::endl;
            break;
        }
    }
}


void Menu::Login()
{
    if (!list_of_users.GetpHead())
    {
        std::cout << "There are no users in the database! First create new user" << std::endl;
        return;
    }
    std::string usr_username, usr_password;
    std::cout << "login: ";
    std::cin >> usr_username;
    while (!list_of_users.CheckIfUserExists(usr_username) || !UserInteractionHelper::CheckIfCorrectUsername(usr_username))
    {
        std::cout << "User doesn't exists! Do you want to continue?" << std::endl;
        std::cout << "[1] Yes \n[2] No" << std::endl;
        this->choice = UserInteractionHelper::CheckIfInt();
        switch (choice)
        {
        case 1:
            std::cout << "login: ";
            std::cin >> usr_username;
            break;
        case 2:
            StartingScreen();
            return;
            break;
        default:
            std::cout << "Incorrect number!" << std::endl << std::endl;
            break;
        }
        
    }
    std::cout << "password: ";
    std::cin >> usr_password;
    while (!list_of_users.CheckIfRightPassword(usr_password)) //dodac cofanie
    {
        std::cout << "Wrong password! Do you want to continue?" << std::endl;
        std::cout << "[1] Yes \n[2] No" << std::endl;
        this->choice = UserInteractionHelper::CheckIfInt();
        switch (choice)
        {
        case 1:
            std::cout << "password: ";
            std::cin >> usr_password;
            break;
        case 2:
            StartingScreen();
            return;
            break;
        default:
            std::cout << "Incorrect number!" << std::endl << std::endl;
            break;
        }
    }
    list_of_users.SetCurrentUser(usr_username);
}

void Menu::MainMenu()
{
    this->choice = 1;
    while (choice)
    {
        std::cout << "WORDLE" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "MAIN MENU" << std::endl << std::endl;

        std::cout << "[1]- Daily challenge" << std::endl;
        std::cout << "[2]- Free game" << std::endl;
        std::cout << "[3]- Check your statistics" << std::endl;
        std::cout << "[4]- Leaderboard" << std::endl;
        std::cout << "[5]- Settings" << std::endl;
        std::cout << "[6]- Log out" << std::endl;
        std::cout << "[0]- Quit" << std::endl << std::endl;

        this->choice = UserInteractionHelper::CheckIfInt();

        switch (choice)
        {
        case 1:
            daily.Game(wordsDatabase, list_of_users);
            break;
        case 2:
            free_play.Game(wordsDatabase, list_of_users);
            break;
        case 3:
            list_of_users.GetCurrentUser().get()->DisplayStatistics();
            break;
        case 4:
            MenuLeaderboard();
            break;
        case 5:
            SettingsMenu();
            break;
        case 6:
            StartingScreen();
            break;
        case 0:
            choice = 0;
            break;
        default:
            std::cout << "Incorrect number!" << std::endl << std::endl;
            break;
        }
    }
}


void Menu::SettingsMenu()
{
    this->choice = 1;
    while (choice)
    {
        std::cout << "WORDLE" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "SETTINGS MENU" << std::endl << std::endl;

        std::cout << "[1]- Change password" << std::endl;
        std::cout << "[2]- Change username" << std::endl;
        std::cout << "[3]- Delete account" << std::endl;
        std::cout << "[4]- Return" << std::endl;

        this->choice = UserInteractionHelper::CheckIfInt();

        switch (choice)
        {
        case 1:
            list_of_users.GetCurrentUser().get()->ChangePassword();
            break;
        case 2:
            list_of_users.GetCurrentUser().get()->ChangeUsername();
            break;
        case 3:
            list_of_users.DeleteUser();
            break;
        case 4:
            MainMenu();
            break;
        default:
            std::cout << "Incorrect number!" << std::endl << std::endl;
            break;
        }
    }
}

void Menu::MenuLeaderboard()
{
    this->choice = 1;
    while (choice)
    {
        std::cout << "Leaderboards" << std::endl;
        std::cout << "---------------------------------" << std::endl;

        std::cout << "Choose leaderboard" << std::endl << std::endl;
        std::cout << "[1]- Leaderboard by the longest daily streak" << std::endl;
        std::cout << "[2]- Leaderboard by the longest free play streak" << std::endl;
        std::cout << "[3]- Leaderboard by the most won free games" << std::endl;
        std::cout << "[4]- Return" << std::endl;

        this->choice = UserInteractionHelper::CheckIfInt();

        switch (choice)
        {
        case 1:
            Leaderboard::LeaderboardByDaily(list_of_users);
            break;
        case 2:
            Leaderboard::LeaderboardByFree(list_of_users);
            break;
        case 3:
            Leaderboard::LeaderboardByDailyWins(list_of_users);
            break;
        case 4:
            MainMenu();
            break;
        default:
            std::cout << "Incorrect number!" << std::endl << std::endl;
            break;
        }
    }
}