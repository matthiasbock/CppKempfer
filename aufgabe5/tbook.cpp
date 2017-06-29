
#include "tbook.h"


TBook::TBook(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node)
{
    load(node);
}


void TBook::load(xmlNodePtr node)
{
    if (node == nullptr)
        return;

    Author = xmlGetString(node, "Author", "TBook");
}


TBook::~TBook()
{
    cout << "Destructing TBook \"" << get_title() << "\"..." << endl;
}


void TBook::print(bool print_parents)
{
    cout << "Medientyp: Buch" << endl;

    if (print_parents)
    {
        TMedium::print();
    }
}
