using namespace std;

#include "tdvd.h"

TDVD::TDVD (ifstream& inFile, streampos endPos)
:TMedium(inFile, endPos), endPos(endPos)
{
    load(inFile);
}


void TDVD::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Actors>", "<PlayingTime>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    inFile.seekg(TMedium::get_fpos());
    while (getline(inFile, line))
    {
        // detect end of Library to prevent any problems
        if (inFile.tellg() == endPos)
        {
            cout << "END OF TDVD DETECTED" << endl;
            break;   
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                    case 0:
                        Actors = parseLine(line, tagToLookFor[i]);
                        break;
                    case 1:
                        PlayingTime = new TTime(inFile);
                        break;                                            
                    default:
                        cout << "Nothing found... in TDVD" << endl;
                        break;
                }
            }
        }
    }
}


TDVD::~TDVD()
{
    cout << "Destructing TDVD \"" << get_name() << "\"..." << endl;

    if (PlayingTime != nullptr)
        delete PlayingTime;
}


void TDVD::print()
{
    cout << "Actors: " << Actors << endl;
    cout << "Spieldauer: ";
    PlayingTime->print();
    cout << endl;
    TMedium::print();
}
