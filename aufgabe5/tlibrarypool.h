#ifndef TLIBRARYPOOL_H
#define TLIBRARYPOOL_H

#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

#include "xml.h"
#include "tdate.h"
#include "tlocation.h"
#include "taddress.h"
#include "tperson.h"
#include "tcustomer.h"
#include "temployee.h"
#include "tmedium.h"
#include "tlibrary.h"


class TLibraryPool
{
    private:
        string Name;
        TPerson *Chairman;
        vector<TLibrary*> LibraryList;
        vector<TCustomer*> CustomerList;
        vector<TEmployee*> EmployeeList;
        ifstream inFile;
        xmlDoc *xml = nullptr;

    public:
        /**
         * @brief Create library pool
         * @param Name of the library pool
         * @param Chairman of the library pool
         */
        TLibraryPool(string, TCustomer*);

        /**
         * @brief Create library pool by importing a file
         * @param Name of file to import
         */
        TLibraryPool(string);

        /**
         * @brief Create library pool by importing a file
         * @param Name of file to import
         */
        void loadFromFile(string);

        /**
         * @brief Create library pool by importing an XML element and it's child elements
         * @param Pointer to XML node to import
         */
        void loadFromXML(xmlNodePtr);

        /**
         * @brief Library pool destructor
         */
        ~TLibraryPool();

        /**
         * @brief Add a library to the pool
         * @param Pointer to library to add
         */
        void add(TLibrary*);

        /**
         * @brief Add a customer to the library pool
         * @param Pointer to customer to add
         */
        void add(TCustomer*);

        /**
         * @brief Grant output stream operator access to private class members
         */
        friend ostream& operator<<(ostream&, TLibraryPool&);

        /**
         * @brief Print a summary about this library pool
         */
        void print();

        /*
         * getter and setter
         */
        string get_name() const;
        TPerson* get_chairman() const;
        vector <TLibrary*> get_libraryList() const;
        vector <TCustomer*> get_customerList() const;

        void set_name(string);
        void set_chairman(TPerson*);
        void set_customerList(vector<TCustomer*>);
        void set_libraryList(vector<TLibrary*>);
};

#endif // TLIBRARYPOOL
