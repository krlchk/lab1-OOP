#pragma once
#include "Date.h"
#include "Time.h"
#include "TimeSpan.h"

class DateTime :
    public Date, public Time
{
private:

public:
    DateTime();
    DateTime(unsigned int, unsigned int, unsigned int);
    DateTime(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

    std::string toString() const noexcept;
    TimeSpan difference(const DateTime&) const noexcept;
};
