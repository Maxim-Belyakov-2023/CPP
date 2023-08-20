/**
 *  Аргументы по умолчанию
 *  
 *  Можно сделать так, что некоторые аргументы станут необязательными.
 *  Для этого можно во время объявления функции задать им какие-то значения.
 *  Важно! Необязательные параметры должны идти после обязательных. Перемешивать их невозможно.
 */

#include <cmath>
#include <iostream>

double distance(int x1, int y1, int x2 = 0, int y2 = 0)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(int argc, char* argv[])
{
    std::cout << distance(5, 4) << std::endl;
    std::cout << distance(5, 4, 8, 1) << std::endl;
    return 0;
}
