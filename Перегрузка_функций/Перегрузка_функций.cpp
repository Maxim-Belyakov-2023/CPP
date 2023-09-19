/**
 *  Перегрузка функций
 *  Если функция делает какое-то одинаковое по смыслу действие, но аргументы могут отличаться,
 *  значит имя функции логично должно быть одинковое, а параметры отчаться.
 *
 *  Компилятор сам решает какую из перегрузок вызывать, в зависимости от параметров.
 */

/**
 * TODO: Написать функции нахождения площади треугольника различными способами.
 */

#include <cmath>
#include <iostream>

/**
 * \brief Расстояние между точками на плоскости.
 */
double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/**
 * \brief Расстояние между точками в пространстве.
 */
double distance(int x1, int y1, int z1, int x2, int y2, int z2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main(int argc, char* argv[])
{
    std::cout << distance(1, 2, 3, 4, 5, 6) << std::endl;
    std::cout << distance(1, 2, 3, 4) << std::endl;
    return 0;
}
