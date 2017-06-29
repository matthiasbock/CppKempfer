
#include "temployee.h"


TEmployee::TEmployee(xmlNodePtr node)
:TPerson(node),
 TCustomer(node),
 EmployeeNr("undefined")
{
    load(node);
}


void TEmployee::load(xmlNodePtr node)
{
    if (node == nullptr)
        return;

    EmployeeNr = xmlGetString(node, "EmployeeNr", "TEmployee");
}


TEmployee::~TEmployee()
{
    cout << "Destructing TEmployee \"" << Name << "\"..." << endl;
}


void TEmployee::print()
{
    TCustomer::print();

    cout << "Angestelltennummer: " << EmployeeNr << endl;
}


/*
 * getter and setter
 */

string TEmployee::getEmployeeNr() {return EmployeeNr;}

void TEmployee::setEmployeeNr(string e) {this->EmployeeNr = e;}
