// Copyright 2016 Zemtsov Artem

#include <stdio.h>
#include <stdexcept>
#include "../include/creditCalc.h"

CreditPerson::CreditPerson() {
    creditTime =  0;
    procent = 0;
    cost = 0;
    yourEnter = 0;
    needToPay = 0;
}

void CreditPerson::setProcentByUser(const double procentImp) {
    if ( (procentImp >= 0) && (procentImp <= 100) ) {
             procent = procentImp / 100;
    } else {
             throw std::invalid_argument("Invalide procent(0<=procent<=100)");
    }
}

double CreditPerson::newInstallment(const double installmentImp) {
    if (installmentImp >= 0) {
            paymentExecution(installmentImp);
            return needToPay;
        } else {
            throw std::invalid_argument
                ("Invalide installment(must be more than 0)");
        }
}

double CreditPerson::performTheCalculation() {
    if (creditTime >= 12) {
        needToPay = cost+cost*procent*
            (static_cast<double>(creditTime / 12));  // calc cost with
    } else {
        if ( creditTime ) {
            needToPay = cost+cost*procent*
                (static_cast<double>(creditTime / 12));
        }
    }
    middlePay = needToPay / creditTime;  // calc everemonth pay
    setFinishTimeByUser(creditTime);
    return needToPay;
}

void CreditPerson::setCreditTime(const int timeImp) {
    creditTime = timeImp;
}

void CreditPerson::setCost(const double costImp) {
    if (costImp <= 0) {
        throw std::invalid_argument("Invalide cost(cost must be more than 0)");
    } else {
        cost = costImp;
        needToPay = costImp;
    }
}

void CreditPerson::paymentExecution(const double payImp) {
        if ( (payImp < 0) || (payImp > needToPay) ) {
            throw std::invalid_argument("Invalide payment");
        } else {
           if (payImp != needToPay) {
               needToPay -= payImp;
               yourEnter += payImp;
           } else {
                needToPay -= payImp;
                yourEnter += payImp;
                creditTime = 0;
                setEarlyFinish();
             }
        }
}

void CreditPerson::setStartTimeByUser
    (const int dImp, const int mImp, const int yImp) {
    // Check
    checkDay(dImp, mImp);
    checkMonth(mImp);
    checkYear(yImp);
    // Set
    startDay.setTime(dImp, mImp, yImp);
}

void CreditPerson::setFinishTimeByUser(const int creditTimeImp) {
    setCreditTime(creditTimeImp);
    if (creditTime < 1) {
        throw std::invalid_argument
            ("Invalide credit time (must be more than 0)");
    } else {
        int day = getStartDay();
        int month = (startDay.getMonth() + creditTime) % 12;
        int year = getStartYear() + ((startDay.getMonth() + creditTime) / 12);
        finishDay.setTime(day, month, year);
    }
}

void CreditPerson::checkDay(int dayImp, int monthImp) {
    if (monthImp % 2 == 1) {
        if ((dayImp < 1) || (dayImp > 31)) {
            throw std::invalid_argument("Invalid day");
        } } else if (monthImp == 2) {
            if ((dayImp < 1) || (dayImp > 28))
                throw std::invalid_argument("Invalid day");
        } else if (monthImp % 2 == 0) {
            if ((dayImp < 1) || (dayImp > 30))
                throw std::invalid_argument("Invalid day");
        }
}

void CreditPerson::checkMonth(int monthImp) {
    if ( (monthImp < 1) || (monthImp > 12) )
            throw std::invalid_argument("Invalid month");
    }

void CreditPerson::checkYear(int yearImp) {
    if ( (yearImp < 1900) || (yearImp > 9999) )
        throw std::invalid_argument("Invalid year");
}

void CreditPerson::setEarlyFinish() {
    std::cout<< "You successfuly closed your credit"<< std::endl;
}
