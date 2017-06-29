
#ifndef TDVD_H
#define TDVD_H

#include <string>
#include <vector>
#include "xml.h"

#include "ttime.h"
#include "tmedium.h"

using namespace std;


class TDVD: public TMedium
{
  private:
    string Actors;
    TTime  *PlayingTime;

  public:
    /**
     * @brief Create DVD object by parsing from XML
     * @param XML node to import
     */
    TDVD(xmlNodePtr);

    void load(xmlNodePtr);

    ~TDVD();

    void print(bool print_parents = true);
};

#endif
