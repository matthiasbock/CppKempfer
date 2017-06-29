// class TTime

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

#include "ttime.h"

TTime::TTime()
{
    now = time(0);
    tm *ltm = localtime(&now);
    hh = ltm->tm_hour;
    mm = ltm->tm_min;
    ss = ltm->tm_sec;
    has_second = true;
}

TTime::TTime(int hh, int mm)
{
    this->hh = hh;
    this->mm = mm;
    ss = 0;
    has_second = false;
}

TTime::TTime(int hh, int mm, int ss)
{
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
    has_second = true;
}


TTime::TTime(xmlNodePtr node)
{
    load(node);
}

void TTime::load(xmlNodePtr node)
{
    hh = xmlGetInt(node, "Hour", "TTime");
    mm = xmlGetInt(node, "Minute", "TTime");

    has_second = true;
    ss = xmlGetInt(node, "Second", "TTime");
    if (ss < 0 || ss > 59)
        has_second = false;
}


TTime::~TTime()
{
    cout << "Destructing TTime..." << endl;
}

int TTime::get_hh() const
{
    return hh;
}


int TTime::get_mm() const
{ 
    return mm;
}

int TTime::get_ss() const
{
    return ss;
}

void TTime::set_hh(int hh)
{
    this->hh = hh;
}

void TTime::set_mm(int mm)
{
    this->mm = mm;
}

void TTime::set_ss(int ss)
{
    this->ss = ss;
}

void TTime::print()
{
    cout << setfill('0');
    cout << setw(2) << hh << ':' << setw(2) << mm;
    if (has_second)
    {
        cout << ':' << setw(2) << ss;
    }
}
