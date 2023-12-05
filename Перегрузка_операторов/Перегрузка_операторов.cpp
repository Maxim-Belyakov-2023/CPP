#include <iomanip>
#include <iostream>

#include "Matrix.h"

int main(int argc, char* argv[])
{
    Matrix* matrix1 = new Matrix(5);
    Matrix* matrix2 = new Matrix(5);
    matrix1->RandomGenerate();
    matrix2->RandomGenerate();
    std::cout << matrix1 << std::endl;
    std::cout << matrix2 << std::endl;
    std::cout << (matrix1 + matrix2) << std::endl;

    return 0;
}
