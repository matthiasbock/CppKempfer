
#include "tmagazine.h"


TMagazine::TMagazine(xmlNodePtr node)
:TMedium(node),
 TPrintedMedium(node)
{
    Designer = xmlGetString(node, "Designer", "TMagazine");
}


TMagazine::~TMagazine()
{
    cout << "Destructing TMagazine \"" << get_title() << "\"..." << endl;
}


void TMagazine::print(bool print_parents)
{
    cout << "Medientyp: Magazin" << endl;

    if (print_parents)
    {
        TPrintedMedium::print();
    }
}
