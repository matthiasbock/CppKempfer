// class TCustomer
using namespace std;

#include "tcustomer.h"


TCustomer::TCustomer(ifstream& inFile)
:TPerson(inFile)
{
    load(inFile);
}


void TCustomer::load(ifstream& inFile)
{
    cout << "Parsing TCustomer..." << endl;

    string tagToLookFor[] = {"<Name>", "<Birthday>", "<Address>", "<CustomerNr>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of customer
        if (line.find("</Customer>") != string::npos)
        {
            cout << "End of TCustomer." << endl;
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
                        goto xmlNodeRecognized;
                        break;
                    // find Birthday > create Birthday and let it load
                    case 1:
                        Birthday = new TDate(inFile);
                        goto xmlNodeRecognized;
                        break;
                    // find Address > create Address and let it load then add to vector
                    case 2:
                        Address = new TAddress(inFile);
                        goto xmlNodeRecognized;
                        break;
                    case 3:
                        CustomerNr = getXmlNodeContent(line);
                        goto xmlNodeRecognized;
                        break;
                    default:
                        cout << "Alert: We should never arrive here." << endl;
                        break;
                }
            }
        }

        // we arrive here only, if no tag was recognized
        cout << "Warning: Child node for TCustomer not recognized: " << getXmlNodeType(line) << endl;

        xmlNodeRecognized:
        continue;
    }
}


void TCustomer::print()
{
	((TPerson*) this)->print();

	cout << "Customer number: " << this->CustomerNr << endl;
}
