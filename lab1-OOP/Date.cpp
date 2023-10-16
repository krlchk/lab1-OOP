#include "Date.h"

Date::Date() : year(1970), month(1), day(1)
{
}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	if (isCorrectDate(year, month, day))
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
	else
	{
		throw std::exception(DATE_INVALID_ARGUMENT);
	}
}

bool Date::isLeapYear() const noexcept
{
	return isLeapYear(year);
}

std::string Date::toString() const noexcept
{
	return std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day);
}

TimeSpan Date::difference(const Date& other) const noexcept
{
	time_t rawtime, rawtime1;
	struct tm timeinfo = { 0 }, timeinfo1 = { 0 };

	timeinfo.tm_year = this->year - 1900;
	timeinfo.tm_mon = this->month;
	timeinfo.tm_mday = this->day;
	rawtime = mktime(&timeinfo);

	timeinfo1.tm_year = other.year - 1900;
	timeinfo1.tm_mon = other.month;
	timeinfo1.tm_mday = other.day;
	rawtime1 = mktime(&timeinfo1);

	time_t result = (time_t)difftime(rawtime, rawtime1);

	return TimeSpan(result);
}

bool Date::isCorrectDate(unsigned int year, unsigned int month, unsigned int day)
{
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (month == 2)
	{
		if (isLeapYear(year))
			return day <= 29;
		return day <= 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return day <= 30;
	}

	return true;
}

bool Date::operator >(const Date& other) const
{
	if (year != other.year)
		return year > other.year;
	else if (month != other.month)
		return month > other.month;
	else if (day != other.day)
		return day > other.day;
	return false;
}

bool Date::operator <(const Date& other) const
{
	if (year != other.year)
		return year < other.year;
	else if (month != other.month)
		return month < other.month;
	else if (day != other.day)
		return day < other.day;
	return false;
}

bool Date::operator >=(const Date& other) const
{
	if (year != other.year)
		return year > other.year;
	else if (month != other.month)
		return month > other.month;
	else if (day != other.day)
		return day > other.day;
	return true;
}

bool Date::operator <=(const Date& other) const
{
	if (year != other.year)
		return year < other.year;
	else if (month != other.month)
		return month < other.month;
	else if (day != other.day)
		return day < other.day;
	return true;
}

bool Date::operator ==(const Date& other) const
{
	return year == other.year && month == other.month && day == other.day;
}

bool Date::operator !=(const Date& other) const
{
	return year != other.year || month != other.month || day != other.day;
}

bool Date::isLeapYear(unsigned int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}