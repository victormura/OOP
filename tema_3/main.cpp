#include <iostream>
#include <string>
#include <fstream>
#include "BankAccount.h"
#include "AccountManager.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "Date.h"

int main() {
    try{
        std :: cout << "Introduce-ti datele despre contul de economii " <<
                       "(nume, data, sold, dobanda%, tipul dobanzii(3/6/12),\n" <<
                       "numarul de tranzactii, sumele tranzactiilor prin spatiu: \n";

        SavingsAccount ob1;
        std :: cin >> ob1;

        std :: cout << "Introduce-ti datele despre cont curent (nume, data, sold)\n";
        CurrentAccount ob2;
        std :: cin >> ob2;

        AccountManager<CurrentAccount> currentAccountManager;
        currentAccountManager += ob2;
        std :: cout << currentAccountManager.checkSold(0) << "\n";
        currentAccountManager += ob2;
        std :: cout << currentAccountManager.checkSold(1) << "\n";

        AccountManager<SavingsAccount> savingsAccountManager;
        savingsAccountManager += ob1;

        std :: cout << savingsAccountManager.checkSold(0) << "\n";
        savingsAccountManager.print_accounts();
    }
    catch (Exception &e) {
        std::cout << e.getMessage();
    }

    return 0;
}
