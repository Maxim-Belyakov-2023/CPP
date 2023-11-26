#pragma once
#include <cmath>

class Point
{
private:
    int x;
    int y;
    // Статическое поле - переменная инициализируется один раз в глобальной области, это переменная хранит значение общее для всех экземпляров класса.
    static unsigned count;
public:
    Point(int x, int y);
    Point();

    double GetDistance(const Point p);

    // Статический метод - не имеет доступа к переменным класса, но по смыслу принадлежит ему.
    static double GetDistance(const Point p1, const Point p2);

    static int GetCountOfInstance();
};
