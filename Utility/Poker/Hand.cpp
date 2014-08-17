//
//  Hand.cpp
//  ProjectEuler
//

#include "Hand.h"

Hand::Hand()
{
    memset(suits, 0, sizeof(char) * 4);
    memset(values, 0, sizeof(char) * 15);
}

void Hand::deterimeRank()
{
    bool straight = true;
    int straightHigh = 0;
    bool flush = true;
    int lastSeen = 0;
    int pair1 = 0;
    int pair2 = 0;
    int triplet = 0;
    int quartet = 0;
    for(int i = 2; i < 15; ++i)
    {
        if(values[i])
        {
            if(lastSeen && lastSeen != i - 1)
            {
                if(i != 14 || straightHigh != 4)
                    straight = false;
            }
            else if(straight)
            {
                straightHigh = i;
            }
            
            switch(values[i])
            {
                case 2:
                    if(pair1)
                        pair2 = i;
                    else
                        pair1 = i;
                    break;
                    
                case 3:
                    triplet = i;
                    break;
                    
                case 4:
                    quartet = i;
                    break;
            }
        }
    }
    
    for(int i = 0; i < 4; ++i)
    {
        if(suits[i] && suits[i] != 5)
        {
            flush = false;
            break;
        }
    }
    
    if(pair1)
    {
        if(pair2)
            rank = TwoPairs;
        else if(triplet)
            rank = FullHouse;
        else
            rank = OnePair;
    }
    else if(triplet)
    {
        rank = ThreeOfAKind;
    }
    else if(straight)
    {
        if(flush)
            rank = values[14] ? RoyalFlush : StraightFlush;
        else
            rank = Straight;
    }
    else if(flush)
    {
        rank = Flush;
    }
    else if(quartet)
    {
        rank = FourOfAKind;
    }
    else
    {
        rank = HighCard;
    }
}

void Hand::evalutateCard(const char *str)
{
    int i = 0;
    switch(str[i])
    {
        case '1':
            ++values[10];
            ++i;
            break;
            
        case 'J':
            ++values[11];
            break;
            
        case 'Q':
            ++values[12];
            break;
            
        case 'K':
            ++values[13];
            break;
            
        case 'A':
            ++values[1];
            ++values[14];
            break;
            
        default:
            ++values[str[i] - '0'];
            break;
    }
    ++i;
    
    switch(str[i])
    {
        case 'C':
            ++suits[0];
            break;
            
        case 'D':
            ++suits[1];
            break;
            
        case 'S':
            ++suits[2];
            break;
            
        case 'H':
            ++suits[3];
            break;
    }
}