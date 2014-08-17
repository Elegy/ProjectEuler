//
//  Common.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Common__
#define __ProjectEuler__Common__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <limits>

bool closeEnough(float a, float b);

int64_t getFactorial(int num);

bool isOdd(int64_t num);

bool isPerfectSquare(uint64_t num);
int countDigits(int64_t num, int base = 10);

bool isPalindrome(std::vector<char> &array);
bool isPalindrome(std::list<char>::const_iterator begin, std::list<char>::const_iterator end);

int alphabeticalValueForCharacter(char c);
int alphabeticalValue(const std::string &str);

std::vector<char> getDigits(int64_t num, int base = 10);
int64_t digitsToNumber(std::vector<char>::const_iterator begin, std::vector<char>::const_iterator end);
int64_t digitsToNumber(std::list<char>::const_iterator begin, std::list<char>::const_iterator end, int count);

bool isPandigital(const std::vector<char> &digits, int lower = 0, int upper = 9);
bool isPandigital(int64_t num, int lower = 0, int upper = 9);

std::vector<std::vector<char>> getPermutations(std::vector<char> &input);

#endif /* defined(__ProjectEuler__Common__) */
