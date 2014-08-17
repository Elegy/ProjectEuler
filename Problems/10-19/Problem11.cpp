//
//  Problem11.cpp
//  ProjectEuler
//

#include "Problem11.h"

std::vector<std::vector<int>> Problem11::parseInput()
{
    std::vector<std::vector<int>> output;
    
    std::ifstream input("problem11.txt");
    if(!input.is_open())
    {
        std::cout << "Error opening input file!\n";
        return output;
    }
    
    std::string line;
    while(std::getline(input, line))
    {
        output.push_back(std::vector<int>());
        std::vector<int> &current = output.back();
        
        std::size_t pos = 0;
        while(pos != line.size())
        {
            line = line.substr(pos);
            current.push_back(std::stoi(line, &pos));
        }
    }
    
    input.close();
    
    return output;
}

int64_t Problem11::solve()
{
    std::vector<std::vector<int>> input = parseInput();
    if(input.empty())
        return 0;
    
    int max = 0;
    
    std::size_t m = input[0].size();
    std::size_t n = input.size();
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(i < n - 3)
            {
                int vert = input[i][j] * input[i + 1][j] * input[i + 2][j] * input[i + 3][j];
                max = std::max(vert, max);
            }
            
            if(j < m - 3)
            {
                int horz = input[i][j] * input[i][j + 1] * input[i][j + 2] * input[i][j + 3];
                max = std::max(horz, max);
            }
            
            if(i < n - 3 && j < m - 3)
            {
                int diag = input[i][j] * input[i + 1][j + 1] * input[i + 2][j + 2] * input[i + 3][j + 3];
                max = std::max(diag, max);
            }
            
            if(i < n - 3 && j >= 3)
            {
                int diag = input[i + 3][j - 3] * input[i + 2][j - 2] * input[i + 1][j - 1] * input[i][j];
                max = std::max(diag, max);
            }
        }
    }
    
    return max;
}