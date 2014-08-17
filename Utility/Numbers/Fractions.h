//
//  Fractions.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Fractions__
#define __ProjectEuler__Fractions__

#include <iostream>
#include "Primes.h"

class Fraction
{
    int numerator;
    int denominator;
    float value;
    
public:
    Fraction(int numerator, int denominator);
    
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    
    bool isProperFraction(Primes &primes) const;
    
    bool operator==(const Fraction &rhs) const;
    bool operator<=(const Fraction &rhs) const;
    bool operator<(const Fraction &rhs) const;
    
    int operator*(int rhs) const;
};

#endif /* defined(__ProjectEuler__Fractions__) */
