//
//  BigNumber.cpp
//  ProjectEuler
//

#include <unordered_map>
#include "BigNumber.h"
#include "Common.h"

BigNumber::BigNumber(int64_t num)
{
    while(num)
    {
        digits.push_front(num % 10);
        num /= 10;
    }
}

BigNumber::BigNumber(const std::string &str)
{
    for(const char &c : str)
        digits.push_back((c - '0') % 10);
}

BigNumber BigNumber::operator+(const BigNumber &rhs) const
{
    BigNumber result;
    
    auto i = digits.end();
    auto j = rhs.digits.end();
    
    bool carry = false;
    while(i != digits.begin() && j != rhs.digits.begin())
    {
        result.digits.push_front(*--i + *--j + carry);
        if(result.digits.front() >= 10)
        {
            carry = true;
            result.digits.front() -= 10;
            continue;
        }
        carry = false;
    }
    
    if(j != rhs.digits.begin())
    {
        do
        {
            result.digits.push_front(*--j + carry);
            if(result.digits.front() >= 10)
            {
                carry = true;
                result.digits.front() -= 10;
                continue;
            }
            carry = false;
        } while(j != rhs.digits.begin());
    }
    else
    {
        while(i != digits.begin())
        {
            result.digits.push_front(*--i + carry);
            if(result.digits.front() >= 10)
            {
                carry = true;
                result.digits.front() -= 10;
                continue;
            }
            carry = false;
        }
    }
    
    if(carry)
        result.digits.push_front(1);
    
    return result;
}

BigNumber BigNumber::operator+(const std::string &rhs) const
{
    BigNumber result;
    
    auto i = digits.end();
    auto j = rhs.end();
    
    bool carry = false;
    while(i != digits.begin() && j != rhs.begin())
    {
        result.digits.push_front(*--i + (*--j - '0') + carry);
        if(result.digits.front() >= 10)
        {
            carry = true;
            result.digits.front() -= 10;
            continue;
        }
        carry = false;
    }
    
    if(j != rhs.begin())
    {
        do
        {
            result.digits.push_front((*--j - '0') + carry);
            if(result.digits.front() >= 10)
            {
                carry = true;
                result.digits.front() -= 10;
                continue;
            }
            carry = false;
        } while(j != rhs.begin());
    }
    else
    {
        while(i != digits.begin())
        {
            result.digits.push_front(*--i + carry);
            if(result.digits.front() >= 10)
            {
                carry = true;
                result.digits.front() -= 10;
                continue;
            }
            carry = false;
        }
    }
    
    if(carry)
        result.digits.push_front(1);
    
    return result;
}

BigNumber &BigNumber::operator+=(const BigNumber &rhs)
{
    auto i = digits.end();
    auto j = rhs.digits.end();
    
    bool carry = false;
    while(i != digits.begin() && j != rhs.digits.begin())
    {
        *i = *--i + *--j + carry;
        if(*i >= 10)
        {
            carry = true;
            *i -= 10;
            continue;
        }
        carry = false;
    }
    
    if(j != rhs.digits.begin())
    {
        do
        {
            digits.push_front(*--j + carry);
            if(digits.front() >= 10)
            {
                carry = true;
                digits.front() -= 10;
                continue;
            }
            carry = false;
        } while(j != rhs.digits.begin());
    }
    else
    {
        while(carry && i != digits.begin())
        {
            *i = *--i + carry;
            if(*i >= 10)
            {
                carry = true;
                *i -= 10;
                continue;
            }
            carry = false;
        }
    }
    
    if(carry)
        digits.push_front(1);
    
    return *this;
}

BigNumber &BigNumber::operator+=(const std::string &rhs)
{
    auto i = digits.end();
    auto j = rhs.end();
    
    bool carry = false;
    while(i != digits.begin() && j != rhs.begin())
    {
        *i = *--i + (*--j - '0') + carry;
        if(*i >= 10)
        {
            carry = true;
            *i -= 10;
            continue;
        }
        carry = false;
    }
    
    if(j != rhs.begin())
    {
        do
        {
            digits.push_front((*--j - '0') + carry);
            if(digits.front() >= 10)
            {
                carry = true;
                digits.front() -= 10;
                continue;
            }
            carry = false;
        } while(j != rhs.begin());
    }
    else
    {
        while(carry && i != digits.begin())
        {
            *i = *--i + carry;
            if(*i >= 10)
            {
                carry = true;
                *i -= 10;
                continue;
            }
            carry = false;
        }
    }
    
    if(carry)
        digits.push_front(1);
    
    return *this;
}

