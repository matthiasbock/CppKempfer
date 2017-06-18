#ifndef TADDRESS_H
#define TADDRESS_H

#include <fstream>
#include <iostream>
#include <string>
#include "xml.h"

using namespace std;


class TAddress
{
    private:
        string Street;
        string Number;
        string Zipcode;
        string Town;

    public:
        TAddress(string, string, string, string);
        TAddress(xmlNodePtr);

        string get_street() const;
        string get_number() const;
        string get_zipcode() const;
        string get_town() const;
        void set_street(string);
        void set_number(string);
        void set_zipcode(string);
        void set_town(string);
        void print();
};

#endif
