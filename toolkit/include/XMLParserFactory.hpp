/*
    XMLParserFactory.hpp

    Creates XMLDocumentParser's
*/

#ifndef INCLUDED_XMLPARSERFACTORY_HPP
#define INCLUDED_XMLPARSERFACTORY_HPP

// @TODO Remove as many include files as possible
#include <iostream>
#include <string>
#include <memory>
#include "XMLDocumentParser.hpp"

// @pattern <pattern> @role <role>
class XMLParserFactory {
public:

    /*
       Factory method to create XMLDocumentParser
    */
    static std::unique_ptr<XMLDocumentParser> factory(int size);
};

#endif
