// Copyright 2016 Voevodin Andrew

#ifndef MODULES_COLOR_CONVERTER_INCLUDE_COLOR_CONVERTER_H_
#define MODULES_COLOR_CONVERTER_INCLUDE_COLOR_CONVERTER_H_

#include <math.h>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;
using std::vector;

class IncorrectValueOfRGB :public std::runtime_error {
 public:
    IncorrectValueOfRGB() :
        std::runtime_error("Value RGB is not correct, values - 0 to 255") {}
};

class IncorrectValueOfHSV :public std::runtime_error {
 public:
    IncorrectValueOfHSV() :
        std::runtime_error("Value HSV is not correct, H: 0-1; S,V: 0-1") {}
};

class IncorrectValueOfLAB :public std::runtime_error {
 public:
    IncorrectValueOfLAB() :
        std::runtime_error("Value LAB is not correct,L:0-100;a,b:-127-128") {}
};

class IncorrectSizeOfVector :public std::runtime_error {
 public:
    IncorrectSizeOfVector() :
        std::runtime_error("Size vector is not correct, size must be - 3") {}
};

class ColorConverter {
 public:
    static vector<int> HSVToRGB(const vector<double>& hsv);
    static vector<int> LABToRGB(const vector<int>& lab);

    static vector<double> RGBToHSV(const vector<int>& rgb);
    static vector<double> LABToHSV(const vector<int>& lab);

    static vector<int> RGBToLAB(const vector<int>& rgb);
    static vector<int> HSVToLAB(const vector<double>& hsv);

 private:
    static const vector<vector<double>> kMatrCoefRGBToXYZ;
    static const double kEpsilonInLAB;
    static const double kEpsilonInRGBToXYZ;
    static const double kEpsilonInXYZToRGB;
    static const double kMaxValueInRGB;
    static const double kNormalizingNumberXYZToRGB;
    static const double kKInLAB;
    static const vector<double> kNormalizingVectorXYZToLAB;
    static const vector<vector<double>> kMatrCoefXYZToRGB;

    static bool IsVectorSizeCorrect(const vector<double>& vector);
    static bool IsVectorSizeCorrect(const vector<int>& vector);
	static bool IsRGBVectorInRange(const vector<int>& rgb);
	static bool IsHSVVectorInRange(const vector<double>& hsv);
	static bool IsLABVectorInRange(const vector<int>& lab);

    static vector<int> XYZToRGB(const vector<double>& xyz);
    static vector<int> XYZToLAB(const vector<double>& xyz);

    static vector<double> RGBToXYZ(const vector<int>& rgb);
    static vector<double> LABToXYZ(const vector<int>& lab);
};
#endif  // MODULES_COLOR_CONVERTER_INCLUDE_COLOR_CONVERTER_H_
