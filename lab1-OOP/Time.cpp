#include "Time.h"

Time::Time() : hours(0), minutes(0), seconds(0)
{
}

Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
	if (isCorrectTime(hours, minutes, seconds))
	{
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}
	else
	{
		throw std::exception(TIME_INVALID_ARGUMENT);
	}
}

std::string Time::toString() const noexcept
{
	return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
}

TimeSpan Time::difference(const Time& other) const noexcept
{
	time_t rawtime, rawtime1;
	struct tm timeinfo = { 0 }, timeinfo1 = { 0 };

	timeinfo.tm_mday = 1;
	timeinfo.tm_mon = 0;
	timeinfo.tm_year = 123;

	timeinfo.tm_hour = this->hours;
	timeinfo.tm_min = this->minutes;
	timeinfo.tm_sec = this->seconds;
	rawtime = mktime(&timeinfo);

	timeinfo1.tm_mday = 1;
	timeinfo1.tm_mon = 0;
	timeinfo1.tm_year = 123;

	timeinfo1.tm_hour = other.hours;
	timeinfo1.tm_min = other.minutes;
	timeinfo1.tm_sec = other.seconds;
	rawtime1 = mktime(&timeinfo1);

	time_t result = (time_t)difftime(rawtime, rawtime1);

	return TimeSpan(result);
}

bool Time::operator >(const Time& other) const
{
	unsigned int t1 = hours * 3600 + minutes * 60 + seconds;
	unsigned int t2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
	return t1 > t2;
}

bool Time::operator <(const Time& other) const
{
	unsigned int t1 = hours * 3600 + minutes * 60 + seconds;
	unsigned int t2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
	return t1 < t2;
}

bool Time::operator >=(const Time& other) const
{
	unsigned int t1 = hours * 3600 + minutes * 60 + seconds;
	unsigned int t2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
	return t1 >= t2;
}

bool Time::operator <=(const Time& other) const
{
	unsigned int t1 = hours * 3600 + minutes * 60 + seconds;
	unsigned int t2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
	return t1 <= t2;
}

bool Time::operator ==(const Time& other) const
{
	unsigned int t1 = hours * 3600 + minutes * 60 + seconds;
	unsigned int t2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
	return t1 == t2;
}

bool Time::operator !=(const Time& other) const
{
	unsigned int t1 = hours * 3600 + minutes * 60 + seconds;
	unsigned int t2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
	return t1 != t2;
}

bool Time::isCorrectTime(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
	if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59)
		return false;
	return true;
}