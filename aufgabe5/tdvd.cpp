
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
        PlayingTime->print();
        cout << endl;
    }
    else
        cout << "Warning: Child node <PlayingTime> for TDVD not found." << endl;

}


TDVD::~TDVD()
{
    cout << "Destructing TDVD \"" << get_title() << "\"..." << endl;

    if (PlayingTime != nullptr)
        delete PlayingTime;
}


void TDVD::print(bool print_parents)
{
    cout << "Medientyp: DVD" << endl;

    if (PlayingTime != nullptr)
    {
        cout << "Dauer:    ";
        PlayingTime->print();
        cout << endl;
    }


    if (print_parents)
    {
        TMedium::print();
    }
}
