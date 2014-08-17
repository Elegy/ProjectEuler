//
//  Problem15.cpp
//  ProjectEuler
//

#include "Problem15.h"

#define PROBLEM_SIZE 20

Problem15::Problem15()
{
    array = new uint64_t*[PROBLEM_SIZE];
    for(int i = 0; i < PROBLEM_SIZE; ++i)
    {
        array[i] = new uint64_t[PROBLEM_SIZE];
        memset(array[i], 0, sizeof(uint64_t) * PROBLEM_SIZE);
    }
    
    for(int i = 0; i < PROBLEM_SIZE; ++i)
        put(i, 0, 2 + i);
}

Problem15::~Problem15()
{
    for(int i = 0; i < PROBLEM_SIZE; ++i)
        delete [] array[i];
    delete [] array;
}

uint64_t Problem15::get(int x, int y)
{
    if(array[x][y])
        return array[x][y];
    
    uint64_t value = get(x - 1, y) + get(x, y - 1);
    put(x, y, value);
    return value;
}

void Problem15::put(int x, int y, uint64_t value)
{
    array[x][y] = value;
    array[y][x] = value;
}

int64_t Problem15::solve()
{
    return get(PROBLEM_SIZE - 1, PROBLEM_SIZE - 1);
}