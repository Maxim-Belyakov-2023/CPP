#include "Point.h"


Point::Point(int x, int y) : x(x), y(y)
{
    count++;
}

Point::Point() : x(0), y(0)
{
    count++;
}

double Point::GetDistance(const Point p)
{
    return Point::GetDistance(*this, p);
}

double Point::GetDistance(const Point p1, const Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int Point::GetCountOfInstance()
{
    return count;
}

unsigned Point::count = 0;