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
        this->Name = string((char*) xmlNodeGetContent(nodeName));
    else
        cout << "Warning: Node <Name> for TLibraryPool not found" << endl;

    xmlNodePtr nodeChairman = xmlGetChildByName(node, "Chairman");
    if (nodeChairman != nullptr)
        this->Chairman = new TEmployee(nodeChairman);
    else
        cout << "Warning: Node <Chairman> for TLibraryPool not found" << endl;

    return;

    string tagToLookFor[] = {"<Name>", "<Chairman>", "<Library>", "<Customer>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;

    // to be sure if file is found and is opened
    if (inFile.is_open())
    {
        // search for beginning of library pool
        do
            if (!getline(inFile, line))
            {
                cout << "Error parsing XML: <LibraryPool> node not found" << endl;
                return;
            }
        while (line.find("<LibraryPool>") < 0);
        cout << "Parsing LibraryPool..." << endl;

        // parse the following lines until end tag
        while (getline(inFile, line))
        {
            // detect end of XML node
            if (line.find("</LibraryPool>") != string::npos)
            {
                cout << "Encountered end of LibraryPool XML node." << endl;
                break;
            }

            // parse all the tags
            for(int i = 0; i < maxTag; i++)
            {
                // tag found ?
                if (line.find(tagToLookFor[i]) != string::npos )
                {
                    switch(i)
                    {
                         // find Pool name > save directly
                        case 0:
                            Name = getXmlNodeContent(line);
                            goto xmlNodeRecognized;
                            break;
                        // find Chairman > create TCustomer and let it load
                        case 1:
                            Chairman = new TEmployee(inFile);
                            goto xmlNodeRecognized;
                            break;
                        // find Library > create TCustomer and let it load then add to vector
                        case 2:
                            add(new TLibrary(inFile));
                            goto xmlNodeRecognized;
                            break;
                        case 3:
                            add(new TCustomer(inFile));
                            goto xmlNodeRecognized;
                            break;
                        default:
                            cout << "Alert: We should never arrive here." << endl;
                            break;
                    }
                }
            }

            // we arrive here only, if no tag was recognized
            cout << "Warning: Child node for TLibraryPool not recognized: " << getXmlNodeType(line) << endl;

            xmlNodeRecognized:
            continue;
        }
    }
    else
    {
        cout << "Error: Failed to open file" << endl;
        return;
    }
    
    cout << "Closing XML file." << endl;
    inFile.close();
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
