
#include "tcd.h"


TCD::TCD (xmlNodePtr node)
:TMedium(node)
{
    // TODO
}


void TCD::print()
{
    cout << "Medientyp: CD-ROM" << endl;
}
