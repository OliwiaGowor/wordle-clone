export module Date;
import <iostream>;
import <sstream>;

export class Date
{
	int day, month, year;

public:
	Date();
	Date(int day, int month, int year);

	void SetDay();
	void SetMonth();
	void SetYear();
	int GetDay();
	int GetMonth();
	int GetYear();
	Date ReadDateFromFile(std::string& line);
	void WriteDateToFile(std::ostream& file);
	friend std::ostream& operator<<(std::ostream& print, const Date& printThis);

};