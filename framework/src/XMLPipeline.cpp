/*
    XMLPipeline.cpp

    Implementation for XML pipeline
*/

// @TODO Remove unused include files
#include "XMLPipeline.hpp"
#include "Filter.hpp"
#include "ParserFilter.hpp"
#include "XPathFilter.hpp"
#include "OutputFilter.hpp"
#include "FilterFactory.hpp"

// @TODO Replace boolean return with exception handling
/*
    Add a filter by name

    @param name The name of the filter
    @param parameter Parameter to the filter
    @return Does the filter exist
*/
bool XMLPipeline::addFilter(std::string_view name, std::string_view parameter) {

    // create the proper filter
    std::unique_ptr<Filter> filter = FilterFactory::Create(name, parameter);

    // if no filter created, then the name is most likely invalid
    if (!filter)
        return false;

    // append xml filter
    filters.push_back(std::move(filter));

    return true;
}

/*
    Run the pipeline of filters
*/
void XMLPipeline::run() {

    // a NOP with no filters
    if (filters.empty())
        return;

    // @TODO Replace this code with a call to the action of the class MacroFilter
    // apply all filters in sequential order
    XMLDocument document;
    for (const auto& filter : filters) {
        document = filter->action(std::move(document));
    }
    
    // perform a default OutputFilter if the last filter in the pipeline is not an output
    if (!filters.back()->isOutput()) {
        OutputFilter("-").action(std::move(document));
    }
}
