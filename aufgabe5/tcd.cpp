
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
    cout << "Deconstructing TCD \"" << get_title() << "\"..." << endl;
}


void TCD::print(bool print_parents)
{
    cout << "Medientyp: CD-ROM" << endl;

    if (print_parents)
    {
        TMedium::print();
    }
}
