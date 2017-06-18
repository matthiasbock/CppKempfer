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
:day(0),
 month(0),
 year(0)
{
    xmlNodePtr childNode;

    childNode = xmlGetChildByName(node, "Day");
    if (childNode != nullptr)
    {
        try
        {
            this->day = atoi((char*) xmlNodeGetContent(childNode));
            cout << "Day: " << this->day << endl;
        }
        catch (exception e)
        {
            cout << "Error: Conversion of string to int failed for child node <Day> for TDate." << endl;
        }
    }
    else
        cout << "Warning: Child node <Day> for TDate not found" << endl;

    childNode = xmlGetChildByName(node, "Month");
    if (childNode != nullptr)
    {
        try
        {
            this->month = atoi((char*) xmlNodeGetContent(childNode));
            cout << "Month: " << this->month << endl;
        }
        catch (exception e)
        {
            cout << "Error: Conversion of string to int failed for child node <Month> for TDate." << endl;
        }
    }
    else
        cout << "Warning: Child node <Month> for TDate not found" << endl;

    childNode = xmlGetChildByName(node, "Year");
    if (childNode != nullptr)
    {
        try
        {
            this->year = atoi((char*) xmlNodeGetContent(childNode));
            cout << "Year: " << this->year << endl;
        }
        catch (exception e)
        {
            cout << "Error: Conversion of string to int failed for child node <Year> for TDate." << endl;
        }
    }
    else
        cout << "Warning: Child node <Year> for TDate not found" << endl;
}


void TDate::print()
{
    cout.fill('0');
    cout << setw(2) << day << '.' << setw(2) << month << '.' << year;
}
