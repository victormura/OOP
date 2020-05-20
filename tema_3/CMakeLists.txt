cmake_minimum_required(VERSION 3.15)
project(tema_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(tema_3 main.cpp BankAccount.h BankAccount.cpp Date.h Date.cpp Exception.h Exception.cpp CurrentAccount.h CurrentAccount.cpp SavingsAccount.h SavingsAccount.cpp AccountManager.h AccountManager.cpp)