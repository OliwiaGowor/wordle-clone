module;
module Date;

Date::Date(): day(1), month(1), year(2000)
{
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date Date::ReadDateFromFile(std::string& line)
{
	Date tmpdate;
	std::stringstream ss(line);
	ss >> tmpdate.day >> tmpdate.month >> tmpdate.year;
	return tmpdate;
}

int Date::GetDay()
{
	return day;
}

int Date::GetMonth()
{
	return month;
}

int Date::GetYear()
{
	return year;
}

std::ostream& operator<<(std::ostream& write, const Date& printThis)
{
	write << printThis.day << ' ' << printThis.month << ' ' << printThis.year << std::endl;
	return write;
}
