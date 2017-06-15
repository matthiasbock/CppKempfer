// class TLibraryPool

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "tlibrarypool.h"

TLibraryPool::TLibraryPool(string n, TPerson* p)
:Name(n), Boss(p) {}

/**
 * @brief Import library pool from XML file
 *
 * @param filename: Name of the XML file to import
 */
TLibraryPool::TLibraryPool(string filename)
:Filename(filename)
{
    // open XML file
    inFile.open(Filename.c_str());

    string tagToLookFor[] = {"<Name>", "<Chairman>", "<Library>", "<Customer>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;

    // to be sure if file is found and is opened
    if (inFile.is_open())
    {
        getline(inFile, line);
        //cout << "first Line: " << line << endl; 
        // check if xml format valid
        if (line.find("<LibraryPool>") != string::npos) // here prolly same with >= 0
        {
            while (getline(inFile, line))
            {
                // detect end of xml to prevent any problems
                if (line.find("</LibraryPool>") != string::npos)
                {
                    cout << "end of xml... bye" << endl;
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
                                break;
                            // find Chairman > create TPerson and let it load
                            case 1:
                                Boss = new TPerson(inFile);
                                break;
                            // find Library > create TPerson and let it load then add to vector
                            case 2:
                                add(new TLibrary(inFile));
                                break;
                            case 3:
                                add(new TPerson(inFile));
                                break;
                            default:
                                cout << "Strange, we recognized something, but we didn't recognized it." << endl;
                                break;
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout << "Error opening file!" << endl;
    }
    
    cout << "Closing file" << endl;
    inFile.close();
}

/**
 * @brief Library pool destructor
 */
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
    delete Boss;
}


void TLibraryPool::add(TPerson* customer)
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
    Boss->print();
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


void TLibraryPool::set_name(string n) {Name = n;}
void TLibraryPool::set_boss(TPerson* b) {Boss = b;}
void TLibraryPool::set_customer(vector<TPerson*> cus) {CustomerList = cus;}
void TLibraryPool::set_libraryList(vector<TLibrary*>lib) {LibraryList = lib;}

string TLibraryPool::get_name() const {return Name;}
TPerson* TLibraryPool::get_boss() const {return Boss;}
vector<TPerson*>TLibraryPool::get_customerList() const {return CustomerList;}
vector<TLibrary*>TLibraryPool::get_libraryList() const {return LibraryList;}
