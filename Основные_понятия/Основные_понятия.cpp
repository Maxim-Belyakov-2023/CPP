#include <iostream>
// Подключение заголовочных файлов проекта
#include "Point.h"

int main(int argc, char* argv[])
{
    Point p(5, 89);
    Point* p1 = new Point(4, 32);

    std::cout << p1->GetDistance(p) << std::endl;
    return 0;
}
