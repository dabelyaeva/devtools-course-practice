// Copyright 2016 Zhiltsov Max

#ifndef VOLUMES_CALC_H_
#define VOLUMES_CALC_H_

#include <functional>

namespace volume_calc {

template<class Ret, class... Args>
using function = std::function<Ret(Args...)>;

/*
Function performs numerical computation of a Riemann integral for a given
function in a given boundaries with a given step.

Parameters:
  lower - lower boundary of intergation interval,
  upper - upper boundary of intergation interval,
  f     - function to be integrated,
  partitionCount - count of partitions in the integration process.

Template parameters:
  NumberType - numerical type used in computation. Computation results depends
    on numerical stability of this type.
  Function   - type of function to be computed.

Return value:
  Number of type NumberType, the result of computation.

Usage examples:

// Simple integral of x^2 on interval [0, 30] with a step = (30 - 0) / 1000:
double result = integrate<double>(0, 30,
    [] (double x) { return x * x; }, 1000
); // returns approximately 30^3 / 3 = 9000

*/
template<class NumberType,
    class Function = function<NumberType, const NumberType&>
>
NumberType integrate(const NumberType& lower, const NumberType& upper,
    const Function& f, size_t partitionCount);

/*
Class for numerical integration of given function in given boundaries
accoridng to a formula:
  volume = integral(a, b, dx, integral(g, h, dy, integral(u, v, dz, f))),
where
  f = f(x, y) - function to be integrated,
  a - const   - first integral lower boundary,
  b - const   - first integral upper boundary,
  g = g(x)    - second internal lower boundary,
  h = h(x)    - second internal upper boundary,
  u = u(x, y) - third internal lower boundary,
  v = v(x, y) - third internal upper boundary.

It allows to use a dependent boundary functions for inner boundaries (functions
g(x) and h(x), u(x, y) and v(x, y)).

Class template parameter NumberType allows to use a custom numerical types in
calculations.

Usage warning:
  It is up to user to control the correctness of a given functions.

Usage examples:

// Calculate a voulme of a sphere with radius 10:
VolumeCalculator<double> calculator (
    [] (double, double theta, double r) {
        return r * r * std::cos(theta);
    },
    0.0,
    2.0 * MATH_PI,
    [] (double) { return - 0.5 * MATH_PI; },
    [] (double) { return + 0.5 * MATH_PI; },
    [] (double, double) { return 0.0; },
    [] (double, double) { return 10.0; }
);
double sphereVolume = calculator.Calculate(200); // approx. 4/3 * MATH_PI * 10^3

// Calculate a volume of a cylinder with radius 5 and height 10:
VolumeCalculator<float> calculator (
    [] (float, float r, float) {
        return r;
    },
    0.f,
    2.f * MATH_PI,
    [] (float) { return 0.f; },
    [] (float) { return 5.f; },
    [] (float, float) { return 0.f; },
    [] (float, float) { return 10.f; }
);
float cylinderVolume = calculator.Calculate();

*/
template<class NumberType = double>
class VolumeCalculator {
 public:
    using Boundary2Func = function<NumberType, const NumberType&>;
    using Boundary3Func = function<
        NumberType, const NumberType&, const NumberType&>;
    using Func = function<
        NumberType, const NumberType&, const NumberType&, const NumberType&>;

    /*
    Initialization constructor.
    */
    VolumeCalculator(const Func& func,
        const NumberType& boundary1Min,
        const NumberType& boundary1Max,
        const Boundary2Func& boundary2Min,
        const Boundary2Func& boundary2Max,
        const Boundary3Func& boundary3Min,
        const Boundary3Func& boundary3Max);

 private:
    static constexpr size_t kDefaultPartitionCount = 100;

 public:
    /*
    Calculates the volume of a figure with the specified description by a
    numerical integration.

    Function parameters:
      partitionCount - count of partitions in integration process. The higher is
        this value, the more accurate the results is and the higher duration of
        computations is. Note that this partition count is applied to each
        integral, so complexity grows approximately as n^3.

    Return value:
      Number of type NumberType, the result of computation.

    */
    NumberType Calculate(size_t partitionCount = kDefaultPartitionCount);

    /*
    Calculates the volume of a figure with the specified description by a
    numerical integration.

    Function parameters:
      partitionCount(1, 2, 3) - count of partitions in integration process.
        The higher is this value, the more accurate the results is and the
        higher duration of computations is. These partition counts is applied
        separately to each integral, so complexity grows approximately
        as n1*n2*n3. Index 1, 2 or 3 stands for integral position, starting from
        outer one.

    Return value:
      Number of type NumberType, the result of computation.

    */
    NumberType Calculate(size_t partitionCount1,
        size_t partitionCount2, size_t partitionCount3);

 private:
    NumberType boundary1Min;
    NumberType boundary1Max;
    Boundary2Func boundary2Min;
    Boundary2Func boundary2Max;
    Boundary3Func boundary3Min;
    Boundary3Func boundary3Max;
    Func func;
};


// Implementation

template<class NumberType, class Function>
NumberType integrate(const NumberType& lower, const NumberType& upper,
    const Function& f, size_t partitionCount
) {
    const auto step = (upper - lower) / partitionCount;
    NumberType result(0);
    for (size_t i = 1; i <= partitionCount; ++i) {
        const auto midPoint = std::rand() / NumberType(RAND_MAX) * step;
        result += f(lower + step * (i - 1) + midPoint) * step;
    }
    return result;
}

template<class NumberType>
VolumeCalculator<NumberType>::VolumeCalculator(const Func& func,
    const NumberType& boundary1Min, const NumberType& boundary1Max,
    const Boundary2Func& boundary2Min, const Boundary2Func& boundary2Max,
    const Boundary3Func& boundary3Min, const Boundary3Func& boundary3Max
) :
    boundary1Min(boundary1Min),
    boundary1Max(boundary1Max),
    boundary2Min(boundary2Min),
    boundary2Max(boundary2Max),
    boundary3Min(boundary3Min),
    boundary3Max(boundary3Max),
    func(func)
{}

template<class NumberType>
NumberType VolumeCalculator<NumberType>::Calculate(size_t partitionCount) {
    return integrate(boundary1Min, boundary1Max,
        [this, partitionCount] (const NumberType& x) {
            return integrate(boundary2Min(x), boundary2Max(x),
                [this, x, partitionCount] (const NumberType& y) {
                    return integrate(boundary3Min(x, y), boundary3Max(x, y),
                        [this, x, y, partitionCount] (const NumberType& z) {
                            return func(x, y, z);
                        },
                        partitionCount);
                },
                partitionCount);
        },
        partitionCount);
}

template<class NumberType>
NumberType VolumeCalculator<NumberType>::Calculate(size_t partitionCount1,
    size_t partitionCount2, size_t partitionCount3
) {
    return integrate(boundary1Min, boundary1Max,
        [this, partitionCount1, partitionCount2, partitionCount3] (
            const NumberType& x
        ) {
            return integrate(boundary2Min(x), boundary2Max(x),
                [this, x, partitionCount2, partitionCount3] (
                    const NumberType& y
                ) {
                    return integrate(boundary3Min(x, y), boundary3Max(x, y),
                        [this, x, y, partitionCount3] (const NumberType& z) {
                            return func(x, y, z);
                        },
                        partitionCount3);
                },
                partitionCount2);
        },
        partitionCount1);
}

}  // namespace volume_calc

#endif  // VOLUMES_CALC_H_
