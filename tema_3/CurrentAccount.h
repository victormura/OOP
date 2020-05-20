#ifndef TEMA_3_CURRENTACCOUNT_H
#define TEMA_3_CURRENTACCOUNT_H

#include <iostream>
#include "BankAccount.h"

class CurrentAccount: public BankAccount{
    static double transaction_price; // percents of transfer sum
    static int number_of_free_trans_initial;
    int number_of_free_trans = number_of_free_trans_initial;

public:
    CurrentAccount() = default;
    void withdrawal(double sum);
    void deposit( double  sum);

    friend std::ostream &operator<<(std::ostream &os, const CurrentAccount &current);
    friend std::istream &operator>>(std::istream &in, CurrentAccount &current);
};

#endif //TEMA_3_CURRENTACCOUNT_H
