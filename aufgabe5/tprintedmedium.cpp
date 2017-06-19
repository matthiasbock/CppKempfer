
#include "tprintedmedium.h"


TPrintedMedium::TPrintedMedium(xmlNodePtr node)
:TMedium(node)
{
    // TODO
}


void TPrintedMedium::print()
{
    cout << "Medientyp: Magazin" << endl;
}

