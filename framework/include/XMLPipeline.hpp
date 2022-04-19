/*
    XMLPipeline.hpp

    Include for XML pipeline
*/

#ifndef INCLUDED_XMLPIPELINE_HPP
#define INCLUDED_XMLPIPELINE_HPP

// @TODO Remove any unused include files
#include "Filter.hpp"
#include "ParserFilter.hpp"
#include "XPathFilter.hpp"
#include <string_view>
#include <vector>
#include <memory>

// @TODO Apply the const specifier to methods where applicable

// @pattern <pattern> @role <role>
class XMLPipeline {
public:

    /*
        Add a filter by name

        @param name Name of the filter
        @param parameter Parameter to the filter
        @return Does the filter exist
    */
    bool addFilter(std::string_view name, std::string_view parameter);

    /*
        Run the pipeline of filters
    */
    void run();

private:

    // pipeline filters
    // @TODO Replace with an instance of a MacroFilter
    std::vector<std::unique_ptr<Filter>> filters;
};

#endif
