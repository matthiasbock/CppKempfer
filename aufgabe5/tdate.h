
#ifndef TDATE_H
#define TDATE_H

#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

#include "xml.h"

using namespace std;


class TDate
{
    private:
        int day;
        int month;
        int year;
        
    public:
        /**
         * @brief Construct date object for today's date
         */
        TDate();

        /**
         * @brief Construct date object from date parameters
         */
        TDate(int dd, int mm, int yyyy);

        /**
         * @brief Construct date object by parsing XML
         * @param XML node to parse
         */
        TDate(xmlNodePtr);

        ~TDate();

        void load(xmlNodePtr);

        void print();

        /**
         * @brief Determines, whether the given year is a leap year
         * @param year Year to test
         * @retval true  Year argument is a leap year (366 days)
         * @retval false Year argument is not a leap year (365 days)
         */
        static bool isLeapYear(int);

        /**
         * @brief Returns the number of days in the given month of the given year
         * @param month Month to count the days of
         * @param year  Year, to check for leap years
         */
        static uint8_t daysPerMonth(int, int);

        /**
         * @brief Creates a new date object by \
         *        adding or subtracting a given number of days
         * @param days Number of days to add/subtract from date
         */
        TDate* operator+(int);

        //int get_dd() const;
        //int get_mm() const;
        //int get_yyyy() const;
        //void set_dd(int dd);
        //void set_mm(int mm);
        //void set_yyyy(int year);
};

#endif
