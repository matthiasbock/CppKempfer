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
    string tagToLookFor[] = {"<Name>", "<Address>", "<Manager>", "<Medium>"};

    xmlNodePtr nodeName = xmlGetChildByName(node, "Name");
    if (nodeName != nullptr)
    {
        this->Name = string((char*) xmlNodeGetContent(nodeName));
        cout << "Library name: " << this->Name << endl;
    }
    else
        cout << "Warning: Node <Name> for TLibrary not found" << endl;
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
    Address->print(); cout << endl;
    cout << "Filialleiter: ";
    Manager->print();
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
