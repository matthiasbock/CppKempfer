
#include "tprintedmedium.h"


TPrintedMedium::TPrintedMedium(xmlNodePtr node)
:TMedium(node)
{
    Pages = xmlGetInt(node, "Pages", "TPrintedMedium");
}


void TPrintedMedium::print()
{
    cout << "Medientyp: Gedrucktes Medium" << endl;

    TMedium::print();
}


TPrintedMedium::~TPrintedMedium ()
{
    cout << "Destructing TPrintedMedium \"" << get_title() << "\"..." << endl;
}
