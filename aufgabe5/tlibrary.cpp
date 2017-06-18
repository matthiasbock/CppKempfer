// class TLibrary

#include "tlibrary.h"


TLibrary::TLibrary(string name, TAddress* address, TPerson* Person )
:Name(name),
 Address(address),
 Manager(Person)
{}


TLibrary::TLibrary(xmlNodePtr node)
:Name(""),
 Address(),
 Manager(),
 MediumList()
{
    this->Name = xmlGetString(node, "Name", "TLibrary");

    xmlNodePtr childNode;

    childNode = xmlGetChildByName(node, "Address");
    if (childNode != nullptr)
    {
        cout << "Parsing library address..." << endl;
        this->Address = new TAddress(childNode);
    }
    else
        cout << "Warning: Node <Address> for TLibrary not found" << endl;

    // TODO: Manager, Mediums
}


TLibrary::~TLibrary()
{
    for(unsigned i = 0; i < MediumList.size(); i++)
    {
        delete MediumList[i];
    }
    delete Address;
    delete Manager;
}


void TLibrary::add(TMedium *medium)
{
    MediumList.push_back(medium);
}


void TLibrary::print()
{
    cout << "Buecherei Filiale " << get_name() << endl;

    Address->print();

    cout << "Filialleiter: ";
    if (Manager != nullptr)
        Manager->print();
    else
        cout << "undefined";
    cout << endl;

    cout << "Es stehen " << MediumList.size() << " Medium/Medien zur Verfuegung:" << endl;
    for(unsigned i = 0; i < MediumList.size(); i++)
    {
        cout << endl;
        MediumList.at(i)->print();
        cout << endl;
    }
}


string TLibrary::get_name() const {return Name;}
TAddress* TLibrary::get_address() const {return Address;}
TPerson* TLibrary::get_manager() const {return Manager;}
