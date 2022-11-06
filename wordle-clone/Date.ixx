export module Date;
import <iostream>;
import <sstream>;

/**
 * Class responsible for date data.
 */
export class Date
{
	int day,	/**< Value represents day of the date.*/
		month,	/**< Value represents month of the date.*/
		year;	/**< Value represents year of the date.*/

public:
	/**
	* Non-parameter Date class constructor.
	*/
	Date();

	/**
	* Day class constructor.
	* @param day parameter repsresents day of the date
	* @param month parameter repsresents month of the date
	* @param year parameter repsresents year of the date
	*/
	Date(int day, int month, int year);

	/**
	 * Method sets day parameter.
	 * @param day parameter representing day of the date
	 */
	void SetDay(int day);

	/**
	 * Method sets month parameter.
	 * @param day parameter representing month of the date
	 */
	void SetMonth(int month);

	/**
	 * Method sets year parameter.
	 * @param day parameter representing year of the date
	 */
	void SetYear(int year);

	/**
	 * Method returns day class parameter.
	 * @return parameter representing day of the date
	 */
	int GetDay();

	/**
	 * Method returns month class parameter.
	 * @return parameter representing month of the date
	 */
	int GetMonth();

	/**
	 * Method returns year class parameter.
	 * @return parameter representing year of the date
	 */
	int GetYear();

	/**
	* Method gets date from a text file (in yyyy-mm-dd format).
	* @param line parameter represents line in a text file to read date from
	* @return date read from file
	*/
	Date ReadDateFromFile(std::string& line);

	/**
	* Method writes date to a text file (in yyyy-mm-dd format).
	* @param file represtenting output stream object
	*/
	void WriteDateToFile(std::ostream& file);

	/**
	* << operator.
	* @param print parameter represtenting output stream object
	* @param printThis date to be printed
	*/
	friend std::ostream& operator<<(std::ostream& print, const Date& printThis);

};