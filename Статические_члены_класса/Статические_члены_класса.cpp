#include <iostream>
#include "Point.h"

int main(int argc, char* argv[])
{
    Point p(5, 89);
    Point* p1 = new Point(4, 32);

    // Статические методы вызываются не из экземпляра класса, а из самого класса через ::
    std::cout << Point::GetDistance(*p1, p);
    std::cout << "\n" << "Count: " << Point::GetCountOfInstance() << std::endl;
    return 0;
}