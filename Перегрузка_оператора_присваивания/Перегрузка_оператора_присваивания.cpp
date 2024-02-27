#include <iostream>

#include "Matrix.h"

int main(int argc, char* argv[])
{
    Matrix matrix1(2, 3);
    matrix1.RandomGenerate();
    std::cout << matrix1 << "\n\n";
    Matrix matrix(2, 3);
    matrix = matrix1;
    matrix1[0][0] = 150;
    std::cout << matrix << "\n\n";
    return 0;
}
