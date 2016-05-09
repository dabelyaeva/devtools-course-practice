// Copyright 2016 Polyakov Igor

#include "include/MatStat.h"

#include <string>
#include <cmath>
#include <vector>

using std::vector;


bool Sample::IsSummOfProbsEqualUnity(const vector<double> _prob) const {
    double sum_of_probabilities = 0.0;

    for (unsigned int i = 0; i < _prob.size(); i++) {
        sum_of_probabilities += _prob[i];
    }

    if (fabs(1.0 - sum_of_probabilities) > SAMPLE_EPSILON) {
        return false;
    }

    return true;
}

bool Sample::AreProbsCorrect(const vector<double> _prob) const {
    for (unsigned int i = 0; i < _prob.size(); i++) {
        if (_prob[i] <= 0.0 || _prob[i] > 1.0) {
            return false;
        }
    }

    if (!IsSummOfProbsEqualUnity(_prob)) {
        return false;
    }

    return true;
}

bool Sample::IsSampleCorrect(const vector<double> _sample) const {
    for (unsigned int i = 0; i < _sample.size() - 1; i++) {
        for (unsigned int j = i + 1; j < _sample.size(); j++) {
            if (_sample[i] == _sample[j]) {
                return false;
            }
        }
    }

    return true;
}

Sample::Sample() {
    sample_size = 1;
    sample = { 0.0 };
    probabilities = { 1.0 };
}

Sample::Sample(const vector<double> _sample,
               const vector<double> _probabilities) {
    if (_sample.size() != _probabilities.size()) {
        throw IncorrectSizesOfSampleAndProbs();
    } else {
        sample_size = _sample.size();
    }

    if (!AreProbsCorrect(_probabilities)) {
        throw IncorrectProbabilities();
    } else {
        probabilities = _probabilities;
    }

    if (!IsSampleCorrect(_sample)) {
        throw IncorrectSample();
    } else {
        sample = _sample;
    }
}

Sample::~Sample() {
}

Sample& Sample::operator=(const Sample& S) {
    sample_size = S.sample_size;
    sample = S.sample;
    probabilities = S.probabilities;

    return *this;
}

bool Sample::operator==(const Sample& S) const {
    if (sample_size < S.sample_size) {
        return false;
    }

    for (int i = 0; i < sample_size; i++) {
        if (sample[i] != S.sample[i] ||
            probabilities[i] != S.probabilities[i]) {
            return false;
        }
    }

    return true;
}

int Sample::GetSampleSize() const {
    return sample_size;
}

vector<double> Sample::GetSample() const {
    return sample;
}

vector<double> Sample::GetProbabilities() const {
    return probabilities;
}

double Sample::CalcMathematicalExpectation() const {
    double mathematical_expectation = 0.0;

    for (int i = 0; i < sample_size; i++) {
        mathematical_expectation += sample[i] * probabilities[i];
    }

    return mathematical_expectation;
}

double Sample::CalcMoment(const double relative_point,
                          const int exponent) const {
    double moment = 0.0;

    for (int i = 0; i < sample_size; i++) {
        double power = pow((sample[i] - relative_point), exponent);
        moment += power * probabilities[i];
    }

    return moment;
}

double Sample::CalcElementaryMoment(const int exponent) const {
    double elementary_moment = 0.0;

    for (int i = 0; i < sample_size; i++) {
        double power = pow(sample[i], exponent);
        elementary_moment += power * probabilities[i];
    }

    return elementary_moment;
}

double Sample::CalcDispersion() const {
    double dispersion = 0.0;
    double mathematical_expectation = CalcMathematicalExpectation();

    for (int i = 0; i < sample_size; i++) {
        double power = pow(sample[i] - mathematical_expectation, 2.0);
        dispersion += power * probabilities[i];
    }

    return dispersion;
}

double Sample::CalcAverageQuadraticDeviation() const {
    return sqrt(CalcDispersion());
}

double Sample::CalcCentralMoment(const int exponent) const {
    double central_moment = 0.0;
    double mathematical_expectation = CalcMathematicalExpectation();

    for (int i = 0; i < sample_size; i++) {
        double power = pow(sample[i] - mathematical_expectation, exponent);
        central_moment += power * probabilities[i];
    }

    return central_moment;
}
