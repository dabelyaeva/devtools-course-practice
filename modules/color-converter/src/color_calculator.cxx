// Copyright 2016 Polkanov Nikita

#include "include/color_calculator.h"
#include "include/Color_Converter.h"
#include <sstream>

using std::string;
using std::vector;

ColorCalculator::ColorCalculator() {}

string ColorCalculator::getHelp() {
    string help = string("Color calculator allows to convert between");
    help += " RGB, HSV and LAB color models.\n";
    help += "To convert color, type arguments in the following format:";
    help += " <source model> <value> <value> <value> <final model>\n";
    help += "Example: RGB 43 235 194 LAB";

    return help;
}

vector <double> intVectorToDoubleVector(vector <int> source) {
    vector <double> res(3);
    res[0] = source[0];
    res[1] = source[1];
    res[2] = source[2];
    return res;
}

vector <int> doubleVectorToIntVector(vector <double> source) {
    vector <int> res(3);
    res[0] = source[0];
    res[1] = source[1];
    res[2] = source[2];
    return res;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Incorrect number format!");
    }

    return value;
}

string ColorCalculator::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return getHelp();
    }
    string message;
    vector <double> result(3);

    if (validateArgsCount(argc)) {
        string source = argv[1];
        string final = argv[5];
        vector <double> values(3);
        try {
            values[0] = parseDouble(argv[2]);
            values[1] = parseDouble(argv[3]);
            values[2] = parseDouble(argv[4]);
        }
        catch (string str) {
            return str;
        }

        try {
            if (source.compare("RGB") == 0) {
                if (final.compare("LAB") == 0) {
                    result = intVectorToDoubleVector(
                            ColorConverter::RGBToLAB(doubleVectorToIntVector(values)));
                } else if (final.compare("HSV") == 0) {
                    result = ColorConverter::RGBToHSV(doubleVectorToIntVector(values));
                } else if (final.compare("RGB") == 0) {
                    result = values;
                } else {
                    message = "Unknown final model";
                }
            } else if (source.compare("LAB") == 0) {
                if (final.compare("RGB") == 0) {
                    result = intVectorToDoubleVector(
                            ColorConverter::LABToRGB(doubleVectorToIntVector(values)));
                } else if (final.compare("HSV") == 0) {
                    result = ColorConverter::LABToHSV(doubleVectorToIntVector(values));
                } else if (final.compare("LAB") == 0) {
                    result = values;
                } else {
                    message = "Unknown final model";
                }
            } else if (source.compare("HSV") == 0) {
                if (final.compare("LAB") == 0) {
                    result = intVectorToDoubleVector(
                            ColorConverter::HSVToLAB(values));
                } else if (final.compare("RGB") == 0) {
                    result = intVectorToDoubleVector(
                            ColorConverter::HSVToRGB(values));
                } else if (final.compare("HSV") == 0) {
                    result = values;
                } else {
                    message = "Unknown final model";
                }
            } else {
                message = "Unknown source model";
            }
        } catch (std::runtime_error err) {
            message = err.what();
        }
    } else {
        message = "Incorrect arguments count";
    }

    if (message.size() == 0) {
        std::ostringstream stream;
        stream << result[0] << " " << result[1] << " " << result[2];
        message = stream.str();
    }
    return message;
}

bool ColorCalculator::validateArgsCount(int argc) {
    if (argc == 6) {
        return true;
    }
    else {
        return false;
    }
}
