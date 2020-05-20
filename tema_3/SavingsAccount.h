#ifndef TEMA_3_SAVINGSACCOUNT_H
#define TEMA_3_SAVINGSACCOUNT_H

#include "BankAccount.h"
#include <iostream>

class SavingsAccount: public BankAccount{
    double interest_rate;
    int rate_type;
    std::vector<int> sold_history;
public:
    SavingsAccount();

    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &savings);
    friend std::istream &operator>>(std::istream &in, SavingsAccount &savings);

    void setSoldHistory(const std::vector<int> &soldHistory);
    void deposit( int sum);
    int getRateType();
};


#endif //TEMA_3_SAVINGSACCOUNT_H
