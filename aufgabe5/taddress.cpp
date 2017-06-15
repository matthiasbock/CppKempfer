// class TAddresse
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "taddress.h"


TAddress::TAddress(string Street, string Number, string Zipcode, string Town)
{
    this->Street = Street;
    this->Number = Number;
    this->Zipcode = Zipcode;
    this->Town = Town;
}

TAddress::TAddress(ifstream& inFile)
{
    load(inFile);
}

void TAddress::load(ifstream& inFile)
{
    string tagToLookFor[] = {"<Street>", "<Number>", "<Zipcode>", "<Town>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    
    while (getline(inFile, line))
    {
        // detect end of Address to prevent any problems
        if (line.find("</Address>") != string::npos)
        {
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                    case 0:
                        Street = getXmlNodeContent(line);
                        break;
                    case 1:
                        Number = getXmlNodeContent(line);
                        break;
                    case 2:
                        Zipcode = getXmlNodeContent(line);
                        break;
                    case 3:
                        Town = getXmlNodeContent(line);
                        break;
                    default:
                        cout << "Nothing found... in Address" << endl;
                        break;
                }
            }
        }
    }
}


void TAddress::print()
{
    cout << Street << " " << Number << "; " << Zipcode << " " << Town;
}

string TAddress::get_street() const {return Street;}
string TAddress::get_number() const {return Number;}
string TAddress::get_zipcode() const {return Zipcode;}
string TAddress::get_town() const {return Town;}

void TAddress::set_street(string s) {Street = s;}
void TAddress::set_number(string n) {Number = n;}
void TAddress::set_zipcode(string z) {Zipcode = z;}
void TAddress::set_town(string t) {Town = t;}
