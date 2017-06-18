// class TLocation

#include "tlocation.h"


TLocation::TLocation()
{
    section = "Buero";
    rack = "Fach zum Einsortieren";
}


TLocation::TLocation(string section, string rack)
{
    this->section = section;
    this->rack = rack;
}


TLocation::TLocation(xmlNodePtr node)
{
    section = xmlGetString(node, "Section", "TLocation");
    rack = xmlGetString(node, "Rack", "TLocation");
}


void TLocation::print()
{
    cout << "Abt.: " << section << "; " << "Regal: " << rack;
}


string TLocation::get_section() const
{
    return section;
}
string TLocation::get_rack() const
{
    return rack;
}

void TLocation::set_section(string section)
{
    this->section = section;
}

void TLocation::set_rack(string section)
{
    this->rack = rack;
}

