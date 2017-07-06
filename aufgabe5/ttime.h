#ifndef TTIME_H
#define TTIME_H

#include "xml.h"


class TTime
{
    private:
        int hh, mm, ss;
        bool has_second = false;
        time_t now;
        string myTime;
        
    public:
        TTime();
        TTime(int hh, int mm);
        TTime(int hh, int mm, int ss);

        /**
         * @brief Create time object by parsing from XML
         * @param XML node to import
         */
        TTime(xmlNodePtr);

        ~TTime();

        friend ostream& operator<<(ostream&, TTime*);
        void print();

        int get_hh() const;
        int get_mm() const;
        int get_ss() const;
        void set_hh(int hh);
        void set_mm(int mm);
        void set_ss(int ss);
};

#endif
