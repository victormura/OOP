#include "BankAccount.h"
#include <utility>

BankAccount::BankAccount(std::string owner, std::string open_date, double sold)
        : owner(std::move(owner))
        , open_date(std::move(open_date))
        , sold(sold)
{}

BankAccount::BankAccount()
        : owner("")
        , open_date("")
        , sold(-1)
{}

std::ostream &operator<<(std::ostream &os, const BankAccount &bankAccount) {
    os << "owner: " << bankAccount.owner <<"\n"<< "open_date: " << bankAccount.open_date << "\n" << "sold: "
       << bankAccount.sold << '\n';
    return os;
}

std::istream & operator >> (std::istream &in, BankAccount &bankAccount){
    in >> bankAccount.owner;

    if(bankAccount.owner == "" || bankAccount.owner == " ")
        throw Exception("Invalid name");
    in >> bankAccount.open_date;

    in >> bankAccount.sold;
    return in;
}

int BankAccount::checkSold() {
    return sold;
}

