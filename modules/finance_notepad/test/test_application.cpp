// Copyright 2016 Magazinnik Ivan

#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include "include/Application.h"

using std::vector;
using std::string;
using ::testing::internal::RE;

class AppFinanceNotepadTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("finance_notepad");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    string output_;
};

TEST_F(AppFinanceNotepadTest, can_create_app) {
    // Arrange
    Application* app;

    // Act
    app = new Application();

    // Assert
    EXPECT_NE(nullptr, app);
    delete app;
}

TEST_F(AppFinanceNotepadTest,
       can_reach_inexistent_param_error) {
    // Arrange
    std::string argument = "-a";
    vector<string> args = {argument};

    // Act
    Act(args);

    // Assert
    Assert("param " + argument + " not found\n");
}

TEST_F(AppFinanceNotepadTest,
     can_reach_error_msg_when_invalid_argument_number) {
    // Arrange
    vector<string> args = {"a", "b", "c", "d", "f", "g"};

    // Act
    Act(args);

    // Assert
    Assert("Error invalid number of Arguments\\..*");
}
TEST_F(AppFinanceNotepadTest,
       can_reach_error_msg_when_first_arg_is_not_param) {
    // Arrange
    vector<string> args = {"help"};

    // Act
    Act(args);

    // Assert
    Assert("error first argument must be param ");
}

TEST_F(AppFinanceNotepadTest, can_call_help) {
    // Arrange
    vector<string> args = {"--help"};

    // Act
    Act(args);

    // Assert
    Assert("This is a finance notepad application\\..*");
}

TEST_F(AppFinanceNotepadTest, can_reach_error_msg_when_read_wrong_filename) {
    // Arrange
    vector<string> args = {"-r", "not_existed_file"};

    // Act
    Act(args);

    // Assert
    Assert("file not exist!");
}

TEST_F(AppFinanceNotepadTest, can_read_from_file) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "30\n";
    fout << "2 january 2016 -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-r", filename};

    // Act
    Act(args);

    // Assert
    Assert("2.1.2016");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_reach_date_day_error) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "30\n";
    fout << "day january 2016 -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-r", filename};

    // Act
    Act(args);

    // Assert
    Assert("Error wrong day param!");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_reach_date_month_error) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "30\n";
    fout << "2 joanuary 2016 -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-r", filename};

    // Act
    Act(args);

    // Assert
    Assert("Error wrong month param!");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_reach_date_year_error) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "30\n";
    fout << "2 january year -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-r", filename};

    // Act
    Act(args);

    // Assert
    Assert("Error wrong year param!");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_reach_delta_cash_error) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "30\n";
    fout << "2 january 2016 cash Debt For Noname\n";
    fout.close();
    vector<string> args = {"-r", filename};

    // Act
    Act(args);

    // Assert
    Assert("Error wrong delta money param!");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_reach_data_error) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "30\n";
    fout << "0 january 2016 -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-r", filename};

    // Act
    Act(args);

    // Assert
    Assert("Error wrong date param!");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_reach_pouch_error) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "pouch\n";
    fout << "0 january 2016 -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-r", filename};

    // Act
    Act(args);

    // Assert
    Assert("Error wrong pouch param!");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_get_pouch) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "50\n";
    fout << "0 january 2016 -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-gp", filename};

    // Act
    Act(args);

    // Assert
    Assert("Your pouch is 50");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_get_potential_pouch) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "50\n";
//    notes.addNote(date(3, months::APRIL, 2017), -20.f, "Food", "KFC");
    fout << "3 april 2017 -20 Food KFC\n";
    fout << "0 january 2016 -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-gpp", filename};

    // Act
    Act(args);

    // Assert
    Assert("Your potential pouch is 30");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_get_sum_from_cathegory) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::ofstream fout(filename);
    fout << "100\n";
    fout << "3 april 2017 -20 Food KFC\n";
    fout << "1 december 2015 -30 Food burger king\n";
    fout << "2 january 2016 -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-s", filename, "Food"};

    // Act
    Act(args);

    // Assert
    Assert("Sum = -50");
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_write_to_file) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    vector<string> args = {"-w", filename,
                           "1 december 2015 -30 Food burger king\n"};
    std::string expected = "1 12 2015 -30 Food burgerking";
    std::string current = "";
    // Act
    Act(args);
    std::ifstream fin(filename);

    getline(fin, current);
    getline(fin, current);

    // Assert
    ASSERT_EQ(expected, current);
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_sort_by_date) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::string expected = "1 12 2015 -30 Food McD";
    std::ofstream fout(filename);
    fout << "100\n";
    fout << "3 april 2017 -20 Food KFC\n";
    fout << expected + "\n";
    fout << "2 january 2016 -30 Debt For Noname\n";
    fout.close();
    vector<string> args = {"-d", filename};
    std::string current = "";

    // Act
    Act(args);
    std::ifstream fin(filename);

    getline(fin, current);
    getline(fin, current);

    // Assert
    ASSERT_EQ(expected, current);
    remove(filename.c_str());
}

TEST_F(AppFinanceNotepadTest, can_grouped_read) {
    // Arrange
    std::string filename = "test_read_from_file.txt";
    std::string expected = "2 january 2016 -30 Debt Noname";
    std::ofstream fout(filename);
    fout << "100\n";
    fout << "3 april 2015 -20 Food KFC\n";
    fout << expected + "\n";
    fout << "1 12 2017 -30 Food McD\n";
    fout.close();
    vector<string> args = {"-rc", filename};
    std::string current = "";

    // Act
    Act(args);

    // Assert
    Assert("2 1 2016");
    remove(filename.c_str());
}
