
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

xmlNodePtr xmlGetChildByName(xmlNodePtr xml, const char* path)
{
    xmlXPathContext *context = xmlXPathNewContext(xml->doc);
    context->node = xml;
    xmlXPathObject *object = xmlXPathEvalExpression((xmlChar*) path, context);
    if (object != nullptr && object->nodesetval != nullptr && object->nodesetval->nodeTab != nullptr)
        return object->nodesetval->nodeTab[0];

    // child not found
    return nullptr;
}
