// Copyright 2016 Zhiltsov Max

#ifndef MODULES_INTERPOLATION_SEARCH_SRC_TABLE_SEARCHER_IMPL_H_
#define MODULES_INTERPOLATION_SEARCH_SRC_TABLE_SEARCHER_IMPL_H_

#include <iostream>
#include <vector>
#include <string>

#include "include/interpolation_search.h"


class Application {
 public:
    Application() = default;
    void Run(int argc, const char* const* argv, std::string* result);

 protected:
    class CommandLineParameter;

    struct Parameters {
        std::string tablePath;
        std::string query;
    };
    void printHelp(const std::string& appName, std::ostream* os) const;
    Application::Parameters parseCommandLine(int argc, const char* const* argv);

    using TableRow = std::vector<std::string>;
    using Table = std::vector<TableRow>;
    void readTable(std::istream* source);
    std::vector<Table::iterator> performSearch(const std::string& query);

    Table table_;

 private:
    Application(const Application& other) = delete;
    Application& operator=(const Application& other) = delete;
};

#endif  // MODULES_INTERPOLATION_SEARCH_SRC_TABLE_SEARCHER_IMPL_H_
