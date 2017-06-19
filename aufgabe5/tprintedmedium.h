
#ifndef TPRINTEDMEDIUM_H
#define TPRINTEDMEDIUM_H

#include <string>
#include <vector>
#include "xml.h"

#include "tmedium.h"

using namespace std;


class TPrintedMedium: virtual public TMedium
{
  private:
    int Pages;

  public:
    /**
     * @brief Create printed medium object by parsing from XML
     * @param XML node to import
     */
    TPrintedMedium(xmlNodePtr);

    void print();
};

#endif

