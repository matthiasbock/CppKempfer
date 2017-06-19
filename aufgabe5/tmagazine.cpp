
#include "tmagazine.h"


TMagazine::TMagazine(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node)
{
    // TODO
}


void TMagazine::print()
{
    cout << "Medientyp: Magazin" << endl;
}
