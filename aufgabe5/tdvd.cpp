
#include "tdvd.h"


TDVD::TDVD (xmlNodePtr node)
:TMedium(node)
{
    xmlNodePtr childNode;

    Actors = xmlGetString(node, "Actors", "TDVD");

    childNode = xmlGetChildByName(node, "PlayingTime");
    if (childNode != nullptr)
    {
        cout << "TDVD.PlayingTime =" << endl;
        PlayingTime = new TTime(childNode);
    }
    else
        cout << "Warning: Child node <PlayingTime> for TDVD not found." << endl;

}


void TDVD::print()
{
    cout << "Medientyp: DVD" << endl;
}
