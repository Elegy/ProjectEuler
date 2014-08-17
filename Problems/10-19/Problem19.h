//
//  Problem19.h
//  ProjectEuler
//
//  Created by Nathan Smith on 8/17/14.
//  Copyright (c) 2014 Elegy Game. All rights reserved.
//

#ifndef __ProjectEuler__Problem19__
#define __ProjectEuler__Problem19__

#include "Problem.h"

class Problem19 : public Problem
{
    enum DayOfWeek
    {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        DayOfWeekCount,
    };
    
    enum Month
    {
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
        MonthCount,
    };
    
    struct Date
    {
        DayOfWeek dayOfWeek;
        Month month;
        uint16_t year;
    };
    
    Date firstDayOfNextMonth(const Date &current);
    
public:
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem19__) */
