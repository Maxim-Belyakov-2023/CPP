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
        Matrix matrix3(2,2);
        //int a = matrix3[3][3];
        Matrix matrix(2,3);
        Matrix matrix1(2,2);
        matrix + matrix1;
    }
    catch(out_of_range_error& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(incorrect_dimension_error& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
    
}
