#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "tperson.h"
#include "tloan.h"

using namespace std;


class TCustomer: virtual public TPerson
{
    protected:
        string CustomerNr;

    public:
        /**
         * @brief Create TCustomer by importing from XML
         * @param XML node to import
         */
        TCustomer(xmlNodePtr);

        void load(xmlNodePtr);

        virtual ~TCustomer();

        /**
         * @brief Print summary about customer
         */
        virtual void print();

        string get_customerNr();
        void set_customerNr(string);
};

#endif
