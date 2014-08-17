//
//  Hand.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Hand__
#define __ProjectEuler__Hand__

#include <iostream>

class Hand
{
    enum Rank
    {
        HighCard,
        OnePair,
        TwoPairs,
        ThreeOfAKind,
        Straight,
        Flush,
        FullHouse,
        FourOfAKind,
        StraightFlush,
        RoyalFlush,
    };
    
    char suits[4];
    char values[15];
    
    Rank rank;
    
    void deterimeRank();
    void evalutateCard(const char *str);
    
public:
    Hand();
};

#endif /* defined(__ProjectEuler__Hand__) */
