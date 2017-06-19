
#include "tbook.h"


TBook::TBook(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node)
{
    Author = xmlGetString(node, "Author", "TBook");
}


void TBook::print()
{
    cout << "Medientyp: Buch" << endl;
}
