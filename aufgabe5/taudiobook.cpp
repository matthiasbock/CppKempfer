
#include "taudiobook.h"


TAudioBook::TAudioBook(xmlNodePtr node)
:TMedium(node)
{
    // TODO
}


void TAudioBook::print()
{
    cout << "Medientyp: Hoerbuch" << endl;
}
