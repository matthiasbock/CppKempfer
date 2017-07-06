// class TCustomer

#include "tcustomer.h"


TCustomer::TCustomer(xmlNodePtr node)
:TPerson(node),
 CustomerNr("undefined")
{
    load(node);
}


void TCustomer::load(xmlNodePtr node)
{
    if (node == nullptr)
        return;

    CustomerNr = xmlGetString(node, "CustomerNr", "TCustomer");
}


TCustomer::~TCustomer()
{
    cout << "Destructing TCustomer \"" << this->Name << "\"... " << endl;
}


void TCustomer::print()
{
    TPerson::print();

    cout << "Kundennummer: " << this->CustomerNr << endl;
}


string TCustomer::get_customerNr()
{
    return CustomerNr;
}
