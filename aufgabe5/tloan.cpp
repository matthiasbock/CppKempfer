
#include "tloan.h"

TLoan::TLoan()
:Medium(nullptr),
 Customer(nullptr),
 LoanDate(nullptr),
 Expiration(nullptr)
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
