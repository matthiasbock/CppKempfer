
#include "taudiobook.h"


TAudioBook::TAudioBook(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node),
 TBook(node),
 TCD(node)
{
    countCDs = xmlGetInt(node, "countCDs", "TAudioBook");
}


TAudioBook::~TAudioBook()
{
    cout << "Deconstructing audiobook \"" << get_title() << "\"..." << endl;
}


void TAudioBook::print()
{
    cout << "Medientyp: Hoerbuch" << endl;
}
