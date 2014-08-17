//
//  Problem8.cpp
//  ProjectEuler
//

#include "Problem8.h"

std::vector<short> Problem8::processInput()
{
    std::vector<short> output;
    
    std::ifstream input("problem8.txt");
    if(!input.is_open())
    {
        std::cout << "Error opening input file!\n";
        return output;
    }
    
    std::string str;
    std::getline(input, str);
    input.close();
    
    for(auto &iter : str)
        output.push_back(iter - '0');
    return output;
}

int64_t Problem8::solve()
{
    std::vector<short> digits = processInput();
    
    int max = 0;
    for(int i = 0; i < digits.size() - 4; ++i)
    {
        int current = digits[i];
        
        for(int j = 1; j < 5; ++j)
        {
            current *= digits[i + j];
            if(!current)
                break;
        }
        
        max = std::max(max, current);
    }
    
    return max;
}