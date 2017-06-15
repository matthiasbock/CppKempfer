
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
    string tagToLookFor[] = {"<Name>", "<Birthday>", "<Address>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of person to prevent any problems
        if (line.find("</Person>") != string::npos)
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
                        break;
                    // find Birthday > create Birthday and let it load
                    case 1:
                        Birthday = new TDate(inFile);
                        break;
                    // find Address > create Address and let it load then add to vector
                    case 2:
                        Address = new TAddress(inFile);
                        break;
                    default:
                        cout << "Unsupported child node type for TEmployee: " << getXmlNodeType(line) << endl;
                        break;
                }
            }
        }
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
