/*
    XPathEvaluator.hpp

    Evaluates an XPath expression
*/

#ifndef INCLUDED_XPATHEVALUATOR_HPP
#define INCLUDED_XPATHEVALUATOR_HPP

#include "XMLDocument.hpp"
#include <string>

// @TODO Apply encapsulation and information hiding

// @pattern <pattern> @role <role>
class XPathEvaluator {
public:
    /*
        Constructor

        @param xpath XPath expression
    */    
    XPathEvaluator(std::string_view xpath);

    /*
        Evaluate the XPath on the document

        @param doc XML document to apply XPath to
        @return Resulting XML document of applying XPath
    */
    XMLDocument evaluate(XMLDocument document);

    std::string xpath;
};

#endif
