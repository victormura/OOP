
#include <iostream>
using std::istream;
using std::ostream;

using std::cerr;
using std::endl;

#include <cstdlib>
using std::exit;

#include "Polinom.h"


Polynomial::Polynomial()
{
    degree        = 0;
    coefficients = 0;

}


Polynomial::Polynomial(int dgr, const double* clist)
{
    getDegree();

}

int Polynomial::getDegree() const
{
    return degree;
}

Polynomial:: ~Polynomial()
{
    setDegree(0);
}

int Polynomial::setDegree(int dgr)
{

    if( dgr <0 ) {
        cerr << "Error:  attempted to set a negative degree" << endl;
        exit(1);
    } else {
        if( coefficients!=0 ) {
            delete [] coefficients;
            coefficients = 0;
            degree       = 0;
        }
        if( dgr !=0 ) {
            coefficients = new double [dgr];
            if( coefficients==0 ) {
                degree =0;
                cerr << "Warning:  unable to allocate enough space for list" << endl;
                exit(2); // this surely is reasonable.
            } else {
                degree=dgr;
            }
        }
    }
    return dgr;


}

//copy constructor
Polynomial::Polynomial(const Polynomial& clist) : degree(0), coefficients(0)
{
    if( clist.getDegree()<=0 ) {
        setDegree(0);
    } else {
        setDegree(clist.getDegree());
        for (int i=0; i< degree ; i++) {
            coefficients[i]=clist.coefficients[i];
        }
    }
}


const Polynomial& Polynomial :: operator=(const Polynomial& clist)
{
    if ( &clist==this )
    {
        cerr << "Warning:  attempt to copy Polynomial onto self" << endl;
    }
    else {
        if( clist.getDegree()<=0 ) {
            setDegree(0);
        } else {
            setDegree(clist.getDegree());
            for (int i=0; i< degree ; i++) {
                coefficients[i] = clist.coefficients[i];
            }
        }
    }
    return *this;
}

bool  Polynomial::operator==(const Polynomial& clist) const
{
    bool result=true;
    if( degree!=clist.getDegree() ) {
        result=false;
    } else {
        for(int i=0; i< degree && result == true; i++) {
            result = coefficients[i]==clist.coefficients[i];
        }
    }
    return result;
}


double Polynomial::operator[]( int index ) const
{
    if( index<0 || index>= degree ) {
        cerr << "Attempt to access element outside index bounds"
             << endl;
        exit(3); // Maybe not reasonable.
    } else {
        return coefficients[index];
    }
}


double& Polynomial::operator[]( int index )
{
    if( index < 0 || index>= degree  ) {
        cerr << "Attempt to access element outside index bounds"
             << endl;
        exit(4);
    } else {
        return coefficients[index];
    }
}



ostream& operator<<( ostream& left, const Polynomial& right)
{
    if( right.getDegree() > 0 ) {
        left << endl;
        for (int i=0; i< right.getDegree(); i++ ) {
            for (int j = 0; j >= 0 ; j -- ){


                left << right[i] << "X^(" << j << ") " ;
                if (j > 0)
                {
                    left << " + ";
                }

            }
        }
    }
    else {
        cerr << "Warning:  Attempt to display empty List" << endl;
    }


    return left;
}


istream& operator>>( istream& left, Polynomial& right)
{
    int tmp;
    left >> tmp;
    if( tmp<=0 ) {
        cerr << "First value expected to be list size, > 0." << endl;
    } else {
        if( tmp!=right.getDegree() ) {
            right.setDegree(tmp);
        }
        for (int i=0; i<right.getDegree(); i++) {
            left >> right[i];
        }
    }
    return left;
}