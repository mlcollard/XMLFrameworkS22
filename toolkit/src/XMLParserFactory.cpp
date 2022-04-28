/*
    XMLParserFactory.cpp

    Creates XMLDocumentParser's
*/

#include "XMLParserFactory.hpp"
#include "XMLDocumentTemplateParser.hpp"

/*
   Factory method to create XMLDocumentParser
*/
std::unique_ptr<XMLDocumentParser> XMLParserFactory::factory(int size) {

    // @TODO Integrate use of XMLDocumentHandlerParser into this method

    // @TODO Add to the factory method so that it generates the correct parser
    //       for this (and other) methods:
    //       * XMLDocumentHandlerParser when the size is less
    //         than 1000 characters 
    //       * Otherwise use the XMLDocumentTemplateParser

    // @TODO Make it so that there is only one parser object in the entire
    //       program, no matter where it is called
    return std::unique_ptr<XMLDocumentTemplateParser>(new XMLDocumentTemplateParser());
}
