
#include "tperson.h"


TPerson::TPerson(string Name, TAddress *Address, TDate *Birthday)
:Name(Name),
 Address(Address),
 Birthday(Birthday)
{}


TPerson::TPerson(xmlNodePtr node)
:Name("undefined"),
 Address(),
 Birthday()
{
    xmlNodePtr childNode;

    this->Name = xmlGetString(node, "Name", "TPerson");

    childNode = xmlGetChildByName(node, "Address");
    if (childNode != nullptr)
    {
        cout << "Parsing TPerson's address:" << endl;
        this->Address = new TAddress(childNode);
    }
    else
        cout << "Warning: Child node <Address> for TPerson not found" << endl;

    childNode = xmlGetChildByName(node, "Birthday");
    if (childNode != nullptr)
    {
        cout << "Parsing TPerson's birthday:" << endl;
        this->Birthday = new TDate(childNode);
    }
    else
        cout << "Warning: Child node <Birthday> for TPerson not found" << endl;
}



TPerson::~TPerson()
{
    cout << "Deconstructing TPerson \"" << Name << "\"..." << endl;
}


void TPerson::print()
{
    cout << Name;
    cout << " *";
    Birthday->print();
    cout << endl;
    Address->print(); 
}


string TPerson::get_name() const {return Name;}
TAddress* TPerson::get_address() const {return Address;}
TDate* TPerson::get_birthday() const {return Birthday;}

void TPerson::set_name(string Name) {this->Name = Name;}
void TPerson::set_birthday(TDate* Birthday) {this->Birthday = Birthday;}
void TPerson::set_address(TAddress* Address) {this->Address = Address;}
