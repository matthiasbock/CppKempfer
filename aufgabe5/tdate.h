
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

        //int get_dd() const;
        //int get_mm() const;
        //int get_yyyy() const;
        //void set_dd(int dd);
        //void set_mm(int mm);
        //void set_yyyy(int year);
};

#endif
