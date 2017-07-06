
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

    string customerNumber = xmlGetString(node, "CustomerNr", "TLoan");
    Customer = myLibraryPool->getCustomerByNr(customerNumber);

    string signatur = xmlGetString(node, "Signatur", "TLoan");
    Medium = myLibraryPool->getMediumBySignature(signatur);

    childNode = xmlGetChildByName(node, "LoanDate");
    if (childNode != nullptr)
    {
        LoanDate = new TDate(childNode);
    }
    else
        cout << ANSI_YELLOW "Warning" ANSI_RESET ": Node <LoanDate> for TLoan not found" << endl;

    int loanDays = xmlGetInt(node, "LoanDays", "TLoan");
//    Expiration = &((*LoanDate) + loanDays);
}


TLoan::~TLoan()
{
    cout << "Destructing TLoan for medium \"" << this->Medium->get_title() << "\"..." << endl;
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
