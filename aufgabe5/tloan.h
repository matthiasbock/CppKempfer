
#ifndef TLOAN_H
#define TLOAN_H

#include "tmedium.h"
#include "tcustomer.h"
#include "tdate.h"
#include "xml.h"
#include "tlibrarypool.h"

class TLoan
{
  private:
    TMedium *Medium;
    TPerson *Customer;
    TDate   *LoanDate;
    TDate   *Expiration;
    TLibraryPool *MyLibrarypool;

  public:
    TLoan();
    TLoan(TLibrarypool mylibrarypool);
    ~TLoan();

    TMedium* getMedium();
    void setMedium(TMedium*);

    TPerson* getCustomer();
    void setCustomer(TPerson*);

    TDate* getLoanDate();
    void setLoanDate(TDate*);

    TDate* getExpiration();
    void setExpiration(TDate*);

    TLibrarypool* getLibrarypool();
    void setLibrarypool(TLibrarypool*);


    TLoan(xmlNodePtr);
    void load(xmlNodePtr);
};

#endif
