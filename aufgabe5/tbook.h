
#ifndef TBOOK_H
#define TBOOK_H

#include <string>
#include <vector>
#include "xml.h"

#include "tprintedmedium.h"

using namespace std;


class TBook: virtual public TPrintedMedium
{
  public:
    /**
     * @brief Create book object by parsing from XML
     * @param XML node to import
     */
    TBook(xmlNodePtr);

    void print();
};

#endif
