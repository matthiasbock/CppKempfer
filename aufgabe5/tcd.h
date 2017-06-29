
#ifndef TCD_H
#define TCD_H

#include <string>
#include <vector>
#include "xml.h"

#include "tmedium.h"

using namespace std;


class TCD: virtual public TMedium
{
  private:
    string Interpret;
    int Tracks;

  public:
    bool print_parents = true;

    /**
     * @brief Create CD object by parsing from XML
     * @param XML node to import
     */
    TCD(xmlNodePtr);

    void load(xmlNodePtr);

    virtual ~TCD();

    /**
     * @brief Grant output stream operator access to private class members
     */
    friend ostream& operator<<(ostream&, TCD&);

    void print();
};

#endif
