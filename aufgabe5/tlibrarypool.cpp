// class TLibraryPool

#include "tlibrarypool.h"


TLibraryPool::TLibraryPool(string n, TCustomer* p)
:Name(n), Chairman(p) {}


TLibraryPool::TLibraryPool(string filename)
{
    loadFromFile(filename);
}


void TLibraryPool::loadFromFile(string filename)
{
    cout << "Importing library pool from \"" << filename << "\"..." << endl;

    xml = xmlReadFile(filename.c_str(), NULL, XML_PARSE_NOBLANKS);
    loadFromXML(xmlDocGetRootElement(xml));

    cout << "Import completed." << endl << endl;
}


void TLibraryPool::loadFromXML(xmlNodePtr node)
{
    xmlNodePtr childNode;

    Name = xmlGetString(node, "Name", "TLibraryPool");

    childNode = xmlGetChildByName(node, "Chairman");
    if (childNode != nullptr)
    {
        cout << "Parsing chairman..." << endl;
        this->Chairman = new TEmployee(childNode);
    }
    else
        cout << "Warning: Node <Chairman> for TLibraryPool not found" << endl;

    vector<xmlNodePtr> nodes;

    xmlGetChildrenByName(node, "Library", nodes);
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        this->LibraryList.push_back(new TLibrary(nodes.at(i)));
    }

    xmlGetChildrenByName(node, "Customer", nodes);
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        this->CustomerList.push_back(new TCustomer(nodes.at(i)));
    }

    return;
}


TLibraryPool::~TLibraryPool()
{
    cout << "Deconstructing TLibraryPool \"" << this->Name << "\"..." << endl;

    // free sub-objects
    for(unsigned i = 0; i < LibraryList.size(); i++)
    {
        delete LibraryList[i];
    }
    for(unsigned i = 0; i < CustomerList.size(); i++)
    {
        delete CustomerList[i];
    }
    delete Chairman;

    // free XML document
    if (this->xml != nullptr)
    {
        xmlFreeDoc(this->xml);
        xmlCleanupParser();
    }
}


void TLibraryPool::add(TCustomer* customer)
{
    CustomerList.push_back(customer);
}


void TLibraryPool::add(TLibrary* lib)
{
    LibraryList.push_back(lib);
}


void TLibraryPool::print()
{
    cout << endl;
    cout << get_name() << endl;
    cout << "Leitung: ";
    Chairman->print();
    cout << endl;
    cout << "\nZum Buecherverband gehoeren " << LibraryList.size() << " Filialen" << endl;
    for(unsigned i = 0; i < LibraryList.size(); i++)
    {
        cout << endl;
        LibraryList.at(i)->print();
        cout << endl;
    }
    cout << endl;
    cout << "Der Buecherverband hat " << CustomerList.size() << " Kunde/Kunden" << endl;
    for(unsigned j = 0; j < CustomerList.size(); j++)
    {
        cout << endl;
        CustomerList.at(j)->print();
    }
    cout << endl;
}


/*
 * getter and setter
 */

string TLibraryPool::get_name() const {return Name;}
TPerson* TLibraryPool::get_chairman() const {return Chairman;}
vector<TCustomer*>TLibraryPool::get_customerList() const {return CustomerList;}
vector<TLibrary*>TLibraryPool::get_libraryList() const {return LibraryList;}

void TLibraryPool::set_name(string n) {Name = n;}
void TLibraryPool::set_chairman(TPerson* b) {Chairman = b;}
void TLibraryPool::set_customerList(vector<TCustomer*> cus) {CustomerList = cus;}
void TLibraryPool::set_libraryList(vector<TLibrary*>lib) {LibraryList = lib;}
