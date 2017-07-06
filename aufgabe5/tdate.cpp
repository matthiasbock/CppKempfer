// class tdate

#include "tdate.h"


TDate::TDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    day = ltm->tm_mday;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
}


TDate::TDate(int dd, int mm, int yyyy)
{
    this->day = dd;
    this->month = mm;
    this->year = yyyy;
}


TDate::TDate(xmlNodePtr node)
{
    load(node);
}

TDate::~TDate()
{
    cout << "Destructing TDate \"" << day << "." << month << "." << year <<"\"..." << endl;
}

void TDate::load(xmlNodePtr node)
{
    if (node == nullptr)
        return;

    day = xmlGetInt(node, "Day", "TDate");
    month = xmlGetInt(node, "Month", "TDate");
    year = xmlGetInt(node, "Year", "TDate");
}


void TDate::print()
{
    cout.fill('0');
    cout << setw(2) << right << day << '.' << setw(2) << right << month << '.' << year;
}


bool TDate::isLeapYear(int year)
{
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}


uint8_t TDate::daysPerMonth(int month, int year)
{
    static const uint8_t dayCount[] =
    {
        31, // january
        28, // february
        31, // march
        30, // april
        31, // may
        30, // june
        31, // july
        31, // august
        30, // september
        31, // october
        30, // november
        31, // december
    };

    return ((month == 2) && isLeapYear(year)) ? 29 : dayCount[month-1];
}


/**
 * @brief Creates a new date object by \
 *        adding or subtracting a given number of days
 * @param days Number of days to add/subtract from date
 */
TDate* operator+(TDate date, int days)
{
    int day = date.day;
    int month = date.month;
    int year = date.year;

    while (days > 0)
    {
        days--;
        day++;
        if (day > TDate::daysPerMonth(month, year))
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }

    return new TDate(day, month, year);
}
