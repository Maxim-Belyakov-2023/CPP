#include <iostream>
#include <stdexcept>

#include "incorrect_dimension_error.h"
#include "Matrix.h"
#include "out_of_range_error.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RU");
    try
    {
        Matrix matrix(2,2);
        int a = matrix[3][3];
    }
    catch(out_of_range_error ex)
    {
        std::cout << ex.what() << std::endl;
    }
    try
    {
        Matrix matrix(2,3);
        Matrix matrix1(2,2);
        Matrix matrix3(10,10);
        matrix + matrix1;
    }
    catch(incorrect_dimension_error ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
    
}
