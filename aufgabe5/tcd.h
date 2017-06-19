
#ifndef TCD_H
#define TCD_H

#include <string>
#include <vector>
#include "xml.h"

#include "tmedium.h"

using namespace std;


class TCD: virtual public TMedium
{
  public:
    /**
     * @brief Create CD object by parsing from XML
     * @param XML node to import
     */
    TCD(xmlNodePtr);

    void print();
};

#endif
