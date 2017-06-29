
#ifndef TAUDIOBOOK_H
#define TAUDIOBOOK_H

#include <string>
#include <vector>
#include "xml.h"

#include "tbook.h"
#include "tcd.h"

using namespace std;


class TAudioBook: public TBook, public TCD
{
  protected:
    int countCDs;
    bool print_parents = true;

  public:
    /**
     * @brief Create audiobook object by parsing from XML
     * @param XML node to import
     */
    TAudioBook(xmlNodePtr);

    void load(xmlNodePtr);

    ~TAudioBook();

    /**
     * @brief Grant output stream operator access to private class members
     */
    friend ostream& operator<<(ostream&, TAudioBook&);

    void print();
};

#endif
