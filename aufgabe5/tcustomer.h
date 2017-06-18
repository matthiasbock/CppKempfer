#ifndef TCUSTOMER_H
#define TCUSTOMER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "tperson.h"

class TCustomer: public TPerson
{
    protected:
        string CustomerNr;

    private:
        void load(ifstream&);

    public:
        /**
         * @brief Create TCustomer by importing from XML
         * @param XML node to import
         */
        TCustomer(xmlNodePtr);

        ~TCustomer();

        /**
         * @brief Print summary about customer
         */
        void print();

        string get_customerNr() const;
        void set_customerNr(string);
};

#endif
