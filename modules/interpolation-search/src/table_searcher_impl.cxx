// Copyright 2016 Zhiltsov Max

#include "table_searcher_impl.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>

#include "include/interpolation_search.h"
#include "include/string_util.h"


class Application::CommandLineParameter {
 public:
    static constexpr char Table = 't';
    static constexpr char Query = 'q';

    CommandLineParameter() = delete;
};

void Application::Run(int argc, const char* const* argv, std::string* result) {
    if ((result == nullptr) || (argv == nullptr)) {
        return;
    }

    try {
        const auto parameters = std::move(parseCommandLine(argc, argv));
        std::istream* inputStream = &std::cin;
        std::ifstream tableFile;
        if (parameters.tablePath.empty() == false) {
            tableFile.open(parameters.tablePath);
            if (tableFile.is_open() == true) {
                inputStream = &tableFile;
            } else {
                throw std::runtime_error("Failed to open table file '" +
                    parameters.tablePath + "'.");
            }
        }
        readTable(*inputStream);

        const auto searchResults = std::move(performSearch(parameters.query));
        for (const auto& entry : searchResults) {
            if (entry == table_.end()) {
                continue;
            }
            for (auto it = (*entry).cbegin(), iend = (*entry).cend();
                it != iend;)
            {
                result->append(*it);
                if (++it != iend) {
                    result->append(", ");
                }
            }
            result->append("\n");
        }
    } catch (const std::exception& e) {
        result->append(e.what()).append("\n");

        const std::string appName = (argv != nullptr) ? argv[0] : "";
        std::stringstream ss;
        printHelp(appName, &ss);
        result->append(ss.str());
    }
}

void
Application::printHelp(const std::string& appName, std::ostream* os) const {
    if (os == nullptr) {
        return;
    }

    using std::endl;
    (*os)
        << "Usage: " << appName << " -" << CommandLineParameter::Query
            << " \"Tom Peterson,BobWillson\" [-" << CommandLineParameter::Table
            << " table.csv]" << endl
        << "Parameters:" << endl
        << "\t-" << CommandLineParameter::Table
            << " - Path to a file with table in format: Name, Data, ..." << endl
        << "\t-" << CommandLineParameter::Query
            << " - Query to search to in table. Format: name[,name]" << endl
        << endl
        << "Program searches for a query in a first column of a table. "
            << "If no table was given then stdin is used as an input table. "
            << endl
        << endl;
}

Application::Parameters
Application::parseCommandLine(int argc, const char* const* argv) {
    Parameters parameters;

    if (argv == nullptr) {
        return std::move(parameters);
    }

    if ((argc == 1) || (5 < argc)) {
        throw std::runtime_error("Failed to parse command line: "
            "Wrong command line parameters count.");
    }

    int i = 1;
    while (i < argc) {
        if (argv[i] == nullptr) {
            ++i;
            continue;
        }

        const std::string arg = argv[i];
        if (arg == std::string({'-', CommandLineParameter::Table})) {
            if ((i + 1 < argc) && (argv[i + 1] != nullptr)) {
                parameters.tablePath = argv[i + 1];
                i += 2;
            } else {
                throw std::runtime_error("Failed to parse command line: " +
                    std::string("Wrong argument of '-") +
                    CommandLineParameter::Table + std::string("' parameter."));
            }
        } else if (arg == std::string({'-', CommandLineParameter::Query})) {
            if ((i + 1 < argc) && (argv[i + 1] != nullptr)) {
                parameters.query = argv[i + 1];
                i += 2;
            } else {
                throw std::runtime_error("Failed to parse command line: " +
                    std::string("Wrong argument of '-") +
                    CommandLineParameter::Query + std::string("' parameter."));
            }
        } else {
            throw std::runtime_error("Failed to parse command line: "
                "Unexpected command line parameter: " + arg);
        }
    }

    if (parameters.query.empty() == true) {
        throw std::runtime_error("Query command line parameter is expected.");
    }

    return std::move(parameters);
}

void Application::readTable(std::istream& source) {
    while (source.good() == true) {
        std::string line;
        std::getline(source, line);
        table_.emplace_back(std::move(splitString(line, ",")));
    }

    std::sort(table_.begin(), table_.end(),
        [] (const Table::value_type& a, const Table::value_type& b) {
            return a.front() < b.front();
        });
}

std::vector<Application::Table::iterator>
Application::performSearch(const std::string& query) {
    using interp_search::Find;

    const auto queries = std::move(splitString(query, ","));
    std::vector<Table::iterator> results;
    results.reserve(queries.size());

    auto less = [] (const TableRow& a, const TableRow& b) {
        return std::strcmp(a.front().c_str(), b.front().c_str()) < 0;
    };
    auto diff = [] (const TableRow& a, const TableRow& b) {
        return findStringDifference(a.front().c_str(), b.front().c_str());
    };

    for (const auto& query : queries) {
        const Table::value_type key { query };
        results.emplace_back(
            Find(table_.begin(), table_.end(), key, less, diff));
    }

    return std::move(results);
}
