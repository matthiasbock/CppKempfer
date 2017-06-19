
#ifndef TMAGAZINE_H
#define TMAGAZINE_H

#include <string>
#include <vector>
#include "xml.h"

#include "tprintedmedium.h"

using namespace std;


class TMagazine: public TPrintedMedium
{
  public:
    /**
     * @brief Create magazine object by parsing from XML
     * @param XML node to import
     */
    TMagazine(xmlNodePtr);

    void print();
};

#endif
