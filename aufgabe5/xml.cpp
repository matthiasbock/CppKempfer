
#include "xml.h"

string xmlGetNodeContent(string line)
{
    int begin = line.find(">") + 1;
    int length = line.find("</") - begin;
    return line.substr(begin, length);
}

string xmlGetNodeType(string line)
{
    int begin = line.find("<") + 1;
    int length = line.find(">") - begin;
    return line.substr(begin, length);
}

xmlNodePtr xmlGetChildByName(xmlNodePtr node, const char* name)
{
    node = node->children;
    while (node != nullptr)
    {
//        cout << node->name << endl;

        if (!xmlStrcmp(node->name, (const xmlChar*) name))
        {
//            cout << "found" << endl;
            return node;
        }

        // without this if-block, it's not working:
        if (node->children != nullptr)
        {
            xmlNodePtr subNode = xmlGetChildByName(node, name);
            if (subNode != nullptr)
                return subNode;
        }

        node = node->next;
    }
//    cout << "not found" << endl;
    return nullptr;

/*
    xmlXPathContext *context = xmlXPathNewContext(xml->doc);
    context->node = xml;
    xmlXPathObject *object = xmlXPathEvalExpression((xmlChar*) path, context);
    if (object != nullptr && object->nodesetval != nullptr && object->nodesetval->nodeTab != nullptr)
        return object->nodesetval->nodeTab[0];

    // child not found
    return nullptr;
*/
}

void xmlGetChildrenByName(xmlNodePtr node, const char* name, vector<xmlNodePtr>& nodes)
{
    node = node->children;
    nodes.clear();

    while (node != nullptr)
    {
//        cout << node->name << "? ";
        if (!xmlStrcmp(node->name, (const xmlChar*) name))
        {
//            cout << "yes" << endl;
            nodes.push_back(node);
        }
//        else
//            cout << "no" << endl;

        // without this if-block, it's not working:
        if (node->children != nullptr)
        {
            xmlNodePtr subNode = xmlGetChildByName(node, name);
//            if (subNode != nullptr)
//                return subNode;
        }

        node = node->next;
    }
//    cout << "Node list length: " << nodes.size() << endl;
}


string xmlGetString(xmlNodePtr parent, const char *childName, string targetClass)
{
    xmlNodePtr childNode = xmlGetChildByName(parent, childName);
    if (childNode != nullptr)
    {
        string s = string((char*) xmlNodeGetContent(childNode));
        cout << targetClass << "." << childName << " = \"" << s << "\";" << endl;
        return s;
    }
    else
        cout << "Warning: Child node <" << childName << "> for " << targetClass << " not found." << endl;
    return "";
}


int xmlGetInt(xmlNodePtr parent, const char *childName, string targetClass)
{
    xmlNodePtr childNode = xmlGetChildByName(parent, childName);
    if (childNode != nullptr)
    {
        try
        {
            int i = atoi((char*) xmlNodeGetContent(childNode));
            cout << targetClass << "." << childName << " = " << i << ";" << endl;
            return i;
        }
        catch (exception e)
        {
            cout << "Error: Conversion of string to int failed for child node <Year> for TDate." << endl;
        }
    }
    else
        cout << "Warning: Child node <" << childName << "> for " << targetClass << " not found" << endl;
    return -1;
}
