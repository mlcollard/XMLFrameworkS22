/*
    xmlrepl.cpp

    An XML REPL (Read-Eval-Print-Loop). Command names are based
    on Filter names.
*/

#include <string>
#include <sstream>
#include "FilterFactory.hpp"
#include "OutputFilter.hpp"

int main(int argc, char* argv[]) {

    XMLDocument document;
    while (true) {

        std::cout << "$ ";

        // Control-D loop exit
        std::string line;
        if (!(std::getline(std::cin, line))) {
            // newline after bare prompt
            std::cout << '\n';
            break;
        }

        // extract the command
        std::istringstream in(line);
        std::string command;
        in >> command;

        // command exit/quit
        if (command == "exit" || command == "quit")
            break;

        // command help
        if (command == "help" or command == "h") {
            // list each filter
            for (const auto& filterInfo : FilterFactory::getFilterNames()) {

                std::cout << filterInfo.first << " - " << filterInfo.second << '\n';
            }
            continue;
        }

        // command is a filter
        std::string filterName = std::move(command);

        // verify filter
        if (!FilterFactory::isRegistered(filterName)) {
            std:: cout << "-xmlrepl: " << filterName << ": filter not found\n";
            continue;
        }

        // extract argument
        std::string argument;
        in >> argument;
        if (argument.empty()) {
            std:: cout << "-xmlrepl: " << filterName << ": filter requires argument\n";
            continue;
        }

        // carry out the filter on the current document
        auto filter = FilterFactory::Create(filterName, argument);
        auto tmpdocument = filter->action(std::move(document));

        // output the document to the user, saving it for the next pass
        OutputFilter output("-");
        document = output.action(std::move(tmpdocument));
    }

    return 0;
}
