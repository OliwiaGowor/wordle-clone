module;
module UserInteractionHelper;

int UserInteractionHelper::CheckIfInt()
{
    int number;
    std::cin >> number;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cout << "Only numbers!" << std::endl;
        std::cin >> number;
    }
    return number;
}


bool UserInteractionHelper::CheckIfCorrectUsername(std::string username)
{
   std::regex check(".{3,20}"); //wywala????????
   std::smatch match;
   if (!std::regex_match(username, match, check))
   {
       return false;
   }
   return true;
}


bool UserInteractionHelper::CheckIfCorrectPassword(std::string password)
{
    std::regex check("^(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?=.*[#?!@$%^&*-]).{8,20}$");
    std::smatch match;
    if (regex_match(password, match, check))
    {
        return true;
    }
    else
        return false;
}