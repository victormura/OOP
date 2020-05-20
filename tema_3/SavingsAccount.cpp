#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(): interest_rate{-1}, rate_type{-1}{}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &savings) {
    os << static_cast<const BankAccount &>(savings) << "\n" <<  "rate: " << savings.interest_rate <<"\n"<<"rate_type: "<<savings.rate_type<< "\n"<< "sold_history: ";
    for(int i = 0; i < savings.sold_history.size(); ++i ){
        os << savings.sold_history[i] << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &in, SavingsAccount &savings) {
    in >> (BankAccount&)savings;
    in >> savings.interest_rate;
    in >> savings.rate_type;
    int ok = 0;
    if (savings.rate_type == 3 || savings.rate_type == 6 || savings.rate_type == 9 || savings.rate_type == 12 )
        ok = 1;
    if( ok == 0)
        throw Exception("Invalid rate type");
    int history_length;
    in >> history_length;
    int elem = 0;
    for( int i = 0; i < history_length; ++i){
        in >> elem;
        savings.sold_history.push_back(elem);
    }
    return in;
}

void SavingsAccount::setSoldHistory(const std::vector<int> &soldHistory)  {
    sold_history = soldHistory;
}

void SavingsAccount::deposit(int sum) {
    sold += sum;
}

int SavingsAccount::getRateType() {
    return rate_type;
}
