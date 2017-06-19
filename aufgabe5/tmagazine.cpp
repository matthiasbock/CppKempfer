
#include "tmagazine.h"


TMagazine::TMagazine(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node)
{
    Designer = xmlGetString(node, "Designer", "TMagazine");
}


void TMagazine::print()
{
    cout << "Medientyp: Magazin" << endl;
}
