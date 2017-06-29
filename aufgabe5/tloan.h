
#ifndef TLOAN_H
#define TLOAN_H

#include "tmedium.h"
#include "tcustomer.h"
#include "tdate.h"


class TLoan
{
  private:
    TMedium *Medium;
    TPerson *Customer;
    TDate   *LoanDate;
    TDate   *Expiration;

  public:
    TLoan();
    ~TLoan();

    TMedium* getMedium();
    void setMedium(TMedium*);

    TPerson* getCustomer();
    void setCustomer(TPerson*);

    TDate* getLoanDate();
    void setLoanDate(TDate*);

    TDate* getExpiration();
    void setExpiration(TDate*);
};

#endif
