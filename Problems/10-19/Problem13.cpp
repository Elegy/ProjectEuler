//
//  Problem13.cpp
//  ProjectEuler
//

#include "Problem13.h"
#include "BigNumber.h"

#define PROBLEM_SIZE 10

int64_t Problem13::solve()
{
    std::ifstream input("problem13.txt");
    if(!input.is_open())
    {
        std::cout << "Error opening input file!\n";
        return -1;
    }
    
    std::string line;
    if(!std::getline(input, line))
        return -1;
    
    BigNumber sum(line);
    
    while(std::getline(input, line))
        sum += line;
    
    input.close();
    
    return digitsToNumber(sum.begin(), sum.end(), PROBLEM_SIZE);
}