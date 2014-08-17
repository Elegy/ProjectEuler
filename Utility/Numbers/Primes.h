//
//  Primes.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Primes__
#define __ProjectEuler__Primes__

#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Primes
{
    std::vector<int64_t> primes;
    std::unordered_set<int64_t> hash;
    mutable std::unordered_map<int64_t, std::map<int64_t, int>> primeFactors;
    
    void generateSieve(bool *sieve, int size);
    
    int upTo;
    
public:
    Primes(int upTo);
    
    const std::vector<int64_t> &getPrimes() const;
    int64_t getPrime(int index) const;
    bool isPrime(int64_t num) const;
    
    std::size_t getCount() const;
    
    std::map<int64_t, int> getPrimeFactors(int64_t num, int limit = -1) const;
    
    static bool check(int64_t num);
};

#endif /* defined(__ProjectEuler__Primes__) */
