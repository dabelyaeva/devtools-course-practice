#ifndef MODULES_ZEMTSOV_ARTEM_CREDITCALC_INCLUDE_CREDITCALC_H_
#define MODULES_ZEMTSOV_ARTEM_CREDITCALC_INCLUDE_CREDITCALC_H_

//  creditCalc.h
//  firstAttempt
//
//  Created by артем on 22.04.16.
//  Copyright © 2016 артем. All rights reserved.
//
#include <include/moments.h>

class CreditPerson{
 public:
    // constructors
    CreditPerson();
    // set
    void setProcentByUser(const double procentImp);
    void setStartTimeByUser(const int dImp, const int mImp, const int yImp);
    void setFinishTimeByUser(const int creditTimeImp);
    // get
    double getBalanceOfTheDebt() {return needToPay;}
    // math methods
    double newInstallment(const double installmentImp);
    double performTheCalculation();  // calculating price with procent
    void discoverCost(const double costImp);  // setCost

 private:
    // variables
    Moment startDay , finishDay;
    int creditTime;
    double procent;
    double cost;
    double yourEnter;
    double needToPay;
    double middlePay;
    // methods
    // set
    void setStartTime(const int dayImp, const int monthImp, const int yearImp);
    void setCreditTime(const int timeImp);
    void setFinishDay(const int dayImp, const int monthImp, const int yearImp);
    void setEarlyFinish();
    void setCost(const double costImp) { cost = costImp; needToPay = costImp; }
    // get
    int getStartDay() {return startDay.getDay();}
    int getStartMonth() {return startDay.getMonth() ;}
    int getStartYear() {return startDay.getYear() ;}
    // math methods
    void paymentExecution(const double payImp);
    // check
    void checkDay(int dayImp);
    void checkMonth(int monthImp);
    void checkYear(int yearImp);
};

#endif  //  MODULES_ZEMTSOV_ARTEM_CREDITCALC_INCLUDE_CREDITCALC_H_

