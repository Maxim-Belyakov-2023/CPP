#pragma once
#include <cmath>

class Point
{
// Модификаторы доступа
private:
    int x;
    int y;
public:
    // Конструктор с параметрами
    Point(int x, int y);
    // Конструктор по умолчанию
    Point();

    // Метод класса
    double GetDistance(const Point p);
};
