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
    day = xmlGetInt(node, "Day", "TDate");
    month = xmlGetInt(node, "Month", "TDate");
    year = xmlGetInt(node, "Year", "TDate");
}


void TDate::print()
{
    cout.fill('0');
    cout << setw(2) << day << '.' << setw(2) << month << '.' << year;
}
