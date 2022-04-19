# XMLFramework

A framework for XML processing:

* Parsing XML with a variety of push and pull parsers
* XPath evaluation
* XSLT transformation
* Combining these operations as needed by the applications

The open-layered architecture framework, XMLFramework, supports
all this and includes:

* Applications
    * Applications using the XMLFramework
    * An xmlpipeline application for a CLI that flexibly uses
      the XMLFramework
* XMLFramework 
    * As described above
* XMLToolkit
    * Set of C++ classes for processing XML
    * Used to implement the XMLFramework, but can be used directly
    * XMLParser belongs here
* XMLLibrary
    * Set of C functions for processing XML
    * Used to implement the XMLToolkit, but can be used directly
