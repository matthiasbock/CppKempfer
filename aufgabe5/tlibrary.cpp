// class TLibrary

#include "tlibrary.h"


TLibrary::TLibrary(string name, TAddress* address, TPerson* Person )
:Name(name),
 Address(address),
 Manager(Person)
{}


TLibrary::TLibrary(xmlNodePtr node)
:MediumList()
{
   load(node);
}

void TLibrary::load(xmlNodePtr node) {
 xmlNodePtr childNode;

    Name = xmlGetString(node, "Name", "TLibrary");

    childNode = xmlGetChildByName(node, "Address");
    if (childNode != nullptr)
    {
        cout << "Parsing library address..." << endl;
        Address = new TAddress(childNode);
    }
    else
        cout << "Warning: Node <Address> for TLibrary not found" << endl;

    childNode = xmlGetChildByName(node, "Manager");
    if (childNode != nullptr)
    {
        cout << "Parsing library manager..." << endl;
        Manager = new TEmployee(childNode);
    }
    else
        cout << "Warning: Node <Address> for TLibrary not found" << endl;

    vector<xmlNodePtr> nodes;
    MediumList.clear();

    xmlGetChildrenByName(node, "Book", nodes);
    cout << "Found " << nodes.size() << " books." << endl;
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        MediumList.push_back(new TBook(nodes.at(i)));
    }

    xmlGetChildrenByName(node, "Magazine", nodes);
    cout << "Found " << nodes.size() << " magazines." << endl;
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        MediumList.push_back(new TMagazine(nodes.at(i)));
    }

    xmlGetChildrenByName(node, "CD", nodes);
    cout << "Found " << nodes.size() << " CDs." << endl;
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        MediumList.push_back(new TCD(nodes.at(i)));
    }

    xmlGetChildrenByName(node, "DVD", nodes);
    cout << "Found " << nodes.size() << " DVDs." << endl;
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        MediumList.push_back(new TDVD(nodes.at(i)));
    }

    xmlGetChildrenByName(node, "Audiobook", nodes);
    cout << "Found " << nodes.size() << " audiobooks." << endl;
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        MediumList.push_back(new TAudioBook(nodes.at(i)));
    }
}

TLibrary::~TLibrary()
{
    cout << "Destructing TLibrary \"" << Name << "\"..." << endl;

    for(unsigned i = 0; i < MediumList.size(); i++)
        if (MediumList.at(i) != nullptr)
            delete MediumList.at(i);
    if (Address)
        delete Address;
    if (Manager)
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
    {
        cout << endl;
        Manager->print();
    }
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


TMedium* TLibrary::getMediumBySignature(string Signature)
{
    for (uint16_t i=0; i<MediumList.size(); i++)
    {
        TMedium* medium = MediumList[i];
        if (medium != 0 && medium->get_signature().compare(Signature) == 0)
        {
            // great success
            return medium;
        }
    }

    // search unsuccessful
    return nullptr;
}


string TLibrary::get_name() const {return Name;}
TAddress* TLibrary::get_address() const {return Address;}
TPerson* TLibrary::get_manager() const {return Manager;}
