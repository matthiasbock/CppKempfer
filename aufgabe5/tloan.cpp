
#include "tloan.h"
#include "tlibrarypool.h"
TLoan::TLoan()
:Medium(nullptr),
 Customer(nullptr),
 LoanDate(nullptr),
 Expiration(nullptr),
 myLibraryPool(nullptr)
{}


TLoan::TLoan(TLibraryPool* mylibrarypool)
:Medium(nullptr),
 Customer(nullptr),
 LoanDate(nullptr),
 Expiration(nullptr),
 myLibraryPool(mylibrarypool)
{}


TLoan::TLoan(xmlNodePtr node)
{
   load(node);
}


TLoan::TLoan(TLibraryPool* librarypool, xmlNodePtr node)
{
    myLibraryPool = librarypool;
    load(node);
}


void TLoan::load(xmlNodePtr node) {
 xmlNodePtr childNode;

    string signatur = xmlGetString(node, "Signatur", "TLoan");
    string customerNumber = xmlGetString(node, "CustomerNr", "TLoan");
    TCustomer* customernr = myLibraryPool->getCustomerByNr(customerNumber);
    TMedium* mediumSignature = myLibraryPool->getMediumBySignature(signatur);

    childNode = xmlGetChildByName(node, "LoanDate");

        if (childNode != nullptr)
        {
            cout << "Parsing loan date..." << endl;
        }
        else
            cout << "Warning: Node <LoanDate> for TLoan not found" << endl;

    int loanDays = xmlGetInt(node, "LoanDays", "TLoan");
}


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


TLibraryPool* TLoan::getLibraryPool()
{
    return myLibraryPool;
}


void TLoan::setLibraryPool(TLibraryPool* l)
{
    myLibraryPool = l;
}
