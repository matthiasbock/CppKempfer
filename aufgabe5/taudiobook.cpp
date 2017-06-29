
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
    cout << "Destructing TAudioBook \"" << get_title() << "\"..." << endl;
}


void TAudioBook::print(bool print_parents)
{
    cout << "Medientyp: Hoerbuch" << endl;

    if (print_parents)
    {
        TCD::print(false);
        TBook::print();
    }
}
