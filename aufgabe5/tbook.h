
#ifndef TBOOK_H
#define TBOOK_H

#include <string>
#include <vector>
#include "xml.h"

#include "tprintedmedium.h"

using namespace std;


class TBook: virtual public TPrintedMedium
{
  private:
    string Author;

  public:
    /**
     * @brief Create book object by parsing from XML
     * @param XML node to import
     */
    TBook(xmlNodePtr);

    void load(xmlNodePtr);

    ~TBook();

    void print(bool print_parents = true);
};

#endif
