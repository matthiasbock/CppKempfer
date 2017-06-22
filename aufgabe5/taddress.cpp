// class TAddresse

#include "taddress.h"


TAddress::TAddress(string Street, string Number, string Zipcode, string Town)
{
    this->Street = Street;
    this->Number = Number;
    this->Zipcode = Zipcode;
    this->Town = Town;
}


TAddress::TAddress(xmlNodePtr node)
{
    if (node != nullptr)
        load(node);
}


void TAddress::load(xmlNodePtr node)
{
    Street = xmlGetString(node, "Street", "TAddress");

    if (xmlHasChild(node, "HouseNr"))
        Number = xmlGetString(node, "HouseNr", "TAddress");
    else
        Number = xmlGetString(node, "Number", "TAddress");

    Zipcode = xmlGetString(node, "Zipcode", "TAddress");
    Town = xmlGetString(node, "Town", "TAddress");
}


TAddress::~TAddress()
{
    cout << "Deconstructing TAddress \"" << Street << " " << Number << "\"..." << endl;
}


void TAddress::print()
{
    cout << "Anschrift:" << endl;
    cout << Street << " " << Number << endl << Zipcode << " " << Town << endl;
}


string TAddress::get_street() const {return Street;}
string TAddress::get_number() const {return Number;}
string TAddress::get_zipcode() const {return Zipcode;}
string TAddress::get_town() const {return Town;}

void TAddress::set_street(string s) {Street = s;}
void TAddress::set_number(string n) {Number = n;}
void TAddress::set_zipcode(string z) {Zipcode = z;}
void TAddress::set_town(string t) {Town = t;}
