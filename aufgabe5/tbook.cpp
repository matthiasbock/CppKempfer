
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


/**
 * @brief Operator overloading for cout output
 */
ostream& operator<<(ostream& out, TBook& book)
{
    out << "Medientyp: Buch" << endl;

    if (book.print_parents)
    {
        out << (TMedium&) book;
    }

    return out;
}


void TBook::print()
{
    cout << *this;
}
