//
//  Common.cpp
//  ProjectEuler
//

#include "Common.h"


bool closeEnough(float a, float b)
{
    return (fabs(a - b) < std::numeric_limits<float>::epsilon());
}

std::unordered_map<int, int64_t> factorials;
int64_t getFactorial(int num)
{
    if(num == 1 || num == 0)
        return 1;
    
    auto existing = factorials.find(num);
    if(existing != factorials.end())
        return existing->second;
    
    int64_t result = num * getFactorial(num - 1);
    factorials.insert(std::make_pair(num, result));
    return result;
}

bool isOdd(int64_t num)
{
    return num & 1;
}

bool isPerfectSquare(uint64_t num)
{
    uint64_t root = (uint64_t)sqrt(num);
    return num == root * root;
}

int countDigits(int64_t num, int base)
{
    if(!num)
        return 1;
    
    int count = 0;
    while(num)
    {
        ++count;
        num /= base;
    }
    return count;
}

bool isPalindrome(std::vector<char> &array)
{
    int size = (int)array.size();
    int mid = size / 2;
    for(int i = 0; i <= mid; ++i)
    {
        if(array[i] != array[size - 1 - i])
            return false;
    }
    
    return true;
}

bool isPalindrome(std::list<char>::const_iterator begin, std::list<char>::const_iterator end)
{
    if(begin == end)
        return true;
    else if(begin == --end)
        return true;
    
    while(*begin == *end)
    {
        if(begin == --end)
            return true;
        else if(++begin == end)
            return true;
        
    }
    return false;
}

int alphabeticalValueForCharacter(char c)
{
    if((c < 'A' && c > 'z') || (c > 'Z' && c < 'a'))
        return 0;
    
    if(c > 'a')
        return c - 'a' + 1;
    
    return c - 'A' + 1;
}

int alphabeticalValue(const std::string &str)
{
    int value = 0;
    
    for(int i = 0; i < str.size(); ++i)
        value += alphabeticalValueForCharacter(str[i]);
    
    return value;
}

std::vector<char> getDigits(int64_t num, int base)
{
    int size = countDigits(num, base);
    std::vector<char> output;
    output.resize(size);
    int i = size - 1;
    while(num)
    {
        output[i--] = num % base;
        num /= base;
    }
    return output;
}

int64_t digitsToNumber(std::vector<char>::const_iterator begin, std::vector<char>::const_iterator end)
{
    int64_t number = *begin++;
    while(begin != end)
    {
        number *= 10;
        number += *begin++;
    }
    return number;
}

int64_t digitsToNumber(std::list<char>::const_iterator begin, std::list<char>::const_iterator end, int count)
{
    int64_t number = *begin++;
    int i = 1;
    while(begin != end && i++ < count)
    {
        number *= 10;
        number += *begin++;
    }
    return number;
}

bool isPandigital(const std::vector<char> &digits, int lower, int upper)
{
    int size = upper - lower + 1;
    bool seen[size];
    memset(seen, 0, sizeof(seen));
    
    if(digits.size() != size)
        return false;
    
    for(const auto &i : digits)
    {
        if(i < lower || i > upper)
            return false;
        
        if(seen[i - lower])
            return false;
        
        seen[i - lower] = true;
    }
    
    for(int i = 0; i < size; ++i)
    {
        if(!seen[i])
            return false;
    }
    
    return true;
}

bool isPandigital(int64_t num, int lower, int upper)
{
    return isPandigital(getDigits(num), lower, upper);
}

std::vector<std::vector<char>> getPermutations(std::vector<char> &input)
{
    std::vector<std::vector<char>> output;
    output.push_back(input);
    
    int64_t limit = getFactorial((int)input.size());
    for(int i = 1; i < limit; ++i)
    {
        std::next_permutation(input.begin(), input.end());
        output.push_back(input);
    }
    return output;
}