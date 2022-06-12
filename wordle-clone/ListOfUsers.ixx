export module ListOfUsers;
import User;
import <iostream>;
import <fstream>;
import <sstream>;
import <memory>;
import <ranges>;
import <algorithm>;
import <vector>;
import UserInteractionHelper;

export struct ListOfUsersElement
{
    std::unique_ptr<ListOfUsersElement> pNext;
    std::shared_ptr<User> pUser;
};

export class ListOfUsers
{
    std::shared_ptr<ListOfUsersElement> pHead;
    std::shared_ptr<User> current_user;
    size_t size;

public:
    std::shared_ptr<ListOfUsersElement> GetpHead();
    void SetCurrentUser(std::string username);
    std::shared_ptr<User> GetCurrentUser();
    size_t GetSize();
    void CreateUser();
    void AddUser(std::string username, std::string password, int streak_free, int wins_daily, int loses_daily, Date tmpdate);
    bool CheckIfUserExists(std::string username);
    bool CheckIfRightPassword(std::string password);
    void ReadUserFromFile(std::string& line, std::string fileName);
    void DeleteUser();
    std::vector<User*> SortByFree();
    std::vector<User*> SortByDailyWins();
    ~ListOfUsers();
};
