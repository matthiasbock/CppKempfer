
#include "taudiobook.h"


TAudioBook::TAudioBook(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node),
 TBook(node),
 TCD(node)
{
    load(node);
}


void TAudioBook::load(xmlNodePtr node)
{
    if (node == nullptr)
        return;

    countCDs = xmlGetInt(node, "countCDs", "TAudioBook");
}


TAudioBook::~TAudioBook()
{
    cout << "Deconstructing TAudioBook \"" << get_title() << "\"..." << endl;
}


void TAudioBook::print()
{
    cout << "Medientyp: Hoerbuch" << endl;

    TCD::print(false);
    TBook::print();
}
