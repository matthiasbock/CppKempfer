
#include "xml.h"

string getXmlNodeContent(string line)
{
    int begin = line.find(">") + 1;
    int length = line.find("</") - begin;
    return line.substr(begin, length);
}

string getXmlNodeType(string line)
{
    int begin = line.find("<") + 1;
    int length = line.find(">") - begin;
    return line.substr(begin, length);
}
