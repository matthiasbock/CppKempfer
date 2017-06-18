// class TCustomer
using namespace std;

#include "tcustomer.h"


TCustomer::TCustomer(xmlNodePtr node)
:TPerson(node),
 CustomerNr("undefined")
{
    xmlNodePtr childNode;

    childNode = xmlGetChildByName(node, "CustomerNr");
    if (childNode != nullptr)
    {
        this->CustomerNr = string((char*) xmlNodeGetContent(childNode));
        cout << "Customer number: " << this->CustomerNr << endl;
    }
    else
        cout << "Warning: Child node <CustomerNr> for TCustomer not found" << endl;
}


TCustomer::~TCustomer()
{
    cout << "Deconstructing TCustomer \"" << this->Name << "\"... " << endl;
}


void TCustomer::print()
{
	((TPerson*) this)->print();

	cout << "Customer number: " << this->CustomerNr << endl;
}