BigNumber BigNumber::operator*(const BigNumber &rhs) const
{
    BigNumber result;
    
    auto i = digits.end();
    int place = 0;
    while(i != digits.begin())
    {
        if(*--i == 0)
        {
            ++place;
            continue;
        }
        
        BigNumber temp;
        for(int i = 0; i < place; ++i)
            temp.digits.push_front(0);
        
        auto j = rhs.digits.end();
        char next = 0;
        while(j != rhs.digits.begin())
        {
            next += (*i)*(*--j);
            temp.digits.push_front(next % 10);
            next /= 10;
        }
        
        if(next)
            temp.digits.push_front(next);
        
        ++place;
        result += temp;
    }
    
    return result;
}

BigNumber BigNumber::operator*(const std::string &rhs) const
{
    BigNumber result;
    
    auto i = digits.end();
    int place = 0;
    while(i != digits.begin())
    {
        if(*--i == 0)
        {
            ++place;
            continue;
        }
        
        BigNumber temp;
        for(int i = 0; i < place; ++i)
            temp.digits.push_front(0);
        
        auto j = rhs.end();
        char next = 0;
        while(j != rhs.begin())
        {
            next += (*i)*(*--j - '0');
            temp.digits.push_front(next % 10);
            next /= 10;
        }
        
        if(next)
            temp.digits.push_front(next);
        
        ++place;
        result += temp;
    }
    
    return result;
}

BigNumber &BigNumber::operator*=(const BigNumber &rhs)
{
    BigNumber result;
    
    auto i = digits.end();
    int place = 0;
    while(i != digits.begin())
    {
        if(*--i == 0)
        {
            ++place;
            continue;
        }
        
        BigNumber temp;
        for(int i = 0; i < place; ++i)
            temp.digits.push_front(0);
        
        auto j = rhs.digits.end();
        char next = 0;
        while(j != rhs.digits.begin())
        {
            next += (*i)*(*--j);
            temp.digits.push_front(next % 10);
            next /= 10;
        }
        
        if(next)
            temp.digits.push_front(next);
        
        ++place;
        result += temp;
    }
    
    digits.swap(result.digits);
    return *this;
}

BigNumber &BigNumber::operator*=(const std::string &rhs)
{
    BigNumber result;
    
    auto i = digits.end();
    int place = 0;
    while(i != digits.begin())
    {
        if(*--i == 0)
        {
            ++place;
            continue;
        }
        
        BigNumber temp;
        for(int i = 0; i < place; ++i)
            temp.digits.push_front(0);
        
        auto j = rhs.end();
        char next = 0;
        while(j != rhs.begin())
        {
            next += (*i)*(*--j - '0');
            temp.digits.push_front(next % 10);
            next /= 10;
        }
        
        if(next)
            temp.digits.push_front(next);
        
        ++place;
        result += temp;
    }
    
    digits.swap(result.digits);
    return *this;
}

std::unordered_map<int64_t, BigNumber> powers;
const BigNumber &BigNumber::pow(int64_t base, int64_t exponent)
{
    int64_t key = (base << 32) | exponent;
    auto existing = powers.find(key);
    if(existing != powers.end())
        return existing->second;
    
    std::pair<std::unordered_map<int64_t, BigNumber>::iterator, bool> result;
    if(exponent == 0)
        result = powers.insert(std::make_pair(key, BigNumber(1)));
    else if(exponent == 1)
        result = powers.insert(std::make_pair(key, BigNumber(base)));
    else if(isOdd(exponent))
        result = powers.insert(std::make_pair(key, pow(base, exponent / 2) * pow(base, exponent / 2 + 1)));
    else
        result = powers.insert(std::make_pair(key, pow(base, exponent / 2) * pow(base, exponent / 2)));
    
    return result.first->second;
}

std::ostream &operator<<(std::ostream& os, const BigNumber &bigNumber)
{
    for(auto &i : bigNumber.digits)
        os << char(i + '0');
    return os;
}