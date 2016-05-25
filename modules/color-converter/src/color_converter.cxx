// Copyright 2016 Voevodin Andrew

#include "include/color_converter.h"
#include <math.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

const vector<vector<double>> ColorConverter::kMatrCoefXYZToRGB{
    { 3.2404542, -1.5371385, -0.4985314 },
    { -0.9693660, 1.87560108, 0.0415560},
    { 0.0556434, -0.2040259, 1.0572252},
};

const vector<vector<double>> ColorConverter::kMatrCoefRGBToXYZ{
    { 0.4124564, 0.3575761, 0.1804375 },
    { 0.2126729, 0.7151522, 0.0721750 },
    { 0.0193339, 0.1191920, 0.9503041 },
};

const double ColorConverter::kEpsilonInLAB = 0.008856;
const double ColorConverter::kEpsilonInRGBToXYZ = 0.04045;
const double ColorConverter::kEpsilonInXYZToRGB = 0.0031308;
const double ColorConverter::kMaxValueInRGB = 255.0;
const double ColorConverter::kNormalizingNumberXYZToRGB = 100.0;
const double ColorConverter::kKInLAB = 7.787;
const vector<double> ColorConverter::
           kNormalizingVectorXYZToLAB{ 95.047, 100.000, 108.883 };

bool ColorConverter::IsVectorSizeCorrect(const vector<double>& vector) {
    if (vector.size() != 3) return false;
    return true;
}

bool ColorConverter::IsVectorSizeCorrect(const vector<int>& vector) {
    if (vector.size() != 3) return false;
    return true;
}

bool ColorConverter::IsRGBVectorInRange(const vector<int>& rgb) {
    for (size_t i = 0; i < rgb.size(); i++)
        if ((rgb[i] > 255) || (rgb[i] < 0)) return false;
    return true;
}

bool ColorConverter::IsHSVVectorInRange(const vector<double>& hsv) {
    for (size_t i = 0; i < hsv.size(); i++)
        if ((hsv[i] > 1.0) || (hsv[i] < 0.0)) return false;
    return true;
}

bool ColorConverter::IsLABVectorInRange(const vector<int>& lab) {
    if ((lab[0] > 100) || (lab[0] < 0) ||
        (lab[1] > 128) || (lab[1] < -127) ||
        (lab[2] > 128) || (lab[2] < -127)) return false;
    return true;
}

vector<int> ColorConverter::XYZToRGB(const vector<double>& xyz) {
    vector<int> rgb(3);
    vector<double> norm_rgb(3);
    vector<double> norm_xyz(3);
    for (size_t i = 0; i < norm_xyz.size(); i++)
        norm_xyz[i] = xyz[i] / kNormalizingNumberXYZToRGB;

    for (size_t i = 0; i < norm_rgb.size(); i++)
        for (size_t j = 0; j < kMatrCoefRGBToXYZ[i].size(); j++)
            norm_rgb[i] = norm_rgb[i] + norm_xyz[j] * kMatrCoefXYZToRGB[i][j];

    for (size_t i = 0; i < norm_xyz.size(); i++) {
        if (norm_rgb[i] > kEpsilonInXYZToRGB)
           norm_rgb[i] = 1.055 * pow(norm_rgb[i], (1.0 / 2.4)) - 0.055;
        else
            norm_rgb[i] = 12.92 * norm_rgb[i];
    }

    for (size_t i = 0; i < norm_xyz.size(); i++) {
        rgb[i] = static_cast<int>(norm_rgb[i] * kMaxValueInRGB + 0.5);
    }
    return rgb;
}

vector<int> ColorConverter::XYZToLAB(const vector<double>& xyz) {
    vector<int> lab(3);
    vector<double> lab_res(3);
    vector<double> norm_xyz(3);
    for (size_t i = 0; i < norm_xyz.size(); i++)
         norm_xyz[i] = xyz[i] / kNormalizingVectorXYZToLAB[i];

    for (size_t i = 0; i < norm_xyz.size(); i++) {
        if (norm_xyz[i] > kEpsilonInLAB)
            norm_xyz[i] = pow(norm_xyz[i], (1.0 / 3.0));
        else
            norm_xyz[i] = (kKInLAB * norm_xyz[i]) + (16.0 / 116.0);
    }

    lab_res[0] = ((116.0 * norm_xyz[1]) - 16.0);
    lab_res[1] = (500.0 * (norm_xyz[0] - norm_xyz[1]));
    lab_res[2] = (200.0 * (norm_xyz[1] - norm_xyz[2]));
    for (size_t i = 0; i < lab.size(); i++) {
        if (lab_res[i] < 0) {
             lab[i] = static_cast<int>(lab_res[i] - 0.5);
        } else {
            lab[i] = static_cast<int>(lab_res[i] + 0.5);
        }
    }
    return lab;
}

