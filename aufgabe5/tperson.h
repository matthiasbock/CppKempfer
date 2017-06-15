#ifndef TPERSON_H
#define TPERSON_H

#include "taddress.h"
#include "tdate.h"

class TPerson
{
    protected:
        string parseLine(string, string);

        string Name;
        TAddress *Address;
        TDate *Birthday;
        void load(ifstream&);
        
    public:
        TPerson(string, TAddress*, TDate*);
        TPerson(ifstream&);
        ~TPerson();
        string get_name() const;
        TAddress* get_address() const;
        TDate* get_birthday() const;
        void set_name(string);
        void set_address(TAddress*);
        void set_birthday(TDate*);
        void print();
};

#endif
