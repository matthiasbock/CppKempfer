
#ifndef XML_H
#define XML_H

#include <string>

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

#endif
