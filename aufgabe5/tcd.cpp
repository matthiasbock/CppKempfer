
#include "tcd.h"


TCD::TCD (xmlNodePtr node)
:TMedium(node)
{
    load(node);
}


void TCD::load(xmlNodePtr node)
{
    if (node == nullptr)
        return;

    Interpret = xmlGetString(node, "Interpret", "TCD");
    Tracks = xmlGetInt(node, "Tracks", "TCD");
}


TCD::~TCD()
{
    cout << "Destructing TCD \"" << get_title() << "\"..." << endl;
}


/**
 * @brief Operator overloading for cout output
 */
ostream& operator<<(ostream& out, TCD& cd)
{
    out << "Medientyp: CD-ROM" << endl;

    if (cd.print_parents)
    {
        out << (TMedium&) cd;
    }

    return out;
}


void TCD::print()
{
    cout << *this;
}
