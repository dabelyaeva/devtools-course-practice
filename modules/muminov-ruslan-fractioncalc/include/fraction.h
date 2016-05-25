// Copyright 2016 Muminov_Ruslan

#ifndef MODULES_MUMINOV_RUSLAN_FRACTIONCALC_INCLUDE_FRACTION_H_
#define MODULES_MUMINOV_RUSLAN_FRACTIONCALC_INCLUDE_FRACTION_H_

class fraction {
 public:
    fraction();
    fraction(int numerator, int denominator);
    fraction(const fraction& z);

    fraction& operator=(const fraction& z);

    int getNum() const;
    int getDenom() const;
    void setNum(int numerator);
    void setDenom(int denominator);

    fraction operator + (const fraction& z) const;
    fraction operator - (const fraction& z) const;
    fraction operator * (const fraction& z) const;
    fraction operator / (const fraction& z) const;

    bool operator == (const fraction& z) const;
    bool operator != (const fraction& z) const;

 private:
    bool equalsZero(const fraction& z) const;
    int NOD() const;
    void reduction();
    int numerator_;
    int denominator_;
};

#endif  // MODULES_MUMINOV_RUSLAN_FRACTIONCALC_INCLUDE_FRACTION_H_
