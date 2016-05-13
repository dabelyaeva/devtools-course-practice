// Copyright 2016 PolyakovIgor

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include\Application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AppTriangleTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
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


TEST_F(AppTriangleTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is application for work with Triangle\\..*");
}

TEST_F(AppTriangleTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = {"2.0", "5.0", "4.0"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 7 arguments\\..*");
}

TEST_F(AppTriangleTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = {"2.0", "5.5", "4.0",
                            "h", "11", "-40.0", "calc_angle_a"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong number format!.*");
}

TEST_F(AppTriangleTest, Can_Detect_Wrong_Function_Format) {
    // Arrange
    vector<string> args = {"2.0", "5.5", "4.0", "3.0",
                            "11.5", "-40.7", "wrong_func"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong function format!");
}

TEST_F(AppTriangleTest, Can_Not_Create_Triangle_With_Two_Same_Points) {
    // Arrange
    vector<string> args = { "0.0", "0.0", "0.0", "0.0",
        "11.5", "-40.7", "calc_angle_a" };

    // Act
    Act(args);

    // Assert
    Assert("Triangle is not correct, two points are identical");
}

TEST_F(AppTriangleTest, Can_Not_Create_Triangle_With_Three_Same_Points) {
    // Arrange
    vector<string> args = { "0.0", "0.0", "0.0", "0.0",
        "0.0", "0.0", "calc_angle_a" };

    // Act
    Act(args);

    // Assert
    Assert("Triangle is not correct, three points are identical");
}

TEST_F(AppTriangleTest, Can_Not_Create_Triangle_With_Points_On_One_Line) {
    // Arrange
    vector<string> args = { "0.0", "0.0", "1.0", "1.0",
        "2.0", "2.0", "calc_angle_a" };

    // Act
    Act(args);

    // Assert
    Assert("Triangle is not correct, all points on one line");
}

TEST_F(AppTriangleTest, Can_Calculate_Angle_A) {
    // Arrange
    vector<string> args = { "2.0", "5.5", "4.0", "3.0",
        "11.5", "-40.7", "calc_angle_a" };

    // Act
    Act(args);

    // Assert
    Assert("Angle CAB in radians of triangle ABC is equal = 0.47194");
}

TEST_F(AppTriangleTest, Can_Calculate_Angle_B) {
    // Arrange
    vector<string> args = { "2.0", "5.5", "4.0", "3.0",
        "11.5", "-40.7", "calc_angle_b" };

    // Act
    Act(args);

    // Assert
    Assert("Angle CBA in radians of triangle ABC is equal = 2.63682");
}

TEST_F(AppTriangleTest, Can_Calculate_Angle_C) {
    // Arrange
    vector<string> args = { "2.0", "5.5", "4.0", "3.0",
        "11.5", "-40.7", "calc_angle_c" };

    // Act
    Act(args);

    // Assert
    Assert("Angle ACB in radians of triangle ABC is equal = 0.0328321");
}

TEST_F(AppTriangleTest, Can_Calculate_Perimeter) {
    // Arrange
    vector<string> args = { "2.0", "5.5", "4.0", "3.0",
        "11.5", "-40.7", "calc_perimeter" };

    // Act
    Act(args);

    // Assert
    Assert("Perimeter of triangle ABC is equal = 94.7071");
}

TEST_F(AppTriangleTest, Can_Calculate_Area) {
    // Arrange
    vector<string> args = { "2.0", "5.5", "4.0", "3.0",
        "11.5", "-40.7", "calc_area" };

    // Act
    Act(args);

    // Assert
    Assert("Area of triangle ABC is equal = 34.325");
}

TEST_F(AppTriangleTest, Can_Calculate_Inradius) {
    // Arrange
    vector<string> args = { "2.0", "5.5", "4.0", "3.0",
        "11.5", "-40.7", "calc_inradius" };

    // Act
    Act(args);

    // Assert
    Assert("Inradius of triangle ABC is equal = 0.724866");
}

TEST_F(AppTriangleTest, Can_Calculate_Circumradius) {
    // Arrange
    vector<string> args = { "2.0", "5.5", "4.0", "3.0",
        "11.5", "-40.7", "calc_circumradius" };

    // Act
    Act(args);

    // Assert
    Assert("Circumradius of triangle ABC is equal = 48.7653");
}
