
#include "temployee.h"


TEmployee::TEmployee(xmlNodePtr node)
:TPerson(node),
 TCustomer(node),
 EmployeeNr("undefined")
{
    this->EmployeeNr = xmlGetString(node, "EmployeeNr", "TEmployee");
}


TEmployee::~TEmployee()
{
    cout << "Deconstructing TEmployee \"" << Name << "\"..." << endl;
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
