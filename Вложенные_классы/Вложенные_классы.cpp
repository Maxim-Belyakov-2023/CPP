#include <iomanip>
#include <iostream>
#include <ctime>

#include "Matrix.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    Matrix matrix1(2,3);
    Matrix matrix2(2,5);
    matrix1.RandomGenerate();
    matrix2.RandomGenerate();
    std::cout << matrix1 << '\n';
    std::cout << matrix2 << '\n';
    std::cout << (matrix1,matrix2);
    
    std::cout << matrix1 + matrix2 << '\n';
    std::cout << matrix1 << '\n';
    if (matrix1 != matrix2)
        std::cout << "Not Same\n";
    std::cout << "Det = " <<static_cast<double>(matrix1) << "\n";
    std::cout << matrix1 << '\n';

    matrix1[0][0] = 45;
    //std::cout << matrix1[0][0];
    return 0;
}
