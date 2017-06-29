
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


/**
 * @brief Operator overloading for cout output
 */
ostream& operator<<(ostream& out, TAudioBook& ab)
{
    out << "Medientyp: Hoerbuch" << endl;

    if (ab.print_parents)
    {
        ((TCD&) ab).print_parents = false;
        out << (TCD&) ab;
        ((TBook&) ab).print_parents = true;
        out << (TBook&) ab;
    }

    return out;
}


void TAudioBook::print()
{
    cout << *this;
}
