#pragma once
#include <string>
#include <vector>
#include <ctime>

#include "TimeSpan.h"

#define TIME_INVALID_ARGUMENT "One or more argument (hours | minutes | seconds) is not correct!"
#define TIME_INVALID_STRING_FORMAT "Input string was not i a correct format!"

class Time
{
protected:
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;
public:
	Time();
	Time(unsigned int, unsigned int, unsigned int);

	std::string toString() const noexcept;
	TimeSpan difference(const Time& other) const noexcept;

	bool operator >(const Time&) const;
	bool operator <(const Time&) const;
	bool operator >=(const Time&) const;
	bool operator <=(const Time&) const;
	bool operator ==(const Time&) const;
	bool operator !=(const Time&) const;

	static bool isCorrectTime(unsigned int, unsigned int, unsigned int);
};
