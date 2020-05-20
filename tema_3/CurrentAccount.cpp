#include "CurrentAccount.h"

double CurrentAccount:: transaction_price = 0.3;
int CurrentAccount :: number_of_free_trans_initial = 10;

void CurrentAccount::withdrawal(double sum) {
    if ( number_of_free_trans > 0){
        if ( sum > sold )
            throw Exception("Transaction failed! Insufficient resources :(");
        else
            sold -= sum;
        --number_of_free_trans;
    }
    else{
        sum = sum + sum * transaction_price;
        if( sum > sold )
            throw Exception("Transaction failed! Insufficient resources :(");
        else
            sold -= sum;
    }
}

void CurrentAccount::deposit(double sum) {
    sold += sum;
}

std::ostream &operator<<(std::ostream &os, const CurrentAccount &current) {
    os << static_cast<const BankAccount &>(current) << "\nThe number of free transactions remaining: " << current.number_of_free_trans;
    return os;
}

std::istream &operator>>(std::istream &in,CurrentAccount &current) {
    in >> static_cast<BankAccount &>(current);
    current.number_of_free_trans = CurrentAccount::number_of_free_trans_initial;
    return in;
}
