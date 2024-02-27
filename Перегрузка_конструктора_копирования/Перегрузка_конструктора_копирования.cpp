#include <iostream>

#include "Matrix.h"

int main(int argc, char* argv[])
{
    Matrix matrix1(2, 3);
    matrix1.RandomGenerate();
    std::cout << matrix1 << "\n\n";
    Matrix matrix2 = Matrix(matrix1);
    matrix1[0][0] = 150;
    std::cout << matrix2 << "\n\n";
    return 0;
}
