//
//  BigNumber.h
//  ProjectEuler
//

#ifndef __ProjectEuler__BigNumber__
#define __ProjectEuler__BigNumber__

#include <iostream>
#include <list>
#include <vector>

class BigNumber
{
    std::list<char> digits;
    
public:
    // note, we're not currently handling negative big numbers
    
    BigNumber() { }
    BigNumber(int64_t num);
    BigNumber(const std::string &str);
    
    std::size_t size() const { return digits.size(); }
    
    std::list<char>::const_iterator begin() const { return digits.begin(); }
    std::list<char>::const_iterator end() const { return digits.end(); }
    
    void reverse() { digits.reverse(); }
    
    BigNumber operator+(const BigNumber &rhs) const;
    BigNumber operator+(const std::string &rhs) const;
    BigNumber operator+(const int64_t &rhs) const;
    BigNumber &operator+=(const BigNumber &rhs);
    BigNumber &operator+=(const std::string &rhs);
    
    BigNumber operator*(const BigNumber &rhs) const;
    BigNumber operator*(const std::string &rhs) const;
    BigNumber &operator*=(const BigNumber &rhs);
    BigNumber &operator*=(const std::string &rhs);
    
    static const BigNumber &pow(int64_t base, int64_t exponent);
    
    friend std::ostream &operator<<(std::ostream& os, const BigNumber &bigNumber);
};

#endif /* defined(__ProjectEuler__BigNumber__) */
