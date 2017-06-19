
#ifndef TDVD_H
#define TDVD_H

#include <string>
#include <vector>
#include "xml.h"

#include "tmedium.h"

using namespace std;


class TDVD: public TMedium
{
  public:
    /**
     * @brief Create DVD object by parsing from XML
     * @param XML node to import
     */
    TDVD(xmlNodePtr);

    void print();
};

#endif
