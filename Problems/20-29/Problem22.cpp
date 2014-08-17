//
//  Problem22.cpp
//  ProjectEuler
//

#include "Problem22.h"
#include "StringQuicksort.h"

std::vector<std::string> Problem22::processInput()
{
    std::vector<std::string> output;
    
    char *buffer = new char[64];
    std::ifstream input("names.txt");
    if(!input.is_open())
    {
        std::cout << "Error opening input file!\n";
        return output;
    }
    
    int cursor = 0;
    while(input.good())
    {
        char c = input.get();
        if(c == ',')
            continue;
        
        if(c == '"')
        {
            if(cursor != 0)
            {
                buffer[cursor] = 0;
                output.push_back(buffer);
                cursor = 0;
            }
            continue;
        }
        
        buffer[cursor++] = c;
    }
    
    input.close();
    
    delete [] buffer;
    return output;
}

int64_t Problem22::solve()
{
    std::vector<std::string> input = processInput();
    quicksort(input);
    
    int sum = 0;
    for(int i = 0; i < input.size(); ++i)
        sum += alphabeticalValue(input[i]) * (i + 1);
    
    return sum;
}