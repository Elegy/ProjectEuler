//
//  Problem42.cpp
//  ProjectEuler
//

#include "Problem42.h"

Problem42::Problem42()
: maxValue(0)
{
    processInput();
    generateTriangeNumbers();
}

void Problem42::processInput()
{
    char *buffer = new char[64];
    std::ifstream input("words.txt");
    if(!input.is_open())
    {
        std::cout << "Error opening input file!\n";
        return;
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
                int value = alphabeticalValue(buffer);
                maxValue = std::max(maxValue, value);
                values.push_back(value);
                cursor = 0;
            }
            continue;
        }
        
        buffer[cursor++] = c;
    }
    
    input.close();
    
    delete [] buffer;
}

void Problem42::generateTriangeNumbers()
{
    int curr = 0;
    int i = 1;
    while(curr < maxValue)
    {
        curr = (int)(0.5 * i * (i + 1));
        ++i;
        triangleNumbers.insert(curr);
    }
}

bool Problem42::isTriangleNumber(int num)
{
    return triangleNumbers.find(num) != triangleNumbers.end();
}

int64_t Problem42::solve()
{
    int count = 0;
    for(auto &i : values)
    {
        if(isTriangleNumber(i))
            ++count;
    }
    
    return count;
}