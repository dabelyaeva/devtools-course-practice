// Copyright 2016 Zemtsov Artem

#ifndef MODULES_CREDITCALC_INCLUDE_CREDITCALC_H_
#define MODULES_CREDITCALC_INCLUDE_CREDITCALC_H_

#include <include/moments.h>

class CreditPerson {
 public:
    // constructors
    CreditPerson();
    // set
    void setProcentByUser(const double procentImp);
    void setStartTimeByUser(const int dImp, const int mImp, const int yImp);
    void setFinishTimeByUser(const int creditTimeImp);
    void setCreditTime(const int timeImp);
    // get
    double getBalanceOfTheDebt() { return needToPay; }
    double getBalanceOfMonth() { return middlePay; }
    int getFinishDay() { return finishDay.getDay(); }
    int getFinishMonth() { return finishDay.getMonth(); }
    int getFinishYear() { return finishDay.getYear(); }
    // math methods
    double newInstallment(const double installmentImp);
    double performTheCalculation();  // calculating price with procent
    void setCost(const double costImp);  // setCost

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
    void setEarlyFinish();
    // get
    int getStartDay() {  return startDay.getDay();   }
    int getStartMonth() {  return startDay.getMonth();  }
    int getStartYear() {  return startDay.getYear();  }
    // math methods
    void paymentExecution(const double payImp);
    // check
    void checkDay(int dayImp, int monthImp);
    void checkMonth(int monthImp);
    void checkYear(int yearImp);
};

#endif  //  MODULES_CREDITCALC_INCLUDE_CREDITCALC_H_
