
#include "temployee.h"


TEmployee::TEmployee(xmlNodePtr node)
:TCustomer(node),
 EmployeeNr("undefined")
{
    xmlNodePtr childNode;

    childNode = xmlGetChildByName(node, "EmployeeNr");
    if (childNode != nullptr)
    {
        this->EmployeeNr = string((char*) xmlNodeGetContent(childNode));
        cout << "Employee number: " << this->EmployeeNr << endl;
    }
    else
        cout << "Warning: Child node <EmployeeNr> for TEmployee not found" << endl;
}


TEmployee::~TEmployee()
{
    cout << "Deconstructing TEmployee \"" << Name << "\"..." << endl;
}


void TEmployee::print()
{
    cout << Name;
    cout << " *";
    Birthday->print();
    cout << endl;
    Address->print(); 
}


/*
 * getter and setter
 */

string TEmployee::getEmployeeNr() {return EmployeeNr;}

void TEmployee::setEmployeeNr(string e) {this->EmployeeNr = e;}
