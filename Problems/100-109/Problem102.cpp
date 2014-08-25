//
//  Problem102.cpp
//  ProjectEuler
//

#include "Problem102.h"
#include "Vector2D.h"

Problem102::Problem102()
{
    std::ifstream input("p102_triangles.txt");
    if(!input.is_open())
    {
        std::cout << "Error opening input file!\n";
        return;
    }
    
    std::vector<int> rawInput;
    std::string line;
    while(std::getline(input, line))
    {
        std::size_t pos = 0;
        while(pos < line.size())
        {
            line = line.substr(pos);
            rawInput.push_back(std::stoi(line, &pos));
            ++pos; // comma-delimiter
        }
    }
    
    input.close();
    
    for(int i = 0; i < rawInput.size() - 1; i += 2)
        points.push_back(Point2D<int>(rawInput[i], rawInput[i + 1]));
}

bool Problem102::sameSide(const Point2D<int> p1, const Point2D<int> p2, const Point2D<int> a, const Point2D<int> b) const
{
    Vector2D<int> line(a, b);
    int64_t cross1 = line.cross(Vector2D<int>(a, p1));
    int64_t cross2 = line.cross(Vector2D<int>(a, p2));
    
    return (cross1 * cross2 >= 0);
}

int64_t Problem102::solve()
{
    int result = 0;
    
    static const Point2D<int> origin = Point2D<int>(0, 0);
    
    for(int i = 0; i < points.size() - 1; i += 3)
    {
        if(sameSide(origin, points[i + 2], points[i], points[i + 1]) &&
           sameSide(origin, points[i], points[i + 1], points[i + 2]) &&
           sameSide(origin, points[i + 1], points[i], points[i + 2]))
            ++result;
    }
    
    return result;
}