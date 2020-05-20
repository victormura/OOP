#ifndef TEMA_3_DATE_H
#define TEMA_3_DATE_H

#include <string>
#include "Exception.h"
#include <vector>
#include <ostream>
#include <iostream>

class Date : public std :: string{
    std :: string date;
public:
    Date(): date("")
    {};

    Date(const std::string &date) : date(date)
    {
        if( date != "")
            this->date_validation();
    }
    friend std::istream &operator >> (std :: istream & in, Date & date);
    friend std::ostream &operator<<(std::ostream &os, const Date & date);
    Date operator = ( const char *a);
    void date_validation();
};


#endif //TEMA_3_DATE_H
