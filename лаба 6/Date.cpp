#include "Date.h"



int Date::Define_Month(int month, int year)
{
	if (month > 12)
	{
		month = month - 12;
		year = year + 1;
	}
	switch (month)
	{
	case 1:
		return 31;
	case 2:
		if (year % 4 == 0)
			return 29;
		else
			return 28;
	case 3:
		return 31;
	case 4:
		return 30;
	case 5:
		return 31;
	case 6:
		return 30;
	case 7:
		return 31;
	case 8:
		return 31;
	case 9:
		return 30;
	case 10:
		return 31;
	case 11:
		return 30;
	case 12:
		return 31;
	default:
		return -1;
	}
}

Date::Date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Date::Date(std::string date)
{
	std::string saver;
	saver.append(date, 0, 2);
	this->day = std::stoi(saver);
	saver.clear();
	saver.append(date, 3, 2);
	this->month = std::stoi(saver);
	saver.clear();
	saver.append(date, 6, 2);
	this->year = std::stoi(saver);
}

void Date::operator =(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}
bool Date::operator ==(const Date& other)
{
	if (this->year != other.year)
		return false;
	if (this->month != other.month)
		return false;
	if (this->day != other.day)
		return false;
	return true;
}
bool Date::operator !=(const Date& other)
{
	if (this->year != other.year)
		return true;
	if (this->month != other.month)
		return true;
	if (this->day != other.day)
		return true;
	return false;
}
bool Date::operator < (const Date& other)
{
	if (this->year < other.year)
		return true;
	if (this->year != other.year)
		return false;
	if (this->month < other.month)
		return true;
	if (this->month != other.month)
		return false;
	if (this->day < other.day)
		return true;
	if (this->day != other.day)
		return false;
	return false;
}
bool Date::operator > (const Date& other)
{
	if (this->year > other.year)
		return true;
	if (this->year != other.year)
		return false;
	if (this->month > other.month)
		return true;
	if (this->month != other.month)
		return false;
	if (this->day > other.day)
		return true;
	if (this->day != other.day)
		return false;
	return false;
}

int Date::SetDate()
{
	std::cout << "¬ведите число:\n";
	this->day = input_int();
	std::cin.clear();
	std::cout << "¬ведите мес€ц:\n";
	this->month = input_int();
	std::cin.clear();
	std::cout << "¬ведите год:\n";
	this->year = input_int();;
	std::cin.clear();
	DateTimeExeption excp;
	if (this->month > 12 || this->day > Define_Month(this->month, this->year))
		throw excp;
	if (this->month < 1 || this->day < 1)
		throw excp;
	return 0;
}
std::string Date::GetDate()
{
	std::string date = "";
	if (this->day < 10)
		date += "0" + std::to_string(this->day);
	else
		date += std::to_string(this->day);
	date += ".";
	if (this->month < 10)
		date += "0" + std::to_string(this->month);
	else
		date += std::to_string(this->month);
	date += "." + std::to_string(this->year);

	return date;
}