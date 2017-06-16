
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
