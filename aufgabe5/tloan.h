
#ifndef TLOAN_H
#define TLOAN_H

#include "tmedium.h"
#include "tcustomer.h"
#include "tdate.h"
#include "xml.h"

#ifdef TLIBRARYPOOL_H
// forward declaration to break circular dependency
class TLibraryPool;
#else
#include "tlibrarypool.h"
#endif


class TLoan
{
  private:
    TMedium *Medium;
    TPerson *Customer;
    TDate   *LoanDate;
    TDate   *Expiration;
    TLibraryPool *myLibraryPool;

  public:
    TLoan();
    TLoan(TLibraryPool*);
    TLoan(xmlNodePtr);
    TLoan(TLibraryPool*, xmlNodePtr);
    ~TLoan();

    void load(xmlNodePtr);

    TMedium* getMedium();
    void setMedium(TMedium*);

    TPerson* getCustomer();
    void setCustomer(TPerson*);

    TDate* getLoanDate();
    void setLoanDate(TDate*);

    TDate* getExpiration();
    void setExpiration(TDate*);

    TLibraryPool* getLibraryPool();
    void setLibraryPool(TLibraryPool*);
};

#endif
