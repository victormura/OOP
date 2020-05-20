#ifndef TEMA_3_BANKACCOUNT_H
#define TEMA_3_BANKACCOUNT_H

#include <string>
#include <ostream>
#include <istream>
#include <exception>
#include <vector>
#include "Exception.h"
#include "Date.h"

class BankAccount {
protected:
    std::string owner;
    Date open_date;
    double sold;
public:
    BankAccount();
    BankAccount(std::string owner, std::string open_date, double sold);

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &bankAccount);
    friend std::istream &operator>> (std::istream &in, BankAccount &bankAccount);

    virtual int checkSold();

};

#endif //TEMA_3_BANKACCOUNT_H
