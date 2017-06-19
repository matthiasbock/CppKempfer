
#include "tmagazine.h"


TMagazine::TMagazine(xmlNodePtr node)
:TMedium(node)
{
    // TODO
}


void TMagazine::print()
{
    cout << "Medientyp: Magazin" << endl;
}
