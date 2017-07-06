
#include "tloan.h"

TLoan::TLoan()
:Medium(nullptr),
 Customer(nullptr),
 LoanDate(nullptr),
 Expiration(nullptr)
{}


TLoan::TLoan(TLibrarypool mylibrarypool)
:Medium(nullptr),
 Customer(nullptr),
 LoanDate(nullptr),
 Expiration(nullptr),
 TLibrarypool(mylibrarypool)
{}

TMedium* TLoan::getMedium()
{
    return Medium;
}

void TLoan::setMedium(TMedium* m)
{
    Medium = m;
}

TPerson* TLoan::getCustomer()
{
    return Customer;
}

void TLoan::setCustomer(TPerson* p)
{
    Customer = p;
}

TDate* TLoan::getLoanDate()
{
    return LoanDate;
}

void TLoan::setLoanDate(TDate* d)
{
    LoanDate = d;
}

TDate* TLoan::getExpiration()
{
    return Expiration;
}

void TLoan::setExpiration(TDate* d)
{
    Expiration = d;
}

TLibrarypool* TLoan::getLibrarypool()
{
    return MyLibrarypool;
}

void TLoan::setLibrarypool(TLibrarypool* l)
{
    MyLibrarypool = l;
}

TLoan::TLoan(xmlNodePtr node)
{
   load(node);
}


void TLoan::load(xmlNodePtr node) {
 xmlNodePtr childNode;

    string signatur = xmlGetString(node, "Signatur", "TLoan");

    /* get CustomerNr function implementieren*/
    string customerNumber = xmlGetString(node, "CustomerNr", "TLoan");
    /* get CustomerNr function implementieren*/

    childNode = xmlGetChildByName(node, "LoanDate");

        if (childNode != nullptr)
        {
            cout << "Parsing loan date..." << endl;
        }
        else
            cout << "Warning: Node <LoanDate> for TLoan not found" << endl;

    int loanDays = xmlGetInt(node, "LoanDays", "TLoan");

    vector<xmlNodePtr> nodes;





}