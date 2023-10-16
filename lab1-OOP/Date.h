#pragma once
#include <string>
#include <vector>
#include <ctime>

#include "TimeSpan.h"

#define DATE_INVALID_ARGUMENT "One or more argument (year | month | day) is not correct!"
#define DATE_INVALID_STRING_FORMAT "Input string was not i a correct format!"

class Date
{
protected:
	unsigned int year;
	unsigned int month;
	unsigned int day;
public:
	Date();
	Date(unsigned int, unsigned int, unsigned int);

	bool isLeapYear() const noexcept;
	std::string toString() const noexcept;
	TimeSpan difference(const Date&) const noexcept;

	bool operator >(const Date&) const;
	bool operator <(const Date&) const;
	bool operator >=(const Date&) const;
	bool operator <=(const Date&) const;
	bool operator ==(const Date&) const;
	bool operator !=(const Date&) const;

	static bool isCorrectDate(unsigned int, unsigned int, unsigned int);
	static bool isLeapYear(unsigned int);
};
