// class TMedium

#include "tmedium.h"


TMedium::TMedium(string Name, string Signature, TLocation* Location, int FSK, Status status)
:Title(Name), Signature(Signature), Location(Location), FSK(FSK)
{
    set_status(status);
}


TMedium::TMedium(xmlNodePtr node)
{
    Title = xmlGetString(node, "Title", "TMedium");
    Signature = xmlGetString(node, "Signature", "TMedium");
    FSK = xmlGetInt(node, "FSK", "TMedium");
    set_status( xmlGetInt(node, "Status", "TMedium") );

    xmlNodePtr childNode;
    childNode = xmlGetChildByName(node, "Location");
    if (childNode != nullptr)
    {
        Location = new TLocation(childNode);
    }
    else
        cout << "Warning: Node <Location> for TMedium not found" << endl;
}


TMedium::~TMedium()
{
    cout << "Das Medium " << Title << " mit der Signatur " << Signature << " wird vernichtet!" << endl;
}


void TMedium::print()
{
    //char tmp = cout.fill();
    cout.fill(' ');
    cout << setw(10) << left << "Titel: "<< get_title() << endl;
    cout << setw(10) << left << "Signatur: " << get_signature() << endl;
    cout << setw(10) << left << "Ort:"; Location->print(); cout << endl;
    cout << setw(10) << left << "FSK:" << "freigegeben ab " << get_FSK() << " Jahren" << endl;
    cout << setw(10) << left << "Status: " << get_status();
}


void TMedium::set_status(int statusInt)
{
    switch(statusInt)
    {
        case 0:
            status = TMedium::verfuegbar;
            break;
        case 1:
            status = TMedium::ausgeliehen;
            break;
        case 2:
            status = TMedium::bestellt;
            break;
        case 3:
            status = TMedium::reserviert;
            break;            
        default:
            cout << "Nothing found... in status" << endl;
            break;
    }
}


string TMedium::get_status() const
{
    switch(status)
    {
        case bestellt:
            return "bestellt";
        case verfuegbar:
            return "verfuegbar";
        case reserviert:
            return "reserviert";
        case ausgeliehen:
            return "ausgeliehen";
        default:
            return "not defined";
    }
}


string TMedium::get_title() const { return Title; }
string TMedium::get_signature() const {return Signature;}
int TMedium::get_FSK() const {return FSK;}

void TMedium::set_status(Status st) {status = st;}
void TMedium::set_title(string n) { Title = n; }
void TMedium::set_signature(string s) { Signature = s; }
void TMedium::set_FSK(int age) { FSK = age;}
void TMedium::set_location(TLocation* location) { Location = location; }
