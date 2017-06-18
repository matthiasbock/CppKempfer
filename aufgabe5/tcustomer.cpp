// class TCustomer

#include "tcustomer.h"


TCustomer::TCustomer(xmlNodePtr node)
:TPerson(node),
 CustomerNr("undefined")
{
    this->CustomerNr = xmlGetString(node, "CustomerNr", "TCustomer");
}


TCustomer::~TCustomer()
{
    cout << "Deconstructing TCustomer \"" << this->Name << "\"... " << endl;
}


void TCustomer::print()
{
	((TPerson*) this)->print();

	cout << "Kundennummer: " << this->CustomerNr << endl;
}
