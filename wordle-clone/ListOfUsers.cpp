module;
module ListOfUsers;


std::shared_ptr<ListOfUsersElement> ListOfUsers::GetpHead()
{
    return pHead;
}
std::shared_ptr<User> ListOfUsers::GetCurrentUser()
{
    return current_user;
}

void ListOfUsers::SetCurrentUser(std::string username)
{
    ListOfUsersElement* t = pHead.get();
    std::string tmpdata;

    if (t) {
        while (t)
        {
            tmpdata = (t->pUser)->GetUsername();
            if (tmpdata == username)
            {
                current_user = t->pUser;
                break;
            }
            t = t->pNext.get();
        }
    }
    else
    {
        current_user = nullptr;
    }
}

size_t ListOfUsers::GetSize()
{
    return this->size;
}

void ListOfUsers::CreateUser()
{
    std::string usr_username,
                usr_password;
    int tmp = 0;
    Date tmpdate;

    std::cout << "login: ";
    std::cin >> usr_username;
    while (CheckIfUserExists(usr_username) | !UserInteractionHelper::CheckIfCorrectUsername(usr_username))
    {
        std::cout << "Wrong username or user already exists! Choose different username." << std::endl;
        std::cout << "login: ";
        std::cin >> usr_username;
    }
    std::cout << "password: ";
    std::cin >> usr_password;
    while (!UserInteractionHelper::CheckIfCorrectPassword(usr_password))
    {
        std::cout << "Wrong password! Password must contain of minimum 8 characters, one big letter, one small letter, one number and one symbol." << std::endl;
        std::cout << "password: ";
        std::cin >> usr_password;
    }
    AddUser(usr_username, usr_password, tmp, tmp, tmp, tmp, tmpdate); 
    SetCurrentUser(usr_username);
}


void ListOfUsers::AddUser(std::string username, std::string password, int streak_free, int streak_daily, int wins_daily, int loses_daily, Date date)
{
    std::unique_ptr<ListOfUsersElement> newOne(new ListOfUsersElement);

    if (!pHead)
    {
        std::unique_ptr<User> tmp = std::make_unique<User>(username, password, streak_free, streak_daily, wins_daily, loses_daily, date);
        newOne->pUser = move(tmp);
        pHead = move(newOne);
    }
    else
    {
        ListOfUsersElement* tmp2 = pHead.get();
        while (tmp2->pNext)
        {
            tmp2 = tmp2->pNext.get();
        }

        std::unique_ptr<User> tmp = std::make_unique<User>(username, password, streak_free, streak_daily, wins_daily, loses_daily, date);
        newOne->pUser = move(tmp);

        tmp2->pNext = move(newOne);
    }
    size++;
}

bool ListOfUsers::CheckIfUserExists(std::string username)
{
    ListOfUsersElement* t = pHead.get();
    std::string tmpdata;

    if (t) {
        while (t)
        {
            tmpdata = (t->pUser)->GetUsername();
            if (tmpdata == username)
            {
                return true;
            }
            t = t->pNext.get();
        }
    }
    else
    {
        return false;
    }
    return false;
}

bool ListOfUsers::CheckIfRightPassword(std::string password)
{
    ListOfUsersElement* t = pHead.get();
    std::string tmpdata;

    if (t) {
        while (t)
        {
            tmpdata = (t->pUser)->GetPassword();
            if (tmpdata == password)
            {
                return true;
            }
            t = t->pNext.get();
        }
    }
    else
    {
        return false;
    }
    return false;
}

void ListOfUsers::ReadUserFromFile(std::string& line, std::string fileName)
{
    std::string tmpusername,
        tmppassword;
    int tmpstreak_free,
        tmpstreak_daily,
        tmpwins_daily,
        tmploses_daily;
    Date tmpdate;
    std::ifstream file(fileName);
    int counter = 1;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        switch (counter)
        {
        case 1:
            tmpusername = line;
            counter++;
            break;
        case 2:
            tmppassword = line;
            counter++;
            break;
        case 3:
            tmpstreak_free = atoi(line.c_str());
            counter++;
            break;
        case 4:
            tmpstreak_daily = atoi(line.c_str());
            counter++;
            break;
        case 5:
            tmpwins_daily = atoi(line.c_str());
            counter++;
            break;
        case 6:
            tmploses_daily = atoi(line.c_str());
            counter++;
            break;
        case 7:
            tmpdate = tmpdate.ReadDateFromFile(line);
            AddUser(tmpusername, tmppassword, tmpstreak_free, tmpstreak_daily, tmpwins_daily, tmploses_daily, tmpdate);
            counter = 1;
            break;
        }

    }
}

