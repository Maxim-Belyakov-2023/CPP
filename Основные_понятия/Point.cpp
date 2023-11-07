#include "Point.h"

// Правила оформления файла cpp, содержащего опрееление методов класса
// тип_результата класс::метод_класса(параметры...) {...}

Point::Point(int x, int y) : x(x), y(y)
{
    // this - обращение к полям или метожам текущего класса (ссылка на текущий класс)
    /*
    this->x = x;
    this->y = y;
    */
}

Point::Point() : x(0), y(0)
{
}

double Point::GetDistance(const Point p)
{
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}