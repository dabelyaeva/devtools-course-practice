// Copyright 2016 Hramov Ilya

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/volumes_calc_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class VolumeCalcTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

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

TEST_F(VolumeCalcTest, can_create_app) {
    // Arrange
    Application* app;

    // Act
    app = new Application();

    // Assert
    EXPECT_NE(nullptr, app);
    delete app;
}

TEST_F(VolumeCalcTest, Can_Show_Help_With_Epmty_Arguments) {
    // Arrange
     std::vector<string> args = {};

     // Act
     Act(args);

     // Assert
     Assert("This is volumes calculator application\\..*");
  }

TEST_F(VolumeCalcTest, Can_Check_Sphere_Parametres_Number) {
    // Arrange
    std::vector<string> args = {"sphere", "2.0", "3.0", "aabb"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong number of parametres for \'sphere\'.*");
}

TEST_F(VolumeCalcTest, Can_Check_Cylinder_Parametres_Number) {
    // Arrange
    std::vector<string> args = {"cylinder", "2.0"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong number of parametres for \'cylinder\'.*");
}

TEST_F(VolumeCalcTest, Can_Check_Volumes_Name_Correctness) {
    // Arrange
    std::vector<string> args = {"some_name", "2.0"};

    // Act
    Act(args);

    // Assert
    Assert("Invalid volume name.*");
}

TEST_F(VolumeCalcTest, Can_Check_Number_Input_Correctness) {
    // Arrange
    std::vector<string> args = {"sphere", "not_number"};

    // Act
    Act(args);

    // Assert
    Assert("Invalid number format!.*");
}
