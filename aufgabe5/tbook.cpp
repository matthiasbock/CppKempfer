
#include "tbook.h"


TBook::TBook(xmlNodePtr node)
:TMedium(node)
{
    // TODO
}


void TBook::print()
{
    cout << "Medientyp: Buch" << endl;
}
