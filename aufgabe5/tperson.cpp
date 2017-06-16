// class TPerson

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

#include "tperson.h"

TPerson::TPerson(string Name, TAddress* Address, TDate*Birthday)
:Name(Name), Address(Address), Birthday(Birthday) {}

TPerson::TPerson(ifstream& inFile)
{
    load(inFile);
}


TPerson::TPerson(xmlNodePtr node)
:Name("undefined"),
 Address(),
 Birthday()
{
    xmlNodePtr childName = xmlGetChildByName(node, "Name");
    if (childName != nullptr)
    {
        this->Name = string((char*) xmlNodeGetContent(childName));
        cout << "Person's name: " << this->Name << endl;
    }
    else
        cout << "Warning: Child node <Name> for TPerson not found" << endl;

    xmlNodePtr childAddress = xmlGetChildByName(node, "Address");
    if (childAddress != nullptr)
    {
        cout << "Person's address:" << endl;
        this->Address = new TAddress(childAddress);
    }
    else
        cout << "Warning: Child node <Address> for TPerson not found" << endl;
}


void TPerson::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Name>", "<Birthday>", "<Address>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of person to prevent any problems
        if (line.find("</Person>") != string::npos)
        {
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                     // find Pool name > save directly
                    case 0:
                        Name = getXmlNodeContent(line);
                        break;
                    // find Birthday > create Birthday and let it load
                    case 1:
                        Birthday = new TDate(inFile);
                        break;
                    // find Address > create Address and let it load then add to vector
                    case 2:
                        Address = new TAddress(inFile);
                        break;
                    default:
                        cout << "Unrecognized node type for TPerson: " << getXmlNodeType(line) << endl;
                        break;
                }
            }
        }
    }
}

TPerson::~TPerson()
{
    cout << "Die Person " << Name << " wird vernichtet!" << endl;
}

string TPerson::get_name() const {return Name;}
TAddress* TPerson::get_address() const {return Address;}
TDate* TPerson::get_birthday() const {return Birthday;}

void TPerson::set_name(string Name) {this->Name = Name;}
void TPerson::set_birthday(TDate* Birthday) {this->Birthday = Birthday;}
void TPerson::set_address(TAddress* Address) {this->Address = Address;}

void TPerson::print()
{
    cout << Name;
    cout << " *";
    Birthday->print();
    cout << endl;
    Address->print(); 
}
