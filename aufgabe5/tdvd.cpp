
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


/**
 * @brief Operator overloading for cout output
 */
ostream& operator<<(ostream& out, TDVD& dvd)
{
    out << "Medientyp: DVD" << endl;

    if (dvd.PlayingTime != nullptr)
    {
        out << "Dauer:    " << dvd.PlayingTime << endl;
    }

    if (dvd.print_parents)
    {
        out << (TMedium&) dvd;
    }

    return out;
}


void TDVD::print()
{
    cout << *this;
}
