// Copyright 2016 Zhiltsov Max

#include <cmath>
#include <functional>
#include <limits>

#include "gtest/gtest.h"
#include "volumes_calc.hpp"


static constexpr double pi = 3.1415926535897932384626433832795;

TEST(VolumeCalculatorTest, Example_1_Is_Working) {
    // Arrange
    static constexpr double expectedVolume = 4188.7902047863909846168578443727;

    // Act
    volume_calc::VolumeCalculator<double> calculator {
        [] (double phi, double theta, double r) {
            return r * r * std::cos(theta);
        },
        0.0,
        2.0 * pi,
        [] (double x) { return - 0.5 * pi; },
        [] (double x) { return + 0.5 * pi; },
        [] (double x, double y) { return 0.0; },
        [] (double x, double y) { return 10.0; }
    };
    const double calculatedVolume = calculator.Calculate(200);

    // Assert
    ASSERT_NEAR(expectedVolume, calculatedVolume, 0.0001 * expectedVolume);
}

TEST(VolumeCalculatorTest, Example_2_Is_Working) {
    // Arrange
    static constexpr float expectedVolume = 785.39816339744830961566084581988f;

    // Act
    volume_calc::VolumeCalculator<float> calculator {
        [] (float phi, float r, float h) {
            return r;
        },
        0.f,
        2.f * pi,
        [] (float phi) { return 0.f; },
        [] (float phi) { return 5.f; },
        [] (float phi, float r) { return 0.f; },
        [] (float phi, float r) { return 10.f; }
    };
    float cylinderVolume = calculator.Calculate();

    // Assert
    ASSERT_NEAR(expectedVolume, cylinderVolume, 0.001f * expectedVolume);
}


TEST(IntegrateTest, Example_1_Is_Working) {
    // Arrange
    static constexpr double expectedResult = 9000.0;

    // Act
    double result = volume_calc::integrate<double>(0, 30,
        [] (double x) { return x * x; }, 1000);

    // Assert
    ASSERT_NEAR(expectedResult, result, 0.0001 * expectedResult);
}

TEST(IntegrateTest, Zero_Sections_Leads_To_Zero_Result) {
    // Arrange
    static constexpr double expectedResult = 0.0;

    // Act
    double result = volume_calc::integrate<double>(50, 300,
        [] (double x) { return x; }, 0);

    // Assert
    ASSERT_NEAR(expectedResult, result, 0.0001 * expectedResult);
}

TEST(IntegrateTest, Equal_Boundaries_Leads_To_Zero_Result) {
    // Arrange
    static constexpr double expectedResult = 0.0;

    // Act
    double result = volume_calc::integrate<double>(50, 50,
        [] (double x) { return x; }, 10);

    // Assert
    ASSERT_NEAR(expectedResult, result, 0.0001 * expectedResult);
}

TEST(IntegrateTest, Inversed_Boundaries_Is_Not_A_Fault) {
    // Arrange
    static constexpr double expectedResult = -9000.0;

    // Act
    double result = volume_calc::integrate<double>(30, 0,
        [] (double x) { return x * x; }, 1200);

    // Assert
    ASSERT_NEAR(expectedResult, result, -0.0001 * expectedResult);
}

TEST(IntegrateTest, Inversed_Boundaries_Leads_To_Negation) {
    // Arrange, act
    double resultInv = volume_calc::integrate<double>(30, 0,
        [] (double x) { return x; }, 500);
    double result = volume_calc::integrate<double>(0, 30,
        [] (double x) { return x; }, 500);

    // Assert
    ASSERT_NEAR(result, -1.0 * resultInv, 0.0001 * std::abs(result));
}

TEST(IntegrateTest, Linearity_Of_Boundaries_Is_Existing) {
    // Arrange
    static constexpr double expectedResult = 450.0;

    // Act
    double first = volume_calc::integrate<double>(0, 10,
        [] (double x) { return x; }, 500);
    double second = volume_calc::integrate<double>(10, 30,
        [] (double x) { return x; }, 500);

    // Assert
    ASSERT_NEAR(expectedResult, first + second, 0.0001 * expectedResult);
}

TEST(IntegrateTest, Linearity_Of_Function_Is_Existing) {
    // Arrange
    static constexpr double expectedResult = 50.0 + 333.333;

    // Act
    double first = volume_calc::integrate<double>(0, 10,
        [] (double x) { return x; }, 1000);
    double second = volume_calc::integrate<double>(0, 10,
        [] (double x) { return x * x; }, 1000);

    // Assert
    ASSERT_NEAR(expectedResult, first + second, 0.0001 * expectedResult);
}

TEST(IntegrateTest, Null_Function_Is_Error) {
    // Arrange, act, assert
    ASSERT_ANY_THROW(volume_calc::integrate(0, 10,
        volume_calc::function<int, int>(), 10));
}

TEST(IntegrateTest, Infinite_Boundaries_Leads_To_Nonfinite_Results) {
    // Arrange, act
    double result = volume_calc::integrate(
        std::numeric_limits<double>::signaling_NaN(),
        +std::numeric_limits<double>::infinity(),
        [] (double x) { return std::exp(-x); }, 1);

    // Assert
    ASSERT_FALSE(std::isfinite(result));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
