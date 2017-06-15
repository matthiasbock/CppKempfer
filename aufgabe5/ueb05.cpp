#include <iostream>

using namespace std;

#include "tlibrarypool.h"

int main()
{
    cout << "Importing library pool from data.xml..." << endl;
    TLibraryPool LP("data.xml");
    cout << "Import completed." << endl << endl;

    cout << "This is your library pool:" << endl;
    LP.print();
    cout << endl;

    return 0;
}
