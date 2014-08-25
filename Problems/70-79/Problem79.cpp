//
//  Problem79.cpp
//  ProjectEuler
//

#include "Problem79.h"
#include "TopologicalSort.h"
#include "WeightedDigraph.h"

std::set<int> Problem79::parseInput() const
{
    std::set<int> combinations;
    
    std::ifstream input("p079_keylog.txt");
    if(!input.is_open())
    {
        std::cout << "Error opening input file!\n";
        return combinations;
    }
    
    std::vector<int> rawInput;
    std::string line;
    while(std::getline(input, line))
        combinations.insert(std::stoi(line));
    
    input.close();
    
    return combinations;
}

int64_t Problem79::solve()
{
    std::set<int> combinations = parseInput();
    
    std::set<DirectedEdge> uniqueEdges;
    
    for(auto &i : combinations)
    {
        auto digits = getDigits(i);
        for(int j = 0; j < digits.size() - 1; ++j)
            uniqueEdges.insert(DirectedEdge(digits[j], digits[j + 1], 0));
    }
    
    WeightedDigraph digraph(10);
    for(auto &i : uniqueEdges)
        digraph.addEdge(i);
    
    TopologicalSort sort(digraph);
    auto result = sort.result();
    
    return digitsToNumber(result.begin(), result.end());
}