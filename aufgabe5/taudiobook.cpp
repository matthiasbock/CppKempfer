
#include "taudiobook.h"


TAudioBook::TAudioBook(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node),
 TBook(node),
 TCD(node)
{
    // TODO
}


void TAudioBook::print()
{
    cout << "Medientyp: Hoerbuch" << endl;
}
