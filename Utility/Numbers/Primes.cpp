//
//  Primes.cpp
//  ProjectEuler
//

#include "Primes.h"
#include "Common.h"

Primes::Primes(int upTo)
: upTo(upTo)
{
    int size = upTo / 2 + 1;
    bool *sieve = new bool[size];
    generateSieve(sieve, size);
    
    int count = 1;
    for(int i = 0; i < size; ++i)
    {
        if(sieve[i])
            ++count;
    }
    
    primes.resize(count);
    hash.reserve(count);
    primes[0] = 2;
    hash.insert(2);
    
    int index = 1;
    for(int i = 0; i < size; ++i)
    {
        if(sieve[i])
        {
            int prime = i * 2 + 1;
            primes[index++] = prime;
            hash.insert(prime);
        }
    }
    
    delete [] sieve;
}

void Primes::generateSieve(bool *sieve, int size)
{
    memset(sieve, 0XFF, sizeof(bool) * size);
    
    sieve[0] = false;
    
    int limit = (int)sqrt(size);
    
    for(int i = 1; i <= limit; ++i)
    {
        if(!sieve[i])
            continue;
        
        int prime = i * 2 + 1;
        for(int j = i + prime; j < size; j += prime)
            sieve[j] = false;
    }
}

const std::vector<int64_t> &Primes::getPrimes() const
{
    return primes;
}

int64_t Primes::getPrime(int index) const
{
    return primes[index];
}

bool Primes::isPrime(int64_t num) const
{
    return hash.find(num) != hash.end();
}

std::size_t Primes::getCount() const
{
    return primes.size();
}

std::map<int64_t, int> Primes::getPrimeFactors(int64_t num, int limit) const
{
    std::map<int64_t, int> output;
    if(num < 2)
        return output;
    
    int64_t curr = num;
    int lastPrimeIndex = 0;
    while(curr)
    {
        if(isPrime(curr))
        {
            auto result = output.insert(std::make_pair(curr, 0));
            ++result.first->second;
            break;
        }
        
        auto existing = primeFactors.find(curr);
        if(existing != primeFactors.end())
        {
            for(auto &i : existing->second)
            {
                auto result = output.insert(std::make_pair(i.first, i.second));
                if(!result.second)
                    result.first->second += i.second;
            }
            break;
        }
        
        int maxPrime = (int)sqrt(curr) + 1;
        for(int i = lastPrimeIndex; i < maxPrime; ++i)
        {
            if(curr % primes[i] == 0)
            {
                auto result = output.insert(std::make_pair(primes[i], 0));
                ++result.first->second;
                curr /= primes[i];
                lastPrimeIndex = i;
                break;
            }
        }
        
        if(limit > 0 && output.size() > limit)
            break;
    }
    
    primeFactors.insert(std::make_pair(num, output));
    return output;
}

bool Primes::check(int64_t num)
{
    if(!isOdd(num))
        return false;
    
    int64_t limit = (int)sqrt(num) + 1;
    for(int i = 3; i < limit; i += 2)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;
}