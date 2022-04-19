/*
    ParserFilter.hpp

    Parser filter for XMLFramework
*/

#ifndef INCLUDED_PARSERFILTER_HPP
#define INCLUDED_PARSERFILTER_HPP

#include "XMLDocument.hpp"
#include "Filter.hpp"
#include <string>
#include <memory>

// @TODO Use override where appropriate

// @TODO Enforce that no one can override ParserFilter::action()

// @TODO Apply encapsulation and information hiding

// @pattern <pattern> @role <role>
class ParserFilter : public Filter {
public:
    /*
        Constructor

        @param filename Filename for action to parse
    */
    ParserFilter(std::string_view filename);

    /*
        Replaces the current XML document with the result of parsing 
        the filename

        @param doc Ignore starting document
        @return XML document from parsing input file
    */
    virtual XMLDocument action(XMLDocument document);

    /*
        Factory method

        @param xpath XPath expression applied to the document
        @return OutputFilter object
    */
    static std::unique_ptr<Filter> factory(std::string_view xpath);

    std::string inputFilename;

private:

    // Filter registration
    static bool registered;
};

#endif
