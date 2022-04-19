/*
    XMLDocument.hpp

    XML document to represent in-memory XML
*/

#ifndef INCLUDED_XMLDOCUMENT_HPP
#define INCLUDED_XMLDOCUMENT_HPP

#include <iostream>
#include <string>

// @TODO Apply encapsulation and information hiding

class XMLDocument {
public:
    // output operator
    friend std::ostream& operator <<(std::ostream& out, const XMLDocument& document);

    // void constructor
    // @TODO Remove need for void constructor definition
    XMLDocument() {}

    // constructor with initial contents
    XMLDocument(std::string_view contents);

    // move constructor from initial contents
    XMLDocument(std::string&& contents);

    // move copy constructor
    XMLDocument(XMLDocument&& other);

    // move assignment operator
    XMLDocument& operator=(XMLDocument&& other);

    // get contents
    std::string& get();

    std::string contents;
};

#endif
