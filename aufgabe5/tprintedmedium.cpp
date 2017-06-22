
#include "tprintedmedium.h"


TPrintedMedium::TPrintedMedium(xmlNodePtr node)
:TMedium(node)
{
    Pages = xmlGetInt(node, "Pages", "TPrintedMedium");
}


void TPrintedMedium::print()
{
    cout << "Medientyp: Drucksache" << endl;

    TMedium::print();
}


TPrintedMedium::~TPrintedMedium ()
{
    cout << "Deconstructing TPrintedMedium \"" << get_title() << "\"..." << endl;
}
