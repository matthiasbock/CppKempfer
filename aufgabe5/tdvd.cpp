
#include "tdvd.h"


TDVD::TDVD (xmlNodePtr node)
:TMedium(node)
{
    load(node);
}


void TDVD::load(xmlNodePtr node)
{
    if (node == nullptr)
        return;

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


TDVD::~TDVD()
{
    cout << "Deconstructing TDVD \"" << get_title() << "\"..." << endl;
}


void TDVD::print()
{
    cout << "Medientyp: DVD" << endl;

    TMedium::print();
}
