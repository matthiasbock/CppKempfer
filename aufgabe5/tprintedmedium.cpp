
#include "tprintedmedium.h"


TPrintedMedium::TPrintedMedium(xmlNodePtr node)
:TMedium(node)
{
    Pages = xmlGetInt(node, "Pages", "TPrintedMedium");
}


void TPrintedMedium::print()
{
    cout << "Medientyp: Magazin" << endl;
}