vector<double> ColorConverter::RGBToXYZ(const vector<int>& rgb) {
    vector<double> xyz_res{ 0.0, 0.0, 0.0 };
    vector<double> norm_rgb(3);
    for (size_t i = 0; i < xyz_res.size(); i++)
         norm_rgb[i] = (1.0*rgb[i] / kMaxValueInRGB);

    for (size_t i = 0; i < norm_rgb.size(); i++) {
        if (norm_rgb[i] > kEpsilonInRGBToXYZ)
            norm_rgb[i] = pow(((norm_rgb[i] + 0.055) / 1.055), 2.4);
        else
            norm_rgb[i] = norm_rgb[i] / 12.92;
    }

    for (size_t i = 0; i < xyz_res.size(); i++)
        for (size_t j = 0; j < kMatrCoefRGBToXYZ[i].size(); j++)
            xyz_res[i] += norm_rgb[j] *
                       kNormalizingNumberXYZToRGB * kMatrCoefRGBToXYZ[i][j];
    return xyz_res;
}

vector<double> ColorConverter::LABToXYZ(const vector<int>& lab) {
    vector<double> xyz_res(3);
    vector<double> norm_xyz(3);

    norm_xyz[1] = (1.0*lab[0] + 16.0) / 116.0;
    norm_xyz[0] = 1.0*lab[1] / 500.0 + norm_xyz[1];
    norm_xyz[2] = norm_xyz[1] - 1.0*lab[2] / 200.0;

    for (size_t i = 0; i < xyz_res.size(); i++) {
         if (pow(norm_xyz[i], 3) > kEpsilonInLAB)
             norm_xyz[i] = pow(norm_xyz[i], 3.0);
         else
             norm_xyz[i] = (norm_xyz[i] - 16.0 / 116.0) / kKInLAB;
    }

    for (size_t i = 0; i < xyz_res.size(); i++)
         xyz_res[i] = kNormalizingVectorXYZToLAB[i] * norm_xyz[i];
    return xyz_res;
}

vector<int> ColorConverter::HSVToRGB(const vector<double>& hsv) {
    if (!IsVectorSizeCorrect(hsv)) throw IncorrectSizeOfVector();
    if (!IsHSVVectorInRange(hsv)) throw IncorrectValueOfHSV();
    vector<int> rgb_res(3);
    vector<double> norm_rgb(3);
    vector<double> intermediate_hsv(3);

    if (hsv[1] == 0.0) {
       for (size_t i = 0; i < rgb_res.size(); i++)
            rgb_res[i] = hsv[2] * kMaxValueInRGB;
    } else {
        double normalized_angle_H = hsv[0] * 6.0;
        int normalized_basis_angle_H =
                       static_cast<int>(normalized_angle_H + 0.5);
        if (normalized_basis_angle_H == 6) normalized_angle_H = 0;
        intermediate_hsv[0] = hsv[2] * (1.0 - hsv[1]);
        intermediate_hsv[1] = hsv[2] * (1.0 - hsv[1] *
           (normalized_angle_H - normalized_basis_angle_H));
        intermediate_hsv[2] = hsv[2] * (1.0 - hsv[1] *
           (1.0 - (normalized_angle_H - normalized_basis_angle_H)));
        switch ((normalized_basis_angle_H)) {
        case 0:
            norm_rgb[0] = hsv[2];
            norm_rgb[1] = intermediate_hsv[2];
            norm_rgb[2] = intermediate_hsv[0];
            break;
        case 1:
            norm_rgb[0] = intermediate_hsv[1];
            norm_rgb[1] = hsv[2];
            norm_rgb[2] = intermediate_hsv[0];
            break;
        case 2:
            norm_rgb[0] = intermediate_hsv[0];
            norm_rgb[1] = hsv[2];
            norm_rgb[2] = intermediate_hsv[2];
            break;
        case 3:
            norm_rgb[0] = intermediate_hsv[0];
            norm_rgb[1] = intermediate_hsv[1];
            norm_rgb[2] = hsv[2];
            break;
        case 4:
            norm_rgb[0] = intermediate_hsv[2];
            norm_rgb[1] = intermediate_hsv[0];
            norm_rgb[2] = hsv[2];
            break;
        default:
            norm_rgb[0] = hsv[2];
            norm_rgb[1] = intermediate_hsv[0];
            norm_rgb[2] = intermediate_hsv[1];
            break;
        }
    for (size_t i = 0; i < rgb_res.size(); i++)
        rgb_res[i] = static_cast<int>(norm_rgb[i] * kMaxValueInRGB);
    }
    return rgb_res;
}

