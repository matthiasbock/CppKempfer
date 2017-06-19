
#include "tbook.h"


TBook::TBook(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node)
{
    // TODO
}


void TBook::print()
{
    cout << "Medientyp: Buch" << endl;
}
