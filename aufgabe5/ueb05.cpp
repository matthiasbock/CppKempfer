#include <iostream>

using namespace std;

#include "tlibrarypool.h"

// name of the XML file to import
const char* filename = "data.xml";

int main()
{
    cout << "Importing library pool from " << filename << "..." << endl;
    xmlDoc *xml = xmlReadFile(filename, NULL, XML_PARSE_NOBLANKS);
    TLibraryPool myLibraryPool(xmlDocGetRootElement(xml));
    cout << "Import completed." << endl << endl;

    cout << "This is your library pool:" << endl;
    myLibraryPool.print();
    cout << endl;

    xmlFreeDoc(xml);
    xmlCleanupParser();

    return 0;
}
