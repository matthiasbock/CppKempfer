
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

ostream& operator<<(ostream& out, TMagazine& tmagazine)
{
    out << "Medientyp: Magazin" << endl;

        if (tmagazine.print_parents)
        {
            out << (TMedium&) tmagazine;
        }
        return out;
}

void TMagazine::print()
{
    cout << *this;
}
