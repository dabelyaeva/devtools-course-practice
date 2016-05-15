// Copyright 2016 Voevodin Andrew

#include <gtest/gtest.h>
#include <math.h>
#include <vector>
#include <string>
#include "include/color_converter.h"


TEST(Color_Converter, Unexpect_Size_Is_Incorrect_In_HSVToRGB) {
    // Arrange
    vector<double> hsv{ 0.0, 0.0, 0.0, 0.0 };
    // Act & Assert
    EXPECT_THROW(ColorConverter::HSVToRGB(hsv), IncorrectSizeOfVector);
}

TEST(Color_Converter, Unexpect_Size_Is_Incorrect_In_HSVToLAB) {
    // Arrange
    vector<double> hsv{ 0.0, 0.0, 0.0, 0.0 };
    // Act & Assert
    EXPECT_THROW(ColorConverter::HSVToLAB(hsv), IncorrectSizeOfVector);
}

TEST(Color_Converter, Unexpect_Size_Is_Incorrect_In_RGBToLAB) {
    // Arrange
    vector<int> rgb{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(ColorConverter::RGBToLAB(rgb), IncorrectSizeOfVector);
}

TEST(Color_Converter, Unexpected_Incorrect_Size_In_LABToRGB) {
    // Arrange
    vector<int> lab{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(ColorConverter::LABToRGB(lab), IncorrectSizeOfVector);
}

TEST(Color_Converter, Unexpect_Size_Is_Incorrect_In_LABToHSV) {
    // Arrange
    vector<int> lab{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(ColorConverter::LABToHSV(lab), IncorrectSizeOfVector);
}

TEST(Color_Converter, Unexpect_Size_Is_Incorrect_In_RGBToHSV) {
    // Arrange
    vector<int> rgb{ 0, 0, 0, 0 };
    // Act & Assert
    EXPECT_THROW(ColorConverter::RGBToHSV(rgb), IncorrectSizeOfVector);
}

TEST(Color_Converter, Unexpect_H_Is_Incorrect_In_HSVToRGB) {
    // Arrange
    vector<double> hsv({ 5.0, 0.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::HSVToRGB(hsv), IncorrectValueOfHSV);
}

TEST(Color_Converter, Unexpect_S_Is_Incorrect_In_HSVToRGB) {
    // Arrange
    vector<double> hsv({ 0.0, 5.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::HSVToRGB(hsv), IncorrectValueOfHSV);
}

TEST(Color_Converter, Unexpect_V_Is_Incorrect_In_HSVToRGB) {
    // Arrange
    vector<double> hsv({ 0.0, 0.0, 5.0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::HSVToRGB(hsv), IncorrectValueOfHSV);
}

TEST(Color_Converter, Unexpect_H_Is_Incorrect_In_HSVToLAB) {
    // Arrange
    vector<double> hsv({ 5.0, 0.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::HSVToLAB(hsv), IncorrectValueOfHSV);
}

TEST(Color_Converter, Unexpect_S_Is_Incorrect_In_HSVToLAB) {
    // Arrange
    vector<double> hsv({ 0.0, 5.0, 0.0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::HSVToLAB(hsv), IncorrectValueOfHSV);
}

TEST(Color_Converter, Unexpect_V_Is_Incorrect_In_In_HSVToLAB) {
    // Arrange
    vector<double> hsv({ 0.0, 0.0, 5.0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::HSVToLAB(hsv), IncorrectValueOfHSV);
}

TEST(Color_Converter, Unexpect_L_Is_Incorrect_In_LABToRGB) {
    // Arrange
    vector<int> lab({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::LABToRGB(lab), IncorrectValueOfLAB);
}

TEST(Color_Converter, Unexpect_A_Is_Incorrect_In_LABToRGB) {
    // Arrange
    vector<int> lab({ 0, 200, 0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::LABToRGB(lab), IncorrectValueOfLAB);
}

TEST(Color_Converter, Unexpect_B_Is_Incorrect_In_LABToRGB) {
    // Arrange
    vector<int> lab({ 0, 0, 200 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::LABToRGB(lab), IncorrectValueOfLAB);
}

TEST(Color_Converter, Unexpect_L_Is_Incorrect_In_LABToHSV) {
    // Arrange
    vector<int> lab({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::LABToHSV(lab), IncorrectValueOfLAB);
}

TEST(Color_Converter, Unexpect_A_Is_Incorrect_In_LABToHSV) {
    // Arrange
    vector<int> lab({ 0, 200, 0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::LABToHSV(lab), IncorrectValueOfLAB);
}

TEST(Color_Converter, Unexpect_B_Is_Incorrect_In_LABToHSV) {
    // Arrange
    vector<int> lab({ 0, 0, 200 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::LABToHSV(lab), IncorrectValueOfLAB);
}

TEST(Color_Converter, Unexpect_R_Is_Incorrect_In_RGBToLAB) {
    // Arrange
    vector<int> rgb({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::RGBToLAB(rgb), IncorrectValueOfRGB);
}

TEST(Color_Converter, Unexpect_G_Is_Incorrect_In_RGBToLAB) {
    // Arrange
    vector<int> rgb({ 0, -1, 0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::RGBToLAB(rgb), IncorrectValueOfRGB);
}

TEST(Color_Converter, Unexpect_B_Is_Incorrect_In_RGBToLAB) {
    // Arrange
    vector<int> rgb({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::RGBToLAB(rgb), IncorrectValueOfRGB);
}

TEST(Color_Converter, Unexpect_R_Is_Incorrect_In_RGBToHSV) {
    // Arrange
    vector<int> rgb({ -1, 0, 0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::RGBToHSV(rgb), IncorrectValueOfRGB);
}

TEST(Color_Converter, Unexpect_G_Is_Incorrect_In_RGBToHSV) {
    // Arrange
    vector<int> rgb({ 0, -1, 0 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::RGBToHSV(rgb), IncorrectValueOfRGB);
}

TEST(Color_Converter, Unexpect_B_Is_Incorrect_In_RGBToHSV) {
    // Arrange
    vector<int> rgb({ 0, 0, -1 });
    // Act & Assert
    EXPECT_THROW(ColorConverter::RGBToHSV(rgb), IncorrectValueOfRGB);
}

TEST(Color_Converter, Check_HSVToRGB1) {
    // Arrange
    vector<double> hsv{ 0.0, 1.0, 1.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 255, 0, 0};
    // Act
    rgb = ColorConverter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_HSVToRGB2) {
    // Arrange
    vector<double> hsv{ 0.167, 1.0, 1.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 254, 255, 0 };
    // Act
    rgb = ColorConverter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_HSVToRGB3) {
    // Arrange
    vector<double> hsv{ 0.34, 1.0, 1.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 0, 255, 10 };
    // Act
    rgb = ColorConverter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_HSVToRGB4) {
    // Arrange
    vector<double> hsv{ 0.51, 1.0, 1.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 0, 239, 255 };
    // Act
    rgb = ColorConverter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_HSVToRGB5) {
    // Arrange
    vector<double> hsv{ 0.67, 1.0, 1.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 5, 0, 255 };
    // Act
    rgb = ColorConverter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_HSVToRGB6) {
    // Arrange
    vector<double> hsv{ 0.85, 1.0, 1.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 255, 0, 229 };
    // Act
    rgb = ColorConverter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_HSVToRGB7) {
    // Arrange
    vector<double> hsv{ 0.0, 0.0, 0.0 };
    vector<int> rgb(3);
    vector<int> rgb_res{ 0, 0, 0 };
    // Act
    rgb = ColorConverter::HSVToRGB(hsv);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_LABToRGB1) {
    // Arrange
    vector<int> lab{ 20, 10, 18 };
    vector<int> rgb;
    vector<int> rgb_res{ 69, 42, 22 };
    // Act
    rgb = ColorConverter::LABToRGB(lab);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_LABToRGB2) {
    // Arrange
    vector<int> lab{ 0, 0, 0 };
    vector<int> rgb;
    vector<int> rgb_res{ 0, 0, 0 };
    // Act
    rgb = ColorConverter::LABToRGB(lab);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_LABToRGB3) {
    // Arrange
    vector<int> lab{ 43, 0, -0 };
    vector<int> rgb;
    vector<int> rgb_res{ 102, 102, 102 };
    // Act
    rgb = ColorConverter::LABToRGB(lab);
    // Assert
    EXPECT_EQ(rgb, rgb_res);
}

TEST(Color_Converter, Check_RGBToHSV1) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 255, 0, 0 };
    vector<double> hsv_res{ 0.0, 1.0, 1.0 };
    // Act
    hsv = ColorConverter::RGBToHSV(rgb);
    // Assert
    EXPECT_EQ(hsv, hsv_res);
}

TEST(Color_Converter, Check_RGBToHSV2) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 0, 0, 0 };
    vector<double> hsv_res{ 0.0, 0.0, 0.0 };
    // Act
    hsv = ColorConverter::RGBToHSV(rgb);
    // Assert
    EXPECT_EQ(hsv, hsv_res);
}

TEST(Color_Converter, Check_RGBToHSV3) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 1, 0, 0 };
    // Act
    hsv = ColorConverter::RGBToHSV(rgb);
    // Assert
    EXPECT_NEAR(hsv[0], 0.0, 0.00001);
    EXPECT_NEAR(hsv[1], 1.0, 0.00001);
    EXPECT_NEAR(hsv[2], 0.00392157, 0.00001);
}

TEST(Color_Converter, Check_RGBToHSV4) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 0, 1, 0 };
    // Act
    hsv = ColorConverter::RGBToHSV(rgb);
    // Assert
    EXPECT_NEAR(hsv[0], 0.33333333, 0.00001);
    EXPECT_NEAR(hsv[1], 1.0, 0.00001);
    EXPECT_NEAR(hsv[2], 0.00392157, 0.00001);
}

TEST(Color_Converter, Check_RGBToHSV5) {
    // Arrange
    vector<double> hsv;
    vector<int> rgb{ 0, 0, 1 };
    // Act
    hsv = ColorConverter::RGBToHSV(rgb);
    // Assert
    EXPECT_NEAR(hsv[0], 0.666667, 0.00001);
    EXPECT_NEAR(hsv[1], 1.0, 0.00001);
    EXPECT_NEAR(hsv[2], 0.00392157, 0.00001);
}

TEST(Color_Converter, Check_LABToHSV) {
    // Arrange
    vector<double> hsv;
    vector<int> lab{ 20, 10, 10 };
    // Act
    hsv = ColorConverter::LABToHSV(lab);
    // Assert
    EXPECT_NEAR(hsv[0], 0.040404, 0.00001);
    EXPECT_NEAR(hsv[1], 0.492537, 0.00001);
    EXPECT_NEAR(hsv[2], 0.262745, 0.00001);
}


TEST(Color_Converter, Check_HSVToLAB) {
    // Arrange
    vector<double> hsv{ 0.0, 1.0, 1.0 };
    vector<int> lab;
    vector<int> lab_res{ 53, 80, 67 };
    // Act
    lab = ColorConverter::HSVToLAB(hsv);
    // Assert
    EXPECT_EQ(lab, lab_res);
}

TEST(Color_Converter, Check_RGBToLAB1) {
    // Arrange
    vector<int> rgb{ 255, 67, 0 };
    vector<int> lab;
    vector<int> lab_res{ 57, 68, 69 };
    // Act
    lab = ColorConverter::RGBToLAB(rgb);
    // Assert
    EXPECT_EQ(lab, lab_res);
}

TEST(Color_Converter, Check_RGBToLAB2) {
    // Arrange
    vector<int> rgb{ 0, 12, 0 };
    vector<int> lab;
    vector<int> lab_res{ 2, -5, 3 };
    // Act
    lab = ColorConverter::RGBToLAB(rgb);
    // Assert
    EXPECT_EQ(lab, lab_res);
}
