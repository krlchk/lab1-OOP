#include "DateTime.h"

DateTime::DateTime()
{
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day) :
	Date(year, month, day), Time()
{
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hours, unsigned int minutes, unsigned int seconds) :
	Date(year, month, day), Time(hours, minutes, seconds)
{
}

std::string DateTime::toString() const noexcept
{
	return Date::toString() + " " + Time::toString();
}

TimeSpan DateTime::difference(const DateTime& other) const noexcept
{
	time_t rawtime, rawtime1;
	struct tm timeinfo = { 0 }, timeinfo1 = { 0 };

	timeinfo.tm_year = this->year - 1900;
	timeinfo.tm_mon = this->month;
	timeinfo.tm_mday = this->day;
	timeinfo.tm_hour = this->hours;
	timeinfo.tm_min = this->minutes;
	timeinfo.tm_sec = this->seconds;
	rawtime = mktime(&timeinfo);

	timeinfo1.tm_year = other.year - 1900;
	timeinfo1.tm_mon = other.month;
	timeinfo1.tm_mday = other.day;
	timeinfo1.tm_hour = other.hours;
	timeinfo1.tm_min = other.minutes;
	timeinfo1.tm_sec = other.seconds;
	rawtime1 = mktime(&timeinfo1);

	time_t result = (time_t)difftime(rawtime, rawtime1);

	return TimeSpan(result);
}