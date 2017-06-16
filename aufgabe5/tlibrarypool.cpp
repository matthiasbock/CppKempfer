// class TLibraryPool

#include "tlibrarypool.h"


TLibraryPool::TLibraryPool(string n, TCustomer* p)
:Name(n), Chairman(p) {}


TLibraryPool::TLibraryPool(xmlNodePtr node)
:Name(""),
 Chairman(nullptr)
{
    xmlNodePtr nodeName = xmlGetChildByName(node, "Name");
    if (nodeName != nullptr)
    {
        this->Name = string((char*) xmlNodeGetContent(nodeName));
        cout << "Library pool name: " << this->Name << endl;
    }
    else
        cout << "Warning: Node <Name> for TLibraryPool not found" << endl;

    xmlNodePtr nodeChairman = xmlGetChildByName(node, "Chairman");
    if (nodeChairman != nullptr)
    {
        cout << "Parsing chairman..." << endl;
        this->Chairman = new TEmployee(nodeChairman);
    }
    else
        cout << "Warning: Node <Chairman> for TLibraryPool not found" << endl;

    vector<xmlNodePtr> libraryNodes;
    xmlGetChildrenByName(node, "Library", libraryNodes);
    for (int i=0; i<libraryNodes.size(); i++)
    {
        this->LibraryList.push_back(new TLibrary(libraryNodes.at(i)));
    }

    vector<xmlNodePtr> customerNodes;
    xmlGetChildrenByName(node, "Customer", customerNodes);

    return;
}


TLibraryPool::~TLibraryPool()
{
    for(unsigned i = 0; i < LibraryList.size(); i++)
    {
        delete LibraryList[i];
    }
    for(unsigned i = 0; i < CustomerList.size(); i++)
    {
        delete CustomerList[i];
    }
    delete Chairman;
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
 * Getter
 */

string TLibraryPool::get_name() const {return Name;}
TPerson* TLibraryPool::get_chairman() const {return Chairman;}
vector<TCustomer*>TLibraryPool::get_customerList() const {return CustomerList;}
vector<TLibrary*>TLibraryPool::get_libraryList() const {return LibraryList;}

/*
 * Setter
 */

void TLibraryPool::set_name(string n) {Name = n;}
void TLibraryPool::set_chairman(TPerson* b) {Chairman = b;}
void TLibraryPool::set_customerList(vector<TCustomer*> cus) {CustomerList = cus;}
void TLibraryPool::set_libraryList(vector<TLibrary*>lib) {LibraryList = lib;}
