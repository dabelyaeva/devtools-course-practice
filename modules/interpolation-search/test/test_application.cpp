// Copyright 2016 Zhiltsov Max

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "src/table_searcher_impl.h"


class TestApplication :
    public ::testing::Test,
    protected Application {
 protected:
    void SetUp() override;

    static const char kTableSource[];
};

const char TestApplication::kTableSource[] {
    "Name1,Value1,Value2,Value3\n"
    "Name2,Value1,Value2\n"
    "Name3\n"
    "Name4,Value1,\n"
    "Name5,Value1"
};

void TestApplication::SetUp() {
    table_.clear();

    std::stringstream ss;
    ss << kTableSource;
    readTable(&ss);
}

TEST_F(TestApplication, can_read_table_from_nullptr_source) {
    // Arrange, Act, Assert
    ASSERT_NO_THROW(readTable(nullptr));
}

TEST_F(TestApplication, can_read_table) {
    // Arrange & Act in SetUp()
    const Table expected = {
        {"Name1", "Value1", "Value2", "Value3"},
        {"Name2", "Value1", "Value2"},
        {"Name3"},
        {"Name4", "Value1", ""},
        {"Name5", "Value1"}
    };

    // Assert
    ASSERT_EQ(expected, table_);
}

TEST_F(TestApplication, can_perform_search_of_one_existing_key) {
    // Arrange
    constexpr char query[] = "Name2";
    const std::vector<Table::iterator> expected = {
        table_.begin() + 1
    };

    // Act
    const auto results = (performSearch(query));

    // Assert
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_TRUE(expected[i] == results[i]);
    }
}

TEST_F(TestApplication, can_perform_search_of_multiple_existing_keys) {
    // Arrange
    constexpr char query[] = "Name2,Name4";
    const std::vector<Table::iterator> expected = {
        table_.begin() + 1,
        table_.begin() + 3
    };

    // Act
    const auto results = (performSearch(query));

    // Assert
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_TRUE(expected[i] == results[i]);
    }
}

TEST_F(TestApplication, can_perform_search_of_one_unexisting_key) {
    // Arrange
    constexpr char query[] = "UnexistingKey";
    const std::vector<Table::iterator> expected = {
        table_.end()
    };

    // Act
    const auto results = (performSearch(query));

    // Assert
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_TRUE(expected[i] == results[i]);
    }
}

TEST_F(TestApplication, can_perform_search_of_multiple_unexisting_keys) {
    // Arrange
    constexpr char query[] = "UnexistingKey1,UnexistingKey2";
    const std::vector<Table::iterator> expected = {
        table_.end(),
        table_.end()
    };

    // Act
    const auto results = (performSearch(query));

    // Assert
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_TRUE(expected[i] == results[i]);
    }
}

TEST_F(TestApplication, can_perform_search_of_multiple_different_keys) {
    // Arrange
    constexpr char query[] = "UnexistingKey1,UnexistingKey2,"
        "Name2,UnexistingKey3,Name4";
    const std::vector<Table::iterator> expected = {
        table_.end(),
        table_.end(),
        table_.begin() + 1,
        table_.end(),
        table_.begin() + 3
    };

    // Act
    const auto results = (performSearch(query));

    // Assert
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_TRUE(expected[i] == results[i]);
    }
}

TEST_F(TestApplication, can_parse_command_line_expected_query_and_table) {
    // Arrange
    constexpr int argc = 5;
    constexpr const char* argv[argc] = {
        "somepath_to_binary",
        "-q",
        "Name1,Name2",
        "-t",
        "\"sometable.csv\""
    };
    Parameters expected;
    expected.query = "Name1,Name2";
    expected.tablePath = "\"sometable.csv\"";

    // Act
    const auto result = parseCommandLine(argc, argv);

    // Assert
    EXPECT_EQ(expected.query, result.query);
    EXPECT_EQ(expected.tablePath, result.tablePath);
}

TEST_F(TestApplication, can_parse_command_line_expected_query) {
    // Arrange
    constexpr int argc = 3;
    constexpr const char* argv[argc] = {
        "somepath_to_binary",
        "-q",
        "Name1,Name2"
    };
    Parameters expected;
    expected.query = "Name1,Name2";

    // Act
    const auto result = parseCommandLine(argc, argv);

    // Assert
    EXPECT_EQ(expected.query, result.query);
}

