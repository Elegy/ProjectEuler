//
//  StringQuicksort.cpp
//  ProjectEuler
//

#include <algorithm>
#include "StringQuicksort.h"

int charAt(const std::string &string, int index)
{
    if(index < string.size())
        return string[index];
    
    return -1;
}

void insertionSortPartition(std::vector<std::string> &array, int begin, int end, int index)
{
    // this is wrong
    
    int size = end - begin;
    for(int i = 0; i < size; ++i)
    {
        for(int j = i; j > 0; j--)
        {
            int curr = begin + j;
            if(array[curr].compare(array[curr - 1]) > 0)
                break;
            
            std::swap(array[curr], array[curr - 1]);
        }
    }
}

void quicksortPartition(std::vector<std::string> &array, int begin, int end, int index)
{
    if(end <= begin)
        return;
    
    /*
    if(end - begin <= 5)
    {
        insertionSortPartition(array, begin, end, index);
        return;
    }
    */
    
    int pivotKey = charAt(array[begin], index);
    
    int lessThan = begin;
    int greaterThan = end;
    int current = begin + 1;
    
    while(current <= greaterThan)
    {
        int currentKey = charAt(array[current], index);
        
        if(currentKey < pivotKey)
            std::swap(array[current++], array[lessThan++]);
        else if(currentKey > pivotKey)
            std::swap(array[current], array[greaterThan--]);
        else
            ++current;
    }
    
    quicksortPartition(array, begin, lessThan - 1, index);
    quicksortPartition(array, greaterThan + 1, end, index);
    if(pivotKey > -1)
        quicksortPartition(array, lessThan, greaterThan, ++index);
}

void quicksort(std::vector<std::string> &array)
{
    quicksortPartition(array, 0, (int)array.size() - 1, 0);
}