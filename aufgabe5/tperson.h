
#ifndef TPERSON_H
#define TPERSON_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "xml.h"
#include "taddress.h"
#include "tdate.h"

using namespace std;


class TPerson
{
    protected:
        string Name;
        TAddress *Address;
        TDate *Birthday;
        
    public:
        // Uebung 3: TPerson darf keinen Standardkonstruktor enthalten
//        TPerson(): Name(""), Address(nullptr), Birthday(nullptr) {};

        TPerson(string, TAddress*, TDate*);

        /**
         * @brief Create TPerson by importing from XML node
         * @param XML node to import
         */
        TPerson(xmlNodePtr);

        virtual ~TPerson();

        void print();

        /*
         * getter and setter
         */

        string get_name() const;
        TAddress* get_address() const;
        TDate* get_birthday() const;

        void set_name(string);
        void set_address(TAddress*);
        void set_birthday(TDate*);
};

#endif
