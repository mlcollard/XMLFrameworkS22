/*
    Filter.hpp

    Filter for XMLFramework
*/

#ifndef INCLUDED_FILTER_HPP
#define INCLUDED_FILTER_HPP

#include "XMLDocument.hpp"

// @TODO Apply the const specifier to methods where applicable

// @pattern <pattern> @role <role>
class Filter {
public:

    /*
        Performs the action on the XML document

        @param doc Input XML document
        @return XML document after action performed on input
    */
    virtual XMLDocument action(XMLDocument document) = 0;

    /*
        Does the filter perform output
    */
    virtual bool isOutput() { return false; }

    // destructor
    // @TODO Remove need for destructor definition (but remain virtual)
    virtual ~Filter() {}
};

#endif
