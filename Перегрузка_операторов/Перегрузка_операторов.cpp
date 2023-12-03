
#include <iostream>

#include "Matrix.h"

int main(int argc, char* argv[])
{
    Matrix* matrix = new Matrix(10);
    std::cout << matrix;
    return 0;
}
