/*
    MacroFilter.hpp

    Macro filter that contains many filters
*/

#ifndef INCLUDED_MACROFILTER_HPP
#define INCLUDED_MACROFILTER_HPP

#include "XMLDocument.hpp"
#include "Filter.hpp"
#include <vector>
#include <string>

// @TODO Use override where appropriate

// @TODO Enforce that no one can override MacroFilter::action()

// @TODO Apply encapsulation and information hiding

// @pattern <pattern> @role <role>
class MacroFilter : public Filter {
public:
    /*
        Constructor
    */
    MacroFilter();

    /*
        Replaces the current XML document with the result of parsing 
        the filename

        @param doc Ignore starting document
        @return XML document from parsing input file
    */
    virtual XMLDocument action(XMLDocument document);

    /*
        Add a filter

        @param filter A valid filter
    */
    void addFilter(std::unique_ptr<Filter> filter);

    std::vector<std::unique_ptr<Filter>> filters;
};

#endif
