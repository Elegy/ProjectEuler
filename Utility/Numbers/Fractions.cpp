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

void Fraction::makeProperFraction(Primes &primes)
{
    auto denominatorFactors = primes.getPrimeFactors(denominator);
    auto numeratorFactors = primes.getPrimeFactors(numerator);
    for(auto i = numeratorFactors.begin(); i != numeratorFactors.end(); )
    {
        auto curr = i++;
        
        auto j = denominatorFactors.find(curr->first);
        if(j == denominatorFactors.end())
            continue;
        
        if(curr->second > j->second)
        {
            curr->second -= j->second;
            denominatorFactors.erase(j);
        }
        else if(curr->second < j->second)
        {
            j->second -= curr->second;
            numeratorFactors.erase(curr);
        }
        else
        {
            numeratorFactors.erase(curr);
            denominatorFactors.erase(j);
        }
    }
    
    numerator = 1;
    denominator = 1;
    
    for(auto &i : numeratorFactors)
    {
        for(int j = 0; j < i.second; ++j)
            numerator *= i.first;
    }
    
    for(auto &i : denominatorFactors)
    {
        for(int j = 0; j < i.second; ++j)
            denominator *= i.first;
    }
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

Fraction &Fraction::operator*=(const Fraction &rhs)
{
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    value = (float) numerator * (float) denominator;
    return *this;
}

int Fraction::operator*(int rhs) const
{
    return value * rhs;
}