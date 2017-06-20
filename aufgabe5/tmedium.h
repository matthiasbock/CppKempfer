#ifndef TMEDIUM_H
#define TMEDIUM_H

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#include "xml.h"
#include "tlocation.h"

using namespace std;

class TMedium
{
    public:
        enum Status {verfuegbar, ausgeliehen, bestellt, reserviert};

    private:
        string Title;
        string Signature;
        TLocation* Location;
        int FSK;
        Status status;
        void load(ifstream&);
        
    public:
        TMedium();
        TMedium(string, string, TLocation*, int, Status);
        TMedium(xmlNodePtr);

        virtual ~TMedium();

        void print();
        
        string get_status() const;
        string get_title() const;
        string get_signature() const;
        int get_FSK() const;

        void set_status(Status);
        void set_status(int);
        void set_title(string);
        void set_signature(string);
        void set_FSK(int);
        void set_location(TLocation*);

};

#endif