void ListOfUsers::DeleteUser() //moze zostawic samo usuwanie, poczatek zrobic w osobnej funkcji
{
    int choice = 1, counter = 1;
    ListOfUsersElement* tmp = pHead.get();
    std::string tmpdata;
    std::cout << "Are you sure you want to delete your account?" << std::endl;
    std::cout << "[1] Yes" << std::endl;
    std::cout << "[2] No" << std::endl;
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    choice = UserInteractionHelper::CheckIfInt();

    switch (choice)
    {
    case 1:

        while (tmp)
        {
                if (pHead == nullptr)
                {
                    return;
                }
                else if (counter == 1)
                {
                    std::shared_ptr<ListOfUsersElement> tmp = std::move(pHead);
                    pHead = std::move(tmp->pNext);
                    std::cout << "Account succesfully deleted." << std::endl;
                    size--;
                    return;
                }
                else if (counter >= 2)
                {
                    int i = 1;
                    int j = 1;
                    ListOfUsersElement* tmp = pHead.get();
                    while (tmp)
                    {
                        tmp = tmp->pNext.get();
                        i++;
                    }
                    tmp = pHead.get();
                    while (tmp)
                    {
                        if ((j + 1) == counter) 
                            break;
                        tmp = tmp->pNext.get();
                        j++;
                    }
                    if (i <= counter)
                    {
                        return;
                    }
                    if (tmp->pNext->pNext)
                    {
                        std::unique_ptr<ListOfUsersElement> tmp2 = std::move(tmp->pNext->pNext);
                        tmp->pNext = std::move(tmp2);
                        std::cout << "Account succesfully deleted." << std::endl;
                        size--;
                        return;
                    }
                    else
                    {
                        tmp->pNext = std::move(tmp->pNext->pNext);
                        std::cout << "Account succesfully deleted." << std::endl;
                        size--;
                        return;
                    }
                }
            tmp = tmp->pNext.get();
            counter++;
        }
        break;
    case 2:
        choice = 0;
        break;
    default:
        std::cout << "Incorrect number!" << std::endl << std::endl;
        break;
    }
   
}


std::vector<User*> ListOfUsers::SortByFree()
{
    ListOfUsersElement* t = pHead.get();
    std::vector<User*> vector;
    if (t) {
        while (t)
        {
            vector.push_back(t->pUser.get());
            t = t->pNext.get();
        }
    }
    else
    {
        std::cout << "No users to show" << std::endl;
    }

    std::ranges::sort(vector, [](User * l, User * r) {
        return l->GetStreakFree() > r->GetStreakFree();
    });

    return vector;
}

std::vector<User*> ListOfUsers::SortByDaily()
{
    ListOfUsersElement* t = pHead.get();
    std::vector<User*> vector;
    if (t) {
        while (t)
        {
            vector.push_back(t->pUser.get());
            t = t->pNext.get();
        }
    }
    else
    {
        std::cout << "No users to show" << std::endl;
    }

    std::ranges::sort(vector, [](User* l, User* r) {
        return l->GetStreakDaily() > r->GetStreakDaily();
        });

    return vector;
}

std::vector<User*> ListOfUsers::SortByDailyWins()
{
    ListOfUsersElement* t = pHead.get();
    std::vector<User*> vector;
    if (t) {
        while (t)
        {
            vector.push_back(t->pUser.get());
            t = t->pNext.get();
        }
    }
    else
    {
        std::cout << "No users to show" << std::endl;
    }

    std::ranges::sort(vector, [](User* l, User* r) {
        return l->GetDailyWins() > r->GetDailyWins();
        });

    return vector;
}

ListOfUsers::~ListOfUsers()
{
    while (pHead)
    {
        pHead = std::move(pHead->pNext);
    }
}
