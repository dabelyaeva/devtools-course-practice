// Copyright 2016 Polyakov Igor

#ifndef MODULES_MATSTAT_INCLUDE_MATSTAT_H_
#define MODULES_MATSTAT_INCLUDE_MATSTAT_H_

#include <vector>
#include <stdexcept>

using std::vector;

const double SAMPLE_EPSILON = 0.001;


class IncorrectSample :public std::runtime_error {
 public:
     IncorrectSample() :
     std::runtime_error("Sample is not correct, values must be different") {}
};

class IncorrectProbabilities :public std::runtime_error {
 public:
    IncorrectProbabilities() :
    std::runtime_error ("\nSum of probabilities must be equal 1") {}
};

class IncorrectSizesOfSampleAndProbs :public std::runtime_error {
 public:
     IncorrectSizesOfSampleAndProbs() :
     std::runtime_error("Sizes of sample and probs must be identical") {}
};


class Sample {
 public:
    Sample();
    Sample(const vector<double> sample,
           const vector<double> probabilities);
    ~Sample();

    Sample& operator=(const Sample& S);
    bool operator==(const Sample& S) const;

    int GetSampleSize() const;
    vector<double> GetSample() const;
    vector<double> GetProbabilities() const;

    double CalcMathematicalExpectation() const;
    double CalcMoment(const double relative_point, const int exponent) const;
    double CalcElementaryMoment(const int exponent) const;
    double CalcDispersion() const;
    double CalcAverageQuadraticDeviation() const;
    double CalcCentralMoment(const int exponent) const;

private:
    int sample_size;
    vector<double> sample;
    vector<double> probabilities;

    bool IsSummOfProbsEqualUnity(const vector<double> _pr) const;
    bool AreProbsCorrect(const vector<double> _pr) const;
    bool IsSampleCorrect(const vector<double> _sample) const;
};

#endif  // MODULES_MATSTAT_INCLUDE_MATSTAT_H_
