#ifndef TLIBRARY_H
#define TLIBRARY_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "xml.h"
#include "tdate.h"
#include "tlocation.h"
#include "taddress.h"
#include "temployee.h"

#include "tbook.h"
#include "tmagazine.h"
#include "tcd.h"
#include "tdvd.h"
#include "taudiobook.h"

class TLibrary
{
    private:
        string Name;
        TAddress *Address;
        TPerson *Manager;
        vector<TMedium*> MediumList;

    public:
        /**
         * @brief Construct empty library
         * @param Library name
         * @param Library address
         * @param Library manager
         */
        TLibrary(string, TAddress*, TPerson*);

        /**
         * @brief Construct library by importing XML element
         * @param XML <Library> node
         */
        TLibrary(xmlNodePtr);
        void load(xmlNodePtr);
        /**
         * @brief Deconstruct library
         */
        ~TLibrary();

        /**
         * @brief Print out a summary about this library
         */
        void print();

        /**
         * @brief Add a medium to this library
         * @param Medium to add to library
         */
        void add(TMedium*);


        /*
         * getter and setter
         */

        void setName(string);
        void setAddress(TAddress*);
        void setManager(TPerson*);
        void setMediumList(vector<TMedium*>);

        string get_name() const;
        TAddress* get_address() const;
        TPerson* get_manager() const;
        vector<TMedium*>getMediumList() const;
};

#endif // TLibrary_h
