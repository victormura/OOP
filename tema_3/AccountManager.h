//
// Created by Admin on 20/05/2020.
//

#ifndef TEMA_3_ACCOUNTMANAGER_H
#define TEMA_3_ACCOUNTMANAGER_H


#include <vector>
#include <iostream>
#include <unordered_map>
#include "SavingsAccount.h"

template <class T>
class AccountManager {
    static int account_index;
    std :: unordered_map<int,std :: pair <T, std :: vector <std :: pair <std :: string , int > > > > accounts;
public:
    AccountManager();
    ~AccountManager();

    void operator +=( const T & ob);
    void deposit( int account_index, int sum);
    double checkSold (int account_index);
};

template<>
class AccountManager <SavingsAccount>{
    static int account_index1;
    std :: unordered_map<int,std :: pair <SavingsAccount, std :: vector <std :: pair <std :: string , int > > > > accounts;
public:
    void print_accounts(){
        for(int i = 0; i < 10; ++i)
            if(accounts[i].first.getRateType() == 12)
                std :: cout << accounts[i].first << "\n";
    }
    double checkSold (int account_index){
        return accounts[account_index].first.checkSold();
    }
    void operator +=( const SavingsAccount & ob){
        accounts[account_index1].first = ob;
        accounts[account_index1].second.push_back({"Account initializing... ", 0});
        ++account_index1;
    };
};



template<class T>
AccountManager<T>::AccountManager() {
}

template<class T>
AccountManager<T>::~AccountManager() {
}

template<class T> int  AccountManager<T> ::account_index = 0;

template<class T>
void AccountManager<T>::operator+=(const T &ob) {
    accounts[account_index].first = ob;
    accounts[account_index].second.push_back({"Account initializing ", 0});
    ++account_index;
}

template<class T>
void AccountManager<T>::deposit(int account_index, int sum) {
    accounts[account_index].first.depunere(sum);
    accounts[account_index].second.push_back({"deposit", sum});
}

template<class T>
double AccountManager<T>::checkSold(int account_index) {
    return accounts[account_index].first.checkSold();
}



#endif //TEMA_3_ACCOUNTMANAGER_H
