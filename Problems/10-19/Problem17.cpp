//
//  Problem17.cpp
//  ProjectEuler
//

#include "Problem17.h"

#define PROBLEM_SIZE 1000
#define AND 3

Problem17::Problem17()
{
    numberToLetterCount.insert(std::make_pair(1, 3));       // one
    numberToLetterCount.insert(std::make_pair(2, 3));       // two
    numberToLetterCount.insert(std::make_pair(3, 5));       // three
    numberToLetterCount.insert(std::make_pair(4, 4));       // four
    numberToLetterCount.insert(std::make_pair(5, 4));       // five
    numberToLetterCount.insert(std::make_pair(6, 3));       // six
    numberToLetterCount.insert(std::make_pair(7, 5));       // seven
    numberToLetterCount.insert(std::make_pair(8, 5));       // eight
    numberToLetterCount.insert(std::make_pair(9, 4));       // nine
    numberToLetterCount.insert(std::make_pair(10, 3));      // ten
    numberToLetterCount.insert(std::make_pair(11, 6));      // eleven
    numberToLetterCount.insert(std::make_pair(12, 6));      // twelve
    numberToLetterCount.insert(std::make_pair(13, 8));      // thirteen
    numberToLetterCount.insert(std::make_pair(14, 8));      // fourteen
    numberToLetterCount.insert(std::make_pair(15, 7));      // fifteen
    numberToLetterCount.insert(std::make_pair(16, 7));      // sixteen
    numberToLetterCount.insert(std::make_pair(17, 9));      // seventeen
    numberToLetterCount.insert(std::make_pair(18, 8));      // eighteen
    numberToLetterCount.insert(std::make_pair(19, 8));      // nineteen
    numberToLetterCount.insert(std::make_pair(20, 6));      // twenty
    numberToLetterCount.insert(std::make_pair(30, 6));      // thirty
    numberToLetterCount.insert(std::make_pair(40, 5));      // forty
    numberToLetterCount.insert(std::make_pair(50, 5));      // fifty
    numberToLetterCount.insert(std::make_pair(60, 5));      // sixty
    numberToLetterCount.insert(std::make_pair(70, 7));      // seventy
    numberToLetterCount.insert(std::make_pair(80, 6));      // eighty
    numberToLetterCount.insert(std::make_pair(90, 6));      // ninety
    numberToLetterCount.insert(std::make_pair(100, 7));     // hundred
    numberToLetterCount.insert(std::make_pair(1000, 11));   // one thousand
}

uint8_t Problem17::getLetterCount(uint16_t number) const
{
    if(number == 1000)
    {
        auto i = numberToLetterCount.find(1000);
        return i->second;
    }
    
    uint8_t letterCount = 0;
    if(number >= 100)
    {
        auto i = numberToLetterCount.find(100);
        letterCount += i->second;
        
        i = numberToLetterCount.find(number / 100);
        letterCount += i->second;
        
        number %= 100;
        if(!number)
            return letterCount;
        
        letterCount += AND;
    }
    
    if(number <= 20 || number % 10 == 0)
    {
        auto i = numberToLetterCount.find(number);
        letterCount += i->second;
    }
    else
    {
        uint8_t onesPlace = number % 10;
        
        auto i = numberToLetterCount.find(onesPlace);
        letterCount += i->second;
        
        i = numberToLetterCount.find(number - onesPlace);
        letterCount += i->second;
    }
    
    return letterCount;
}

int64_t Problem17::solve()
{
    int letterCount = 0;
    for(int i = 1; i <= PROBLEM_SIZE; ++i)
        letterCount += getLetterCount(i);
    
    return letterCount;
}