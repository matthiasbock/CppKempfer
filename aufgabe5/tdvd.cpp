
#include "tdvd.h"


TDVD::TDVD (xmlNodePtr node)
:TMedium(node)
{
    // TODO
}


void TDVD::print()
{
    cout << "Medientyp: DVD" << endl;
}
