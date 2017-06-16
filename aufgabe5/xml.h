
#ifndef XML_H
#define XML_H

#include <iostream>
#include <vector>
#include <string>

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>

using namespace std;

/**
 * @brief Extract content of an XML node,\
 *  i.e. the string between "<...>" and "</...>"
 *
 * @param line: One line as read from XML file (max. one node per line)
 */
string getXmlNodeContent(string line);

/**
 * @brief Extract type of XML node, \
 *  i.e. the string between "<" and ">"
 *
 * @param line: One line as read from XML file (max. one node per line)
 */
string getXmlNodeType(string line);

/**
 * @brief Returns a pointer to an XML node with the given name and below the given XML parent node
 * @param XML parent node
 * @param Requested XML node name
 */
xmlNodePtr xmlGetChildByName(xmlNodePtr, const char*);

/**
 * @brief Returns a vector of XML nodes with the given name and below the given XML parent node
 * @param XML parent node
 * @param Requested XML node name
 * @param Reference to vector to modify
 */
void xmlGetChildrenByName(xmlNodePtr node, const char* name, vector<xmlNodePtr>& nodes);

#endif
