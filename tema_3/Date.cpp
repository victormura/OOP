#include "Date.h"


void Date::date_validation() {
    std::vector<char> separator = {'/', '.', '-'};
    int ok = 0;
    for (auto it : separator )
    {
        if(date[2] == it && date[5] == it)
        {
            ok = 1;
            break;
        }
    }
    if (date.size() != 10)
        ok = 0;
    for(int i = 0; i < date.size(); ++i)
        if( i != 2 || i != 5){
            if (!( (int)date[i] >= 0 || (int)date[i] <= 9))
                ok = 0;
        }
    if( ((int)date[0] == '0' && (int)date[1]  == '0' )
        ||   ((int)date[3] == '0' && (int)date[4]  == '0' )
        || ((int)date[6] == '0' ) )
        ok = 0;

    if ( ok == 0)
        throw Exception("Input date are incorrect");
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << "date: " << date.date;
    return os;
}

std::istream &operator>>(std::istream &in, Date &date) {
    in >> date.date;
    date.date_validation();
    return in;
}

Date Date::operator=(const char *a) {
    return basic_string::operator=(a);
}

