/*
    XMLDocumentParser.hpp

    Parses XML into an XMLDocument
*/

#ifndef INCLUDED_XMLDOCUMENTPARSER_HPP
#define INCLUDED_XMLDOCUMENTPARSER_HPP

#include "XMLDocument.hpp"
#include <string_view>

// @pattern <pattern> @role <role>
class XMLDocumentParser {
public:
    /*
        Parse the file into an XMLDocument

        @param filename Filename of the file to parse
    */
    // @TODO Apply const when applicable
    virtual XMLDocument parse(std::string_view filename) = 0;

    // destructor
    // @TODO Remove need for destructor definition
    virtual ~XMLDocumentParser() {}
};

#endif
