// class TLibrary

#include "tlibrary.h"

TLibrary::TLibrary(string name, TAddress* address, TPerson* Person )
:Name(name), Address(address), Manager(Person) {}


TLibrary::TLibrary(ifstream& inFile)
{
    load(inFile);
}


TLibrary::TLibrary(xmlNodePtr node)
:Name(""),
 Address(),
 Manager(),
 MediumList()
{
    xmlNodePtr nodeName = xmlGetChildByName(node, "Name");
    if (nodeName != nullptr)
    {
        this->Name = string((char*) xmlNodeGetContent(nodeName));
        cout << "Library name: " << this->Name << endl;
    }
    else
        cout << "Warning: Node <Name> for TLibrary not found" << endl;
}


void TLibrary::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Name>", "<Address>", "<Manager>", "<Medium>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of Library to prevent any problems
        if (line.find("</Library>") != string::npos)
        {
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                    case 0:
                        Name = parseLine(line, tagToLookFor[i]);
                        break;
                    case 1:
                        Address = new TAddress(inFile);
                        break;                        
                    case 2:
                        Manager = new TPerson(inFile);
                        break;
                    case 3:
                        add(new TMedium(inFile));
                        break;                        
                    default:
                        cout << "Nothing found... in Library" << endl;
                        break;
                }
            }
        }
    }
}

string TLibrary::parseLine(string line, string tagToBeStriped)
{
    string tagEndBegin = "</";
    size_t tagStartPos = line.find(tagToBeStriped);
    int messageLength = line.length() - ((tagStartPos + 1) + (tagToBeStriped.length() * 2) + 1);
    int messageStart = tagStartPos+tagToBeStriped.length(); 
    return line.substr(messageStart, messageLength);
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
    cout << "Filialleister: ";
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
