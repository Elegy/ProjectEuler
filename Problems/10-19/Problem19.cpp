//
//  Problem19.cpp
//  ProjectEuler
//
//  Created by Nathan Smith on 8/17/14.
//  Copyright (c) 2014 Elegy Game. All rights reserved.
//

#include "Problem19.h"

bool isLeapYear(uint16_t year)
{
    if(year % 4 != 0)
        return false;
    
    if(year % 100 == 0 && year % 400 != 0)
        return false;
    
    return true;
}

Problem19::Date Problem19::firstDayOfNextMonth(const Date &current)
{
    Date next;
    next.month = (Month)((current.month + 1) % MonthCount);
    next.year = (next.month == January) ? current.year + 1 : current.year;
    
    uint8_t daysThisMonth = 0;
    switch(current.month)
    {
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            daysThisMonth = 31;
            break;
            
        case April:
        case June:
        case September:
        case November:
            daysThisMonth = 30;
            break;
            
        case February:
            daysThisMonth = isLeapYear(current.year) ? 29 : 28;
            break;
            
        default:
            break;
    }
    
    next.dayOfWeek = (DayOfWeek)((current.dayOfWeek + daysThisMonth % 7) % DayOfWeekCount);
    return next;
}

int64_t Problem19::solve()
{
    int result = 0;
    
    Date current;
    current.month = January;
    current.year = 1900;
    current.dayOfWeek = Monday;
    
    while(current.year < 1901)
        current = firstDayOfNextMonth(current);
    
    while(current.year < 2001)
    {
        if(current.dayOfWeek == Sunday)
            ++result;
        
        current = firstDayOfNextMonth(current);
    }
    
    return result;
}