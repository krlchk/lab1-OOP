#include "TimeSpan.h"

TimeSpan::TimeSpan() : days(0), hours(0), minutes(0), seconds(0)
{
}

TimeSpan::TimeSpan(time_t seconds)
{
	seconds *= (seconds < 0) ? -1 : 1;
	this->days = seconds / 24 / 60 / 60; seconds %= 24 * 60 * 60;
	this->hours = seconds / 60 / 60; seconds %= 60 * 60;
	this->minutes = seconds / 60;
	this->seconds = seconds % 60;
}

TimeSpan::TimeSpan(int days, int hours, int minutes, int seconds) : TimeSpan()
{
	if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59)
		throw std::exception(TIMESPAN_INVALID_ARGUMENT);
	this->days = days;
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

std::string TimeSpan::toString() const noexcept
{
	return std::to_string(days) + ":" + std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
}