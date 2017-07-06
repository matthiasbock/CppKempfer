#include <iostream>

using namespace std;

#include "tlibrarypool.h"

int main()
{
   TLibraryPool LP("data.xml");

   cout << LP << endl;

   return 0;
}
