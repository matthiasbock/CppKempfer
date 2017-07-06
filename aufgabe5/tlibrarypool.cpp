// class TLibraryPool

#include "tlibrarypool.h"


TLibraryPool::TLibraryPool(string n, TCustomer* p)
:Name(n), Chairman(p) {}


TLibraryPool::TLibraryPool(string filename)
{
    loadFromFile(filename);
}


/**
 * @brief Operator overloading for cout output
 */
ostream& operator<<(ostream& out, TLibraryPool& librarypool)
{
    out << endl;
    out << librarypool.get_name() << endl;
    out << "Leitung: ";
    librarypool.Chairman->print();
    out << endl;
    out << "\nZum Buecherverband gehoeren " << librarypool.LibraryList.size() << " Filialen" << endl;
    for(unsigned i = 0; i < librarypool.LibraryList.size(); i++)
    {
        out << endl;
        librarypool.LibraryList.at(i)->print();
        out << endl;
    }
    out << endl;
    out << "Der Buecherverband hat " << librarypool.CustomerList.size() << " Kunde/Kunden" << endl;
    for(unsigned j = 0; j < librarypool.CustomerList.size(); j++)
    {
        out << endl;
        librarypool.CustomerList.at(j)->print();
    }
    out << endl;

    out << ANSI_PINK "##########################################################################################" ANSI_RESET << endl;

    return out;
}


void TLibraryPool::loadFromFile(string filename)
{
    cout << "Importing library pool from \"" << filename << "\"..." << endl;

    xml = xmlReadFile(filename.c_str(), NULL, XML_PARSE_NOBLANKS);
    loadFromXML(xmlDocGetRootElement(xml));

    cout << "Import completed." << endl << endl;

    cout << ANSI_PINK "##########################################################################################" ANSI_RESET << endl;
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
        cout << ANSI_YELLOW "Warning" ANSI_RESET ": Node <Chairman> for TLibraryPool not found" << endl;

    vector<xmlNodePtr> nodes;

    xmlGetChildrenByName(node, "Library", nodes);
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        this->LibraryList.push_back(new TLibrary(nodes[i]));
    }

    xmlGetChildrenByName(node, "Customer", nodes);
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        this->CustomerList.push_back(new TCustomer(nodes[i]));
    }

    xmlGetChildrenByName(node, "Loan", nodes);
    for (unsigned int i=0; i<nodes.size(); i++)
    {
        this->LoanList.push_back(new TLoan(this, nodes[i]));
    }

    return;
}


TLibraryPool::~TLibraryPool()
{
    cout << "Destructing TLibraryPool \"" << this->Name << "\"..." << endl;


    // delete loans before libraries, such that the mediums still exist
    for(unsigned i = 0; i < LoanList.size(); i++)
    {
        delete LoanList[i];
    }

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
    cout << *this;
}


TCustomer* TLibraryPool::getCustomerByNr(string CustomerNr)
{
    for (uint8_t i=0; i<CustomerList.size(); i++)
    {
        TCustomer *c = CustomerList[i];
        if (c != nullptr && c->get_customerNr().compare(CustomerNr) == 0)
        {
            // comparison is a match!
            return c;
        }
    }

    // search was unsuccessful
    return nullptr;
}


TMedium* TLibraryPool::getMediumBySignature(string Signature)
{
    for (uint8_t i=0; i<LibraryList.size(); i++)
    {
        TLibrary* library = LibraryList[i];
        if (library != nullptr)
        {
            TMedium* medium = library->getMediumBySignature(Signature);
            if (medium != nullptr)
            {
                // great success
                return medium;
            }
        }
    }

    // search was unsuccessful
    return nullptr;
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
