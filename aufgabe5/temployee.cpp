
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

#include "temployee.h"


/**
 * Initialize employee as TPerson + EmployeeNr
 */
TEmployee::TEmployee(
    string Name,
    TAddress *Address,
    TDate *Birthday,
    string EmployeeNr
    )
:TCustomer(),
 EmployeeNr(EmployeeNr)
{
    this->Name = Name;
    this->Address = Address;
    this->Birthday = Birthday;
};


/**
 * Initialize employee from file
 */
TEmployee::TEmployee(ifstream& inFile): TCustomer(inFile)
{
    load(inFile);
}


/**
 * Load employee from file
 */
void TEmployee::load(ifstream& inFile)
{
    cout << "Parsing TEmployee..." << endl;

    string tagToLookFor[] = {"<Name>", "<Birthday>", "<Address>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of person to prevent any problems
        if (line.find("</Employee>") != string::npos)
        {
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                     // find Pool name > save directly
                    case 0:
                        Name = getXmlNodeContent(line);
                        goto xmlNodeRecognized;
                        break;
                    // find Birthday > create Birthday and let it load
                    case 1:
                        Birthday = new TDate(inFile);
                        goto xmlNodeRecognized;
                        break;
                    // find Address > create Address and let it load then add to vector
                    case 2:
                        Address = new TAddress(inFile);
                        goto xmlNodeRecognized;
                        break;
                    default:
                        cout << "Alert: We should never arrive here." << endl;
                        break;
                }
            }
        }

        // we arrive here only, if no tag was recognized
        cout << "Warning: Child node for TCustomer not recognized: " << getXmlNodeType(line) << endl;

        xmlNodeRecognized:
        continue;
    }
}

TEmployee::~TEmployee()
{
    cout << "Employee \"" << Name << "\" destroyed." << endl;
}


/*
 * getter and setter
 */
string TEmployee::getEmployeeNr() {return EmployeeNr;}

void TEmployee::setEmployeeNr(string e) {this->EmployeeNr = e;}


void TEmployee::print()
{
    cout << Name;
    cout << " *";
    Birthday->print();
    cout << endl;
    Address->print(); 
}
