// Copyright 2016 Polkanov Nikita

#include "include/hypothec_calculator.h"
#include <math.h>
#include <stdexcept>


const int HypothecCalculator::DEFAULT_PROPERTY_COST = 3000000;
const int HypothecCalculator::DEFAULT_PERCENT = 12;
const double HypothecCalculator::DEFAULT_FIRST_PAYMENT_PERCENT = 0.2;
const int HypothecCalculator::DEFAULT_TERM = 180;

const int HypothecCalculator::MAX_TERM = 600;
const int HypothecCalculator::MAX_PERCENT = 100;
const int HypothecCalculator::MONTHS_IN_YEAR = 12;

HypothecCalculator::HypothecCalculator() {
    resetDefaults();
}

HypothecCalculator::HypothecCalculator(
        const int property_cost,
        const int first_payment,
        const int term,
        const int percent) {
    if (first_payment <= 0) {
        throw std::invalid_argument("First payment must be bigger than 0");
    }

    if (property_cost <= 0) {
        throw std::invalid_argument("Property cost must be bigger than 0");
    }

    if (first_payment >= property_cost) {
        throw std::invalid_argument(
                "First payment must be lesser than property cost");
    }

    if (percent <= 0 || percent >= MAX_PERCENT) {
        throw std::invalid_argument(
                "Percent must be bigger than 0 and lesser than 100");
    }

    if (term <= 0 || term > MAX_TERM) {
        throw std::invalid_argument(
                "Term must be bigger than 0 and lesser than 601");
    }

    property_cost_ = property_cost;
    first_payment_ = first_payment;
    term_ = term;
    percent_ = percent;
    monthly_payment_ = 0;
    overpayment_ = 0;
}

void HypothecCalculator::resetDefaults() {
    property_cost_ = DEFAULT_PROPERTY_COST;
    first_payment_ = property_cost_ * DEFAULT_FIRST_PAYMENT_PERCENT;
    term_ = DEFAULT_TERM;
    percent_ = DEFAULT_PERCENT;
    monthly_payment_ = 0;
    overpayment_ = 0;
}

void HypothecCalculator::calculate() {
    int hypothec_amount = property_cost_ - first_payment_;
    if (hypothec_amount <= 0) {
        throw std::invalid_argument(
                "First payment must be lesser than property cost");
    }

    double monthly_percent =
            percent_ / static_cast<double>(MAX_PERCENT * MONTHS_IN_YEAR);
    double k = pow(1 + monthly_percent, term_);
    monthly_payment_ = hypothec_amount * ((monthly_percent * k) / (k - 1));
    overpayment_ = monthly_payment_ * term_ - hypothec_amount;
}

void HypothecCalculator::setPercent(int percent) {
    if (percent <= 0 || percent >= MAX_PERCENT) {
        throw std::invalid_argument(
                "Percent must be bigger than 0 and lesser than 100");
    }
    percent_ = percent;
}

void HypothecCalculator::setPropertyCost(int cost) {
    if (cost <= 0) {
        throw std::invalid_argument("Property cost must be bigger than 0");
    }
    property_cost_ = cost;
}

void HypothecCalculator::setFirstPayment(int payment) {
    if (payment <= 0) {
        throw std::invalid_argument("First payment must be bigger than 0");
    }
    first_payment_ = payment;
}

void HypothecCalculator::setTerm(int term) {
    if (term <= 0 || term > MAX_TERM) {
        throw std::invalid_argument(
                "Term must be bigger than 0 and lesser than 601");
    }
    term_ = term;
}

double HypothecCalculator::getPaymentsSum() const {
    return monthly_payment_ * term_;
}

int HypothecCalculator::getPercent() const {
    return percent_;
}

double HypothecCalculator::getMonthlyPayment() const {
    return monthly_payment_;
}

double HypothecCalculator::getOverpayment() const {
    return overpayment_;
}

int HypothecCalculator::getPropertyCost() const {
    return property_cost_;
}

int HypothecCalculator::getFirstPayment() const {
    return first_payment_;
}

int HypothecCalculator::getTerm() const {
    return term_;
}
