
#ifndef TAUDIOBOOK_H
#define TAUDIOBOOK_H

#include <string>
#include <vector>
#include "xml.h"

#include "tmedium.h"

using namespace std;


class TAudioBook: public TMedium
{
  public:
    /**
     * @brief Create audiobook object by parsing from XML
     * @param XML node to import
     */
    TAudioBook(xmlNodePtr);

    void print();
};

#endif
