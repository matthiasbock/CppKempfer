
#include "tprintedmedium.h"


TPrintedMedium::TPrintedMedium(xmlNodePtr node)
:TMedium(node)
{
    Pages = xmlGetInt(node, "Pages", "TPrintedMedium");
}


void TPrintedMedium::print(bool print_parents)
{
    cout << "Medientyp: Gedrucktes Medium" << endl;

    if (print_parents)
    {
        TMedium::print();
    }
}


TPrintedMedium::~TPrintedMedium ()
{
    cout << "Destructing TPrintedMedium \"" << get_title() << "\"..." << endl;
}
