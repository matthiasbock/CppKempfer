
#include "tcd.h"


TCD::TCD (xmlNodePtr node)
:TMedium(node)
{
    Interpret = xmlGetString(node, "Interpret", "TCD");
    Tracks = xmlGetInt(node, "Tracks", "TCD");
}


void TCD::print()
{
    cout << "Medientyp: CD-ROM" << endl;
}


TCD::~TCD()
{
    cout << "Deconstructing TCD \"" << get_title() << "\"..." << endl;
}
