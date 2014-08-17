//
//  Fractions.cpp
//  ProjectEuler
//

#include "Fractions.h"

Fraction::Fraction(int numerator, int denominator)
: numerator(numerator)
, denominator(denominator)
, value((float)numerator / (float)denominator)
{
    
}

bool Fraction::isProperFraction(Primes &primes) const
{
    auto denominatorFactors = primes.getPrimeFactors(denominator);
    auto numeratorFactors = primes.getPrimeFactors(numerator);
    for(auto &i : numeratorFactors)
    {
        if(denominatorFactors.find(i.first) != denominatorFactors.end())
            return false;
    }
    return true;
}

bool Fraction::operator==(const Fraction &rhs) const
{
    return (numerator == rhs.numerator && denominator == rhs.denominator);
}

bool Fraction::operator<=(const Fraction &rhs) const
{
    if(*this == rhs)
        return true;
    
    return value < rhs.value;
}

bool Fraction::operator<(const Fraction &rhs) const
{
    if(*this == rhs)
        return false;
    
    return value < rhs.value;
}

int Fraction::operator*(int rhs) const
{
    return value * rhs;
}