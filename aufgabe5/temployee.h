/**
 * Class TEmployee
 *
 * An employee works for a library,
 * is itself a person (base class TPerson),
 * but can also loan mediums and
 * is therefore also a customer (base class TCustomer).
 */

#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H

#include "xml.h"

#include "taddress.h"
#include "tdate.h"
#include "tperson.h"
#include "tcustomer.h"

class TEmployee: public TCustomer
{
    protected:
        string EmployeeNr;
        
    public:
        TEmployee(string, TAddress*, TDate*, string);
        TEmployee(ifstream&);
        ~TEmployee();

        // load from file stream
        void load(ifstream&);

        // getter and setter
        string getEmployeeNr();
        void setEmployeeNr(string);

        void print();
};

#endif
