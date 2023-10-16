#pragma once
#include <string>

#define TIMESPAN_INVALID_ARGUMENT "One or more argument (hours | minutes | seconds) is not correct!"

class TimeSpan
{
private:
	int days;
	int hours;
	int minutes;
	int seconds;
public:
	TimeSpan();
	TimeSpan(time_t);
	TimeSpan(int, int, int, int);

	std::string toString() const noexcept;
};
