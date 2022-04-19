/*
    XMLDocumentTemplateParser.hpp

    Parses XML into an XMLDocument
*/

#ifndef INCLUDED_XMLDOCUMENTTEMPLATEPARSER_HPP
#define INCLUDED_XMLDOCUMENTTEMPLATEPARSER_HPP

// @TODO Move as many include files as possible from here to XMLDocumentTemplateParser.cpp
#include "XMLDocumentParser.hpp"
#include "XMLDocument.hpp"
#include <string_view>
#include <iostream>
#include <fstream>
#include <sstream>

// @pattern <pattern> @role <role>
class XMLDocumentTemplateParser : public XMLDocumentParser {
public:
    /*
        Parse the file into an XMLDocument

        @param filename Filename of the file to parse
    */
    virtual XMLDocument parse(std::string_view filename);
};

#endif
