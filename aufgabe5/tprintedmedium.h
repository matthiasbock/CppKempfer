
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
    bool print_parents = true;
  public:
    /**
     * @brief Create printed medium object by parsing from XML
     * @param XML node to import
     */
    TPrintedMedium(xmlNodePtr);

    ~TPrintedMedium();
    friend ostream& operator<<(ostream&, TPrintedMedium&);

    void print();
};

#endif