TEST_F(TestApplication, can_parse_command_line_unexpected_no_query) {
    // Arrange
    constexpr int argc = 5;
    constexpr const char* argv[argc] = {
        "somepath_to_binary",
        "-t",
        "sometable.csv"
    };

    // Act & Assert
    EXPECT_ANY_THROW(parseCommandLine(argc, argv));
}

TEST_F(TestApplication, can_parse_command_line_unexpected_unknown_args) {
    // Arrange
    constexpr int argc = 7;
    constexpr const char* argv[argc] = {
        "somepath_to_binary",
        "-a",
        "something",
        "-b",
    };

    // Act & Assert
    EXPECT_ANY_THROW(parseCommandLine(argc, argv));
}

TEST_F(TestApplication, can_parse_command_line_unexpected_query_without_query) {
    // Arrange
    constexpr int argc = 2;
    constexpr const char* argv[argc] = {
        "somepath_to_binary",
        "-q"
    };

    // Act & Assert
    EXPECT_ANY_THROW(parseCommandLine(argc, argv));
}

TEST_F(TestApplication, can_parse_command_line_unexpected_table_without_table) {
    // Arrange
    constexpr int argc = 4;
    constexpr const char* argv[argc] = {
        "somepath_to_binary",
        "-q",
        "Name1,Name2",
        "-t"
    };

    // Act & Assert
    EXPECT_ANY_THROW(parseCommandLine(argc, argv));
}

TEST_F(TestApplication, can_parse_command_line_unexpected_empty) {
    // Arrange
    constexpr int argc = 1;
    constexpr const char* argv[argc] = {
        "somepath_to_binary"
    };

    // Act & Assert
    EXPECT_ANY_THROW(parseCommandLine(argc, argv));
}

TEST_F(TestApplication, can_parse_command_line_unexpected_too_many_args) {
    // Arrange
    constexpr int argc = 5;
    constexpr const char* argv[argc] = {
        "somepath_to_binary0",
        "somepath_to_binary1",
        "somepath_to_binary2",
        "somepath_to_binary3",
        "somepath_to_binary4",
    };

    // Act & Assert
    EXPECT_ANY_THROW(parseCommandLine(argc, argv));
}

TEST_F(TestApplication,
    can_parse_command_line_unexpected_nullptr_argv_internal
) {
    // Arrange
    constexpr int argc = 4;
    constexpr const char* argv[argc] = {
        "somepath_to_binary",
        "-q",
        "Name1",
        nullptr
    };
    Parameters expected;
    expected.query = "Name1";

    // Act
    const auto result = parseCommandLine(argc, argv);

    // Assert
    EXPECT_EQ(expected.query, result.query);
}

TEST_F(TestApplication, can_print_help) {
    // Arrange
    std::stringstream ss;

    // Act
    printHelp("123", &ss);

    // Assert
    EXPECT_FALSE(ss.str().empty());
}

TEST_F(TestApplication, can_print_help_with_nullptr) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(printHelp("123", nullptr));
}

TEST_F(TestApplication, can_run) {
    // Arrange
    constexpr int argc = 5;
    constexpr const char* argv[argc] = {
        "somepath_to_binary",
        "-q", "Name1,Name2",
        "-t", "testTable.csv"
    };
    table_.clear();

    std::ofstream ofs(argv[argc - 1]);
    if (ofs.is_open() == false) {
        throw std::runtime_error("Failed to create test table.");
    }
    ofs << kTableSource << std::endl;
    ofs.close();

    // Act
    std::string result;
    Application::Run(argc, argv, &result);

    // Assert
    EXPECT_FALSE(result.empty());

    std::remove(argv[argc - 1]);
}

TEST_F(TestApplication, can_run_with_nullptr_result) {
    // Arrange
    constexpr int argc = 3;
    constexpr const char* argv[argc] = {
        "somepath_to_binary",
        "-q",
        "Name1,Name2"
    };

    // Act & Assert
    ASSERT_NO_THROW(Application::Run(argc, argv, nullptr));
}

TEST_F(TestApplication, can_run_with_nullptr_argv) {
    // Arrange
    constexpr int argc = 1;

    // Act & Assert
    std::string result;
    EXPECT_NO_THROW(Application::Run(argc, nullptr, &result));
}

TEST_F(TestApplication, can_run_with_nullptr_argv_and_result) {
    // Arrange
    constexpr int argc = 1;

    // Act & Assert
    EXPECT_NO_THROW(Application::Run(argc, nullptr, nullptr));
}
