#include <iomanip>
#include <iostream>
#include <ctime>

#include "Matrix.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Matrix matrix1(2);
    Matrix matrix2(2);
    matrix1.RandomGenerate();
    matrix2.RandomGenerate();
    std::cout << matrix1 << "\n\n";
    std::cout << matrix2 << "\n\n";
    std::cout << matrix1 + matrix2 << "\n\n";
    matrix1++;
    std::cout << matrix1 << "\n\n";
    if (matrix1 != matrix2)
        std::cout << "Not Same\n\n";
    std::cout << "Det = " << static_cast<double>(matrix1) << "\n";

    Matrix matrix3 = matrix1;
    std::cout << matrix3;
    return 0;
}
