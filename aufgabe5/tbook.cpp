
#include "tbook.h"


TBook::TBook(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node)
{
    Author = xmlGetString(node, "Author", "TBook");
}


TBook::~TBook()
{
    cout << "Deconstructing TBook \"" << get_title() << "\"..." << endl;
}


void TBook::print()
{
    cout << "Medientyp: Buch" << endl;
}
