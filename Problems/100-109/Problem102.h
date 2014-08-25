//
//  Problem102.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Problem102__
#define __ProjectEuler__Problem102__

#include "Problem.h"
#include "Point2D.h"

class Problem102 : public Problem
{
    std::vector<Point2D<int>> points;
    
    bool containsOrigin(const Point2D<int> a, const Point2D<int> b, const Point2D<int> c) const;
    bool sameSide(const Point2D<int> p1, const Point2D<int> p2, const Point2D<int> a, const Point2D<int> b) const;
    
public:
    Problem102();
    
    int64_t solve();
};

#endif /* defined(__ProjectEuler__Problem102__) */