vector<int> ColorConverter::LABToRGB(const vector<int>& lab) {
    if (!IsVectorSizeCorrect(lab)) throw IncorrectSizeOfVector();
    if (!IsLABVectorInRange(lab)) throw IncorrectValueOfLAB();
    return XYZToRGB(LABToXYZ(lab));
}


vector<double> ColorConverter::RGBToHSV(const vector<int>& rgb) {
    if (!IsVectorSizeCorrect(rgb)) throw IncorrectSizeOfVector();
    if (!IsRGBVectorInRange(rgb)) throw IncorrectValueOfRGB();
    vector<double> hsv(3);
    vector<int> rgb_res(rgb);
    vector<double> norm_rgb(3);
    vector<double> del_RGB(3);
    for (size_t i = 0; i < norm_rgb.size(); i++)
        norm_rgb[i] = (1.0*rgb_res[i] / kMaxValueInRGB);

    double current_min_value_in_rgb = 1.0 * rgb_res[0] / kMaxValueInRGB;
    double current_max_value_in_rgb = 1.0 * rgb_res[0] / kMaxValueInRGB;
    for (size_t i = 1; i < rgb_res.size(); i++) {
        if (1.0*rgb_res[i] / kMaxValueInRGB < current_min_value_in_rgb)
         current_min_value_in_rgb = 1.0*rgb_res[i] / kMaxValueInRGB;
        if (1.0*rgb_res[i] / kMaxValueInRGB > current_max_value_in_rgb)
         current_max_value_in_rgb = 1.0*rgb_res[i] / kMaxValueInRGB;
    }
    double dif_max_in_rgb = current_max_value_in_rgb - current_min_value_in_rgb;
    hsv[2] = current_max_value_in_rgb;
    if (dif_max_in_rgb == 0) {
        hsv[0] = 0.0;
        hsv[1] = 0.0;
    } else {
        hsv[1] = dif_max_in_rgb / current_max_value_in_rgb;

        for (size_t i = 0; i < del_RGB.size(); i++)
            del_RGB[i] = (((current_max_value_in_rgb - norm_rgb[i]) / 6.0) +
                           (dif_max_in_rgb / 2.0)) / dif_max_in_rgb;

        if (norm_rgb[0] == current_max_value_in_rgb)
            hsv[0] = del_RGB[2] - del_RGB[1];
        else if (norm_rgb[1] == current_max_value_in_rgb)
            hsv[0] = (1.0 / 3.0) + del_RGB[0] - del_RGB[2];
        else if (norm_rgb[2] == current_max_value_in_rgb)
            hsv[0] = (2.0 / 3.0) + del_RGB[1] - del_RGB[0];

        if (hsv[0] < 0.0) hsv[0] += 1.0;
        if (hsv[0] > 1.0) hsv[0] -= 1.0;
    }
    return hsv;
}

vector<double> ColorConverter::LABToHSV(const vector<int>& lab) {
    if (!IsVectorSizeCorrect(lab)) throw IncorrectSizeOfVector();
    if (!IsLABVectorInRange(lab)) throw IncorrectValueOfLAB();
    return RGBToHSV(LABToRGB(lab));
}


vector<int> ColorConverter::RGBToLAB(const vector<int>& rgb) {
    if (!IsVectorSizeCorrect(rgb)) throw IncorrectSizeOfVector();
    if (!IsRGBVectorInRange(rgb)) throw IncorrectValueOfRGB();
    return XYZToLAB(RGBToXYZ(rgb));
}

vector<int> ColorConverter::HSVToLAB(const vector<double>& hsv) {
    if (!IsVectorSizeCorrect(hsv)) throw IncorrectSizeOfVector();
    if (!IsHSVVectorInRange(hsv)) throw IncorrectValueOfHSV();
    return RGBToLAB(HSVToRGB(hsv));
}
