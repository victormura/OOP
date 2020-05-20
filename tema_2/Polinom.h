
#ifndef TEMA_2_POLINOM_H
#define TEMA_2_POLINOM_H

#include "Monom.h"
#include <iostream>
using std::ostream;
using std::istream;

class Polinom
{

public:
    Polinom();
    Polinom( int dgr, const double* clist );
    Polinom( const Polinom& );
    ~Polinom();

    int setDegree(int dgr);
    int getDegree() const;

    const Polinom& operator=( const Polinom& clist);
    bool operator==( const Polinom& clist) const;

    void printPolinom( int dgr, const double* clist );

    double operator[]( int index ) const;
    double& operator[]( int index );

private:
    int    degree;
    double *coefficients; // list of coefficients
};

ostream& operator<<( ostream& , const Polinom& );
istream& operator>>( istream& , Polinom& );


#endif //TEMA_2_POLINOM_H
