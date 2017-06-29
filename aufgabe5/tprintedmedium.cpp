
#include "tprintedmedium.h"


TPrintedMedium::TPrintedMedium(xmlNodePtr node)
:TMedium(node)
{
    Pages = xmlGetInt(node, "Pages", "TPrintedMedium");
}

void TPrintedMedium::print()
{

}

ostream& operator<<(ostream& out, TPrintedMedium& tprintedmedium)
{
    out << "Medientyp: Gedrucktes Medium" << endl;
    if (tprintedmedium.print_parents)
    {
        out << (TMedium&) tprintedmedium;
    }
    return out;
}


TPrintedMedium::~TPrintedMedium ()
{
    cout << "Destructing TPrintedMedium \"" << get_title() << "\"..." << endl;
}
